#include <iostream>
#include "Interpreter.h"

Interpreter::Interpreter(int maxStep)  : 
    m_memoryPointer { 0 },
    m_maxStep { maxStep },
    m_programPointer { 0 },
    m_stepCount { 0 },
    m_maxMemoryPointer {0}
{
    m_memory.fill(0);
}

Interpreter::~Interpreter()
{
    std::cout << "\n----END OF PROGRAM----\n";

    if (m_maxStep == m_stepCount)
    {
        std::cout << "Terminated before finish at step " << m_stepCount << '\n';
        std::cout << "Pointer at position " << m_memoryPointer << '\n';
        std::cout << "Output written to state.txt\n";
        outputState();
    }
    else {
        std::cout << "Program completed after step " << m_stepCount << '\n';
    }
}

void Interpreter::outputState()
{
    for (int i=1; i<=m_maxMemoryPointer + 1; ++i)
    {
        m_out << m_memory[i-1] << ' ';
        if (i % 12 == 0) m_out << '\n';
    }
}

void Interpreter::consume(const std::string& program)
{
    while ( m_programPointer < program.size() )
    {
        char a { program[m_programPointer] };
        m_stepCount += 1;

        if (a == '>'){
            m_memoryPointer += 1;
        } else if ( a == '<') {
            m_memoryPointer -= 1;
        } else if ( a == '+') {
            m_memory[m_memoryPointer] += 1;
        } else if ( a == '-') {
            m_memory[m_memoryPointer] -= 1;
        } else if ( a == '.') {
            std::cout << static_cast<char>(m_memory[m_memoryPointer]);
        } else if ( a == ',') {
            char b;
            std::cin >> b;
            m_memory[m_memoryPointer] = b;            
        } else if ( a == '[') {
            if (m_memory[m_memoryPointer] == 0){
                int depth { 1 };
                while ( depth != 0){
                    char c { program[++m_programPointer] };
                    if ( c == '[' ) {
                        depth++;
                    } else if ( c == ']' ) {
                        depth--;
                    }
                } 
            } else {
                m_jump.push_back(m_programPointer);
            }
            
        } else if ( a == ']') {
            if (m_memory[m_memoryPointer] != 0){
                m_programPointer = m_jump.back();
            } else {
                m_jump.pop_back();
            }
        } else {
            m_stepCount -= 1;
        }

        m_programPointer++;
        m_maxMemoryPointer = std::max(m_maxMemoryPointer, m_memoryPointer);
        if (m_stepCount == m_maxStep) return;

    }
}