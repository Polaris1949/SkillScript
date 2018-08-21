#include "attr.h"
#include <iostream>

int main()
{
    sks::attribute a{'a', 'b'};
    std::cout << sks::attr_to(a) << '\n';
}
