#include <iostream>
#include <fstream>
#include "Interpreter.h"


int main(int argc, char* argv[])
{

    std::string fileName {argv[1]};
    int maxStep {atoi(argv[2])};
    Interpreter I {maxStep};
    std::ifstream myFile(fileName);
    I.consume(myFile);

    return 0;
}