#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <array>
#include <vector>
#include <fstream>

class Interpreter
{
    private:
        std::array<int, 30000> m_memory;
        std::vector<std::streampos> m_jump;
        int m_memoryPointer;
        int m_maxMemoryPointer;
        int m_programPointer;
        int m_stepCount;
        int m_maxStep;
        std::ofstream m_out { "state.txt" };
        void outputState();

    public:
        void consume(const std::string& program);
        Interpreter(int maxStep);
        ~Interpreter();

};

#endif