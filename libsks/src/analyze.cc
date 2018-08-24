#include "analyze.h"
#include <iostream>

namespace sks
{

bool analyze(const skill& __sk)
{
    if (__sk.empty())
        return false;

    std::cout << "Index: " << __sk.index() << '\n';
    std::cout << "Name: " << __sk.name() << '\n';
    std::cout << "Attribute: " << attr_to(__sk.attr()) << '\n';
    std::cout << "Description: " << __sk.desc() << '\n';
    std::cout << "Power: " << size_t{__sk.power()} << '\n';
    std::cout << "Style: " << style_to(__sk.style()) << '\n';
    std::cout << "PP: " << size_t{__sk.pp()} << '\n';
    std::cout << "Speed: " << size_t{__sk.speed()} << '\n';
    std::cout << "Offense: " << offen_to(__sk.offen()) << '\n';
    return true;
}

}
