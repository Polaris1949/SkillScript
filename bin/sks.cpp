// Skill Script Viewer

#include <iostream>
#include <fstream>
#include <string>

struct skill_script
{
    std::size_t index{};
    std::string name{};
    std::size_t attr{};
    std::string desc{};
    std::size_t power{};

    void print() const;
};

std::size_t attr_main(std::size_t attr)
{
    return attr & 0xffff;
}

std::size_t attr_deputy(std::size_t attr)
{
    return attr >> 16;
}

std::size_t make_attr(std::size_t main, std::size_t deputy)
{
    return main | (deputy << 16);
}

enum attr_value : std::size_t
{
    none, ice, demon, ghost, soil, water,
    stone, common, dragon, fire, poison,
    electric, insect, grass, valiant,
    machine, beauty, wing, light,
    holyfire, holywater, holygrass,
    unknown = static_cast<std::size_t>(-1)
};

std::size_t attr_char(char c)
{
    switch (c)
    {
        case '\0': return none;
        case 'a': case 'r': return dragon;
        case 'b': case 'u': return beauty;
        case 'c': return common;
        case 'd': return demon;
        case 'e': return electric;
        case 'f': return fire;
        case 'g': return grass;
        case 'h': return ghost;
        case 'i': return ice;
        case 'j': case 'x': return holyfire;
        case 'k': case 'y': return holywater;
        case 'l': return light;
        case 'm': return machine;
        case 'n': return wing;
        case 'o': return soil;
        case 'p': return poison;
        case 'q': case 'z': return holygrass;
        case 's': return insect;
        case 't': return stone;
        case 'v': return valiant;
        case 'w': return water;
        default: return unknown;
    }
}

std::string attr_name(std::size_t a)
{
    switch (a)
    {
        case none: return "none";
        case dragon: return "dragon";
        case beauty: return "beauty";
        case common: return "common";
        case demon: return "demon";
        case electric: return "electric";
        case fire: return "fire";
        case grass: return "grass";
        case ghost: return "ghost";
        case ice: return "ice";
        case holyfire: return "holyfire";
        case holywater: return "holywater";
        case light: return "light";
        case machine: return "machine";
        case wing: return "wing";
        case soil: return "soil";
        case poison: return "poison";
        case holygrass: return "holygrass";
        case insect: return "insect";
        case stone: return "stone";
        case valiant: return "valiant";
        case water: return "water";
        default: return "unknown";
    }
}

void skill_script::print() const
{
    std::cout << "Index: " << index << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Attribute: " << attr_name(attr_main(attr));
    if (attr_deputy(attr))
        std::cout << " + " << attr_name(attr_deputy(attr));
    std::cout << '\n';
    std::cout << "Description: " << desc << '\n';
    std::cout << "Power: " << power << '\n';
}

void help()
{
    std::cout <<
        "Usage: sks [FILE]...\n"
        "   or: sks OPTION\n"
        "Analyze a skill script and output user-friendly information.\n"
        "\n      --help     display this help and exit"
        "\n      --version  ouput version information and exit"
        << std::endl;
}

void version()
{
    std::cout <<
        "sks (Polaris utils) 1.0\n"
        "Packaged by Cygwin (1.0-1)\n"
        "Copyright (C) 2016 Free Software Foundation, Inc.\n"
        "License GPLv3+: GNU GPL version 3 or later "
        "<http://gnu.org/licenses/gpl.html>.\n"
        "This is free software: you are free to change and redistribute it.\n"
        "There is NO WARRANTY, to the extent permitted by law.\n\n"
        "Written by Polaris Zhao."
        << std::endl;
}

int main(int argc, const char* argv[])
{
    if (argc < 2)
    {
        help();
        return 0;
    }

    if (argc > 2)
    {
        std::cout << "Bad usage. Try sks --help for more information."
                  << std::endl;
        return 1;
    }

    if (std::string(argv[1]) == "--help")
    {
        help();
        return 0;
    }

    if (std::string(argv[1]) == "--version")
    {
        version();
        return 0;
    }

    std::ifstream fin(argv[1]);
    std::string s, w;
    skill_script sks;

    auto extract_word = [&s, &w]()
    {
        w = s.substr(0, s.find(' '));
        s.erase(0, w.size());
        while (s.front() == ' ') s.erase(s.begin());
        return !w.empty();
    };

    while (getline(fin, s))
    {
        extract_word();

        if (w == "index")
        {
            extract_word();
            sks.index = std::stoi(w);

            if (!s.empty())
                std::cout << "Warning: ignore content after one index"
                    << std::endl;

            continue;
        }

        if (w == "name")
        {
            sks.name = s;
            continue;
        }

        if (w == "attr")
        {
            extract_word();
            std::size_t a_main = attr_char(w.front());
            extract_word();
            std::size_t a_deputy = attr_char(w.front());
            sks.attr = make_attr(a_main, a_deputy);

            if (!s.empty())
                std::cout << "Warning: ignore content after two attributes"
                    << std::endl;

            continue;
        }

        if (w == "desc")
        {
            sks.desc = s;
            continue;
        }

        if (w == "power")
        {
            extract_word();
            sks.power = std::stoi(w);

            if (!s.empty())
                std::cout << "Warning: ignore content after one power"
                    << std::endl;

            continue;
        }
    }

    sks.print();
    std::cout << "Successfully analyzed." << std::endl;
    return 0;
}
