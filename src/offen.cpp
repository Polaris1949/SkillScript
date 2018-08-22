#include "offen.h"

namespace sks
{

namespace __offen_detail
{

_Offen_data_t::
_Offen_data_t()
    : _M_order{}, _M_number{}
{}

_Offen_data_t::
_Offen_data_t(_Order_t __order, _Number_t __number)
    : _M_order{__order}, _M_number{__number}
{}

_Offen_storage_t::
_Offen_storage_t()
    : _M_value{}
{}

_Offen_storage_t::
_Offen_storage_t(_Offen_value_t __value)
    : _M_value{__value}
{}

_Offen_storage_t::
_Offen_storage_t(_Offen_order_t __order, _Offen_number_t __number)
    : _M_data{__order, __number}
{}

}

#define SKS_OFFEN_ORDER_DATA_USING(D) \
    static_cast<_Offen_order_t>(_Offen_order_data_t::D)
#define SKS_OODU(X) SKS_OFFEN_ORDER_DATA_USING(X)

offense::
offense()
    : _M_storage{}
{}

offense::
offense(const value_type& __value)
    : _M_storage{__value}
{}

offense::
offense(const order_type& __order, const number_type& __number)
    : _M_storage{__order, __number}
{}

_Offen_order_t
offense::
order() const
{ return this->_M_storage._M_data._M_order; }

_Offen_number_t
offense::
number() const
{ return this->_M_storage._M_data._M_number; }

_Offen_value_t&
offense::
value()
{ return this->_M_storage._M_value; }

const _Offen_value_t&
offense::
value() const
{ return this->_M_storage._M_value; }

void
offense::
assign(const value_type& __value)
{ this->_M_storage._M_value = __value; }

void
offense::
assign(const order_type& __order, const number_type& __number)
{
    this->_M_storage._M_data._M_order = __order;
    this->_M_storage._M_data._M_number = __number;
}

void
offense::
assign(const offense& __offen)
{ this->_M_storage = __offen._M_storage; }

_Offen_order_t
offen_order_from(char __ch)
{
    switch (__ch)
    {
        case '\0': return SKS_OODU(none);
        case 'a': case 'f': return SKS_OODU(first);
        case 'b': case 'l': return SKS_OODU(last);
        default: return SKS_OODU(unknown);
    }
}

std::string
offen_order_to(const _Offen_order_t& __order)
{
    switch (__order)
    {
        case SKS_OODU(none): return "none";
        case SKS_OODU(first): return "first";
        case SKS_OODU(last): return "last";
        default: return "unknown";
    }
}

_Offen_value_t
offen_from(char __ch, _Offen_number_t __num)
{ return _Offen_storage_t{offen_order_from(__ch), __num}._M_value; }

std::string
offen_to(const _Offen_value_t& __offen)
{
    _Offen_data_t __tmp{_Offen_storage_t{__offen}._M_data};
    std::string __ret{offen_order_to(__tmp._M_order)};

    if (__tmp._M_order == SKS_OODU(none) || \
            __tmp._M_order == SKS_OODU(unknown))
        return __ret;

    __ret += ' ';
    if (__tmp._M_number > 0) __ret += '+';
    __ret += std::to_string(__tmp._M_number);
    return __ret;
}

std::string
offen_to(const offense& __offen)
{ return offen_to(__offen.value()); }

#undef SKS_OODU
#undef SKS_OFFEN_ORDER_DATA_USING

}
