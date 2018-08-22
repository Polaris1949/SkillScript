#ifndef _SKS_MAIN_H
#define _SKS_MAIN_H 1

#include <iostream>
#include "version.h"

namespace sks
{

void help_msg()
{
    std::cerr <<
        "Usage: sks [FILE]...\n"
        "  or:  sks OPTION\n"
        "Analyze a skill script and output its information.\n"
        "\n      --help     display this help and exit"
        "\n      --version  ouput version information and exit"
        << std::endl;
}

void version_msg()
{
    std::cerr <<
        "sks (Polaris utils) " SKS_VERSION "\n"
        "Copyright (C) 2018 Free Software Foundation, Inc.\n"
        "License GPLv3+: GNU GPL version 3 or later "
        "<http://gnu.org/licenses/gpl.html>.\n"
        "This is free software: you are free to change and redistribute it.\n"
        "There is NO WARRANTY, to the extent permitted by law.\n\n"
        "Written by Polaris Zhao."
        << std::endl;
}

}

#endif
