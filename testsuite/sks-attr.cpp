#include "attr.h"
#include <iostream>

int main()
{
    sks::attribute a{'a', 'l'};
    std::cout << sks::attr_to(a) << '\n';
    std::cout << sks::attr_to(sks::attr_from('b')) << '\n';
}
