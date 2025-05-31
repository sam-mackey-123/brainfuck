#include <iostream>
#include <fstream>
#include "Interpreter.h"


int main(int argc, char* argv[])
{
    Interpreter I {};
    if (argc == 2)
    {
        std::string fileName {argv[1]};
        std::ifstream myFile(fileName);
        I.consume(myFile);
    } 
    else
    {
        I.consume(std::cin);
    }
    return 0;
}