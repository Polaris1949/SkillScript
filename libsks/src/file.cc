#include "file.h"
#include <fstream>
#include <iostream>

namespace sks
{

file::
file(const file_type& __file)
    : _M_file{__file}
{}

skill
file::
operator() (bool __msg) const
{
    std::ifstream __f{this->_M_file};
    skill __sk;

    if (!__f)
    {
        if (__msg)
            std::cerr << "fatal error: bad file\n";

        return __sk;
    }

    std::string __s;
    std::string __w;

    auto extract_word = [&__s, &__w]() -> std::string&
    {
        __w = __s.substr(0, __s.find(' '));
        __s.erase(0, __w.size());
        while (__s.front() == ' ') __s.erase(__s.begin());
        return __w;
    };

    while (std::getline(__f, __s))
    {
        extract_word();

        if (__w == "index")
        {
            __sk.index() = std::stoi(extract_word());

            if (__msg && !__s.empty())
                std::cerr << "warning: ignore content after one index\n";

            continue;
        }

        if (__w == "name")
        {
            __sk.name() = __s;
            continue;
        }

        if (__w == "attr")
        {
            char __a_main = extract_word().front();
            char __a_deputy = extract_word().front();
            __sk.attr() = {attr_from(__a_main), attr_from(__a_deputy)};

            if (__msg && !__s.empty())
                std::cerr << "warning: ignore content after two attributes\n";

            continue;
        }

        if (__w == "desc")
        {
            __sk.desc() = __s;
            continue;
        }

        if (__w == "power")
        {
            __sk.power() = std::stoi(extract_word());

            if (__msg && !__s.empty())
                std::cerr << "warning: ignore content after one power\n";

            continue;
        }

        if (__w == "style")
        {
            __sk.style() = style_from(extract_word().front());

            if (__msg && !__s.empty())
                std::cerr << "warning: ignore content after one type\n";

            continue;
        }

        if (__w == "pp")
        {
            __sk.pp() = std::stoi(extract_word());

            if (__msg && !__s.empty())
                std::cerr << "warning: ignore content after one pp\n";

            continue;
        }

        if (__w == "speed")
        {
            __sk.speed() = std::stoi(extract_word());

            if (__msg && !__s.empty())
                std::cerr << "warning: ignore content after one speed\n";

            continue;
        }

        if (__w == "offen")
        {
            char __o_order = extract_word().front();
            size_t __o_number = std::stoi(extract_word());
            __sk.offen() = offen_from(__o_order, __o_number);

            if (__msg && !__s.empty())
                std::cerr << "warning: ignore content after two offenses\n";

            continue;
        }
    }

    return __sk;
}

}
