#include <iostream>
#include <fstream>
#include "Interpreter.h"


int main(int argc, char* argv[])
{

    std::string fileName {argv[1]};
    std::ifstream file(fileName);
    std::string program { std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() };

    int maxStep {atoi(argv[2])};
    Interpreter I {maxStep};
    I.consume(program);

    return 0;
}