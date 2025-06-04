#include <iostream>
#include "Interpreter.h"

Interpreter::Interpreter(int maxStep)  : 
    m_pointer {0},
    m_maxStep { maxStep },
    m_stepCount {0},
    m_maxPointer {0}
{
    m_memory.fill(0);
}

Interpreter::~Interpreter()
{
    std::cout << "\n----END OF PROGRAM----\n";

    if (m_maxStep == m_stepCount)
    {
        std::cout << "Terminated before finish at step " << m_stepCount << '\n';
        std::cout << "Pointer at position " << m_pointer << '\n';
        std::cout << "Output written to state.txt\n";
        outputState();
    }
    else {
        std::cout << "Program completed after step " << m_stepCount << '\n';
    }
}

void Interpreter::outputState()
{
    for (int i=1; i<=m_maxPointer + 1; ++i)
    {
        m_out << m_memory[i-1] << ' ';
        if (i % 12 == 0) m_out << '\n';
    }
}

void Interpreter::consume(std::istream& stream)
{
    while ( stream )
    {
        char a { stream.get() };
        int x { stream.tellg() };
        m_stepCount += 1;

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
        } else {
            m_stepCount -= 1;
        }

        m_maxPointer = std::max(m_maxPointer, m_pointer);
        if (m_stepCount == m_maxStep) return;

    }
}