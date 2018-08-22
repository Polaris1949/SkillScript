#ifndef _SKS_STYLE_H
#define _SKS_STYLE_H 1

#include <cstdint>
#include <string>

namespace sks
{

inline namespace __style_detail
{

using _Style_value_t = uint8_t;

enum class _Style_data_t : _Style_value_t
{
    none, physics, magic, variety,
    unknown = static_cast<_Style_value_t>(-1)
};

}

class style
{
public:
    using value_type = _Style_value_t;
    using data_type = _Style_data_t;

private:
    value_type _M_style;

public:
    style();
    style(const value_type& __style);
    style(char __ch);

    value_type& data();
    const value_type& data() const;

    void assign(const value_type& __style);
    void assign(const style& __style);
};

_Style_value_t style_from(char __ch);
std::string style_to(const _Style_value_t& __style);
std::string style_to(const style& __style);

}

#endif
