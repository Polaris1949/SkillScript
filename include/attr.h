#ifndef _SKS_ATTR_H
#define _SKS_ATTR_H 1

#include <cstdint>
#include <string>

namespace sks
{

inline namespace __attr_detail
{

using _Attr_value_t = uint8_t;

enum class _Attr_data_t : _Attr_value_t
{
    none, ice, demon, ghost, soil, water,
    stone, common, dragon, fire, poison,
    electric, insect, grass, valiant,
    machine, beauty, wing, light,
    holyfire, holywater, holygrass,
    unknown = static_cast<_Attr_value_t>(-1)
};

}

class attribute
{
public:
    using value_type = _Attr_value_t;
    using data_type = _Attr_data_t;

private:
    value_type _M_main;
    value_type _M_deputy;

public:
    attribute();
    attribute(const value_type& __main, const value_type& __deputy);
    attribute(char __main, char __deputy);

    value_type& main();
    value_type& deputy();

    const value_type& main() const;
    const value_type& deputy() const;

    void assign(const value_type& __main, const value_type& __deputy);
    void assign(const attribute& __attr);
};

_Attr_value_t attr_from(char __ch);
std::string attr_to(const _Attr_value_t& __attr);
std::string attr_to(const attribute& __attr);

}

#endif
