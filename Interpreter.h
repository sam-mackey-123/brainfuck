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
        int m_pointer;
        int m_stepCount;
        int m_maxStep;
        int m_maxPointer;
        std::ofstream m_out { "state.txt" };
        void outputState();

    public:
        void consume(std::istream& stream);
        Interpreter(int maxStep);
        ~Interpreter();

};

#endif