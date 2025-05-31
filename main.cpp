#include <iostream>
#include <fstream>

void printStream(std::istream& stream)
{
    while ( stream )
    {
        char a { stream.get() };
        std::cout << a;
    }
}

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        std::string fileName {argv[1]};
        std::ifstream myFile(fileName);
        printStream(myFile);
    } 
    else
    {
        printStream(std::cin);
    }
    return 0;
}