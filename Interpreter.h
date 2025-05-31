#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <array>
#include <vector>

class Interpreter
{
    private:
        std::array<char, 30000> m_memory;
        std::vector<std::streampos> m_jump;
        int m_pointer;

    public:
        void consume(std::istream& stream);
        Interpreter();

};

#endif