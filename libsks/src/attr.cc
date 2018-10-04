#include "attr.h"

namespace sks
{

#define SKS_ATTR_DATA_USING(D) static_cast<_Attr_value_t>(_Attr_data_t::D)
#define SKS_ADU(X) SKS_ATTR_DATA_USING(X)

attribute::
attribute()
    : _M_main{SKS_ADU(none)}, _M_deputy{SKS_ADU(none)}
{}

attribute::
attribute(const value_type& __main, const value_type& __deputy)
    : _M_main{__main}, _M_deputy{__deputy}
{}

attribute::
attribute(char __main, char __deputy)
    : _M_main{attr_from(__main)}, _M_deputy{attr_from(__deputy)}
{}

_Attr_value_t&
attribute::
main()
{ return this->_M_main; }

_Attr_value_t&
attribute::
deputy()
{ return this->_M_deputy; }

const _Attr_value_t&
attribute::
main() const
{ return this->_M_main; }

const _Attr_value_t&
attribute::
deputy() const
{ return this->_M_deputy; }

void
attribute::
assign(const value_type& __main, const value_type& __deputy)
{
    this->_M_main = __main;
    this->_M_deputy = __deputy;
}

void
attribute::
assign(const attribute& __attr)
{
    this->_M_main = __attr._M_main;
    this->_M_deputy = __attr._M_deputy;
}

_Attr_value_t
attr_from(char __ch)
{
    switch (__ch)
    {
        case '\0': return SKS_ADU(none);
        case 'a': case 'r': return SKS_ADU(dragon);
        case 'b': case 'u': return SKS_ADU(beauty);
        case 'c': return SKS_ADU(common);
        case 'd': return SKS_ADU(demon);
        case 'e': return SKS_ADU(electric);
        case 'f': return SKS_ADU(fire);
        case 'g': return SKS_ADU(grass);
        case 'h': return SKS_ADU(ghost);
        case 'i': return SKS_ADU(ice);
        case 'j': case 'x': return SKS_ADU(holyfire);
        case 'k': case 'y': return SKS_ADU(holywater);
        case 'l': return SKS_ADU(light);
        case 'm': return SKS_ADU(machine);
        case 'n': return SKS_ADU(wing);
        case 'o': return SKS_ADU(soil);
        case 'p': return SKS_ADU(poison);
        case 'q': case 'z': return SKS_ADU(holygrass);
        case 's': return SKS_ADU(insect);
        case 't': return SKS_ADU(stone);
        case 'v': return SKS_ADU(valiant);
        case 'w': return SKS_ADU(water);
        default: return SKS_ADU(unknown);
    }
}

std::string
attr_to(const _Attr_value_t& __attr)
{
    switch (__attr)
    {
        case SKS_ADU(none): return "none";
        case SKS_ADU(dragon): return "dragon";
        case SKS_ADU(beauty): return "beauty";
        case SKS_ADU(common): return "common";
        case SKS_ADU(demon): return "demon";
        case SKS_ADU(electric): return "electric";
        case SKS_ADU(fire): return "fire";
        case SKS_ADU(grass): return "grass";
        case SKS_ADU(ghost): return "ghost";
        case SKS_ADU(ice): return "ice";
        case SKS_ADU(holyfire): return "holyfire";
        case SKS_ADU(holywater): return "holywater";
        case SKS_ADU(light): return "light";
        case SKS_ADU(machine): return "machine";
        case SKS_ADU(wing): return "wing";
        case SKS_ADU(soil): return "soil";
        case SKS_ADU(poison): return "poison";
        case SKS_ADU(holygrass): return "holygrass";
        case SKS_ADU(insect): return "insect";
        case SKS_ADU(stone): return "stone";
        case SKS_ADU(valiant): return "valiant";
        case SKS_ADU(water): return "water";
        default: return "unknown";
    }
}

std::string
attr_to(const attribute& __attr)
{
    std::string __res{attr_to(__attr.main())};
    if (__attr.deputy() != SKS_ADU(none))
    {
        __res += " + ";
        __res += attr_to(__attr.deputy());
    }
    return __res;
}

#undef SKS_ADU
#undef SKS_ATTR_DATA_USING

}
