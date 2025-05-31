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
            m_jump.push_back(stream.tellg());
            if (m_memory[m_pointer] == 0){
                int depth { 1 };
                char c;
                while ( stream.get(c) && depth != 0){
                    if ( c == '[' ) depth++;
                    else if ( c == ']' ) depth--;
                } 
            }
            
        } else if ( a == ']') {
            std::streampos p {m_jump.back() - 1};
            m_jump.pop_back();
            if (m_memory[m_pointer] != 0){
                stream.seekg(p);
            }
        }

    }
}