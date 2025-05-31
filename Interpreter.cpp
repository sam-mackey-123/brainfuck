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
            std::cout << m_memory[m_pointer];
        } else if ( a == ',') {
            char b;
            std::cin >> b;
            m_memory[m_pointer] = b;            
        } else if ( a == '[') {
            m_jump.push_back(stream.tellg());
            if (m_memory[m_pointer] == 0){
                while ( stream.get() != ']'); 
            }
            
        } else if ( a == ']') {
            if (m_memory[m_pointer] != 0){
                stream.seekg(m_jump.back());
                m_jump.pop_back();
            }
        }

    }
}