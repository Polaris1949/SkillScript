#ifndef _SKS_OFFEN_H
#define _SKS_OFFEN_H 1

#include <cstdint>
#include <string>

namespace sks
{

inline namespace __offen_detail
{

using _Offen_value_t = uint8_t;

struct _Offen_data_t
{
    unsigned _M_order : 2;
    signed _M_number : 6;

    using _Order_t = decltype(_M_order);
    using _Number_t = decltype(_M_number);

    _Offen_data_t();
    _Offen_data_t(_Order_t __order, _Number_t __number);
};

using _Offen_order_t = _Offen_data_t::_Order_t;
using _Offen_number_t = _Offen_data_t::_Number_t;

enum class _Offen_order_data_t : _Offen_order_t
{
    none, first, last,
    unknown = static_cast<_Offen_order_t>(-1)
};

union _Offen_storage_t
{
    _Offen_value_t _M_value;
    _Offen_data_t _M_data;

    _Offen_storage_t();
    _Offen_storage_t(_Offen_value_t __value);
    _Offen_storage_t(_Offen_order_t __order, _Offen_number_t __number);
};

}

class offense
{
public:
    using value_type = _Offen_value_t;
    using data_type = _Offen_data_t;
    using storage_type = _Offen_storage_t;
    using order_type = _Offen_order_t;
    using number_type = _Offen_number_t;

private:
    storage_type _M_storage;

public:
    offense();
    offense(const value_type& __value);
    offense(const order_type& __order, const number_type& __number);

    order_type order() const;
    number_type number() const;

    value_type& value();
    const value_type& value() const;

    void assign(const value_type& __value);
    void assign(const order_type& __order, const number_type& __number);
    void assign(const offense& __offen);
};

_Offen_order_t offen_order_from(char __ch);
std::string offen_order_to(const _Offen_order_t& __order);
_Offen_value_t offen_from(char __ch, _Offen_number_t __num);
std::string offen_to(const _Offen_value_t& __offen);
std::string offen_to(const offense& __offen);

}

#endif
