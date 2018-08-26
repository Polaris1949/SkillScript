#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "main.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        sks::help_msg();
        return 0;
    }

    if (argc > 2)
    {
        std::cerr << "Bad usage. Try sks --help for more information.\n";
        return 1;
    }

    if (std::string(argv[1]) == "--help")
    {
        sks::help_msg();
        return 0;
    }

    if (std::string(argv[1]) == "--version")
    {
        sks::version_msg();
        return 0;
    }

    if (sks::analyze(sks::file{argv[1]}()))
        std::cerr << "Successfully analyzed.\n";
    return 0;
}
