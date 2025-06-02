#include <iostream>
#include "Interpreter.h"

Interpreter::Interpreter()  : m_pointer {0}
{
    m_memory.fill(0);
}

void Interpreter::consume(std::istream& stream)
{
    while ( stream )
    {
        char a { stream.get() };
        int x { stream.tellg() };

        // if (a != '\n') std::cout << m_pointer << ' ' << x << ' ' << a << '\n';
        if (a == '>'){
            m_pointer += 1;
        } else if ( a == '<') {
            m_pointer -= 1;
        } else if ( a == '+') {
            m_memory[m_pointer] += 1;
        } else if ( a == '-') {
            m_memory[m_pointer] -= 1;
        } else if ( a == '.') {
            std::cout << static_cast<char>(m_memory[m_pointer]);
        } else if ( a == ',') {
            char b;
            std::cin >> b;
            m_memory[m_pointer] = b;            
        } else if ( a == '[') {
            if (m_memory[m_pointer] == 0){
                int depth { 1 };
                char c;
                while ( depth != 0 && stream.get(c)){
                    if ( c == '[' ) {
                        depth++;
                    } else if ( c == ']' ) {
                        depth--;
                    }
                } 
            } else {
                m_jump.push_back(stream.tellg());
            }
            
        } else if ( a == ']') {
            if (m_memory[m_pointer] != 0){
                stream.seekg(m_jump.back());
            } else {
                m_jump.pop_back();
            }
        }

    }
}