#include "style.h"

namespace sks
{

#define SKS_STYLE_DATA_USING(D) static_cast<_Style_value_t>(_Style_data_t::D)
#define SKS_SDU(X) SKS_STYLE_DATA_USING(X)

style::
style()
    : _M_style{SKS_SDU(none)}
{}

style::
style(const value_type& __style)
    : _M_style{__style}
{}

style::
style(char __ch)
    : _M_style{style_from(__ch)}
{}

_Style_value_t&
style::
data()
{ return this->_M_style; }

const _Style_value_t&
style::
data() const
{ return this->_M_style; }

void
style::
assign(const value_type& __style)
{ this->_M_style = __style; }

void
style::
assign(const style& __style)
{ this->_M_style = __style._M_style; }

_Style_value_t
style_from(char __ch)
{
    switch (__ch)
    {
        case '\0': return SKS_SDU(none);
        case 'a': case 'p': return SKS_SDU(physics);
        case 'b': case 'm': return SKS_SDU(magic);
        case 'c': case 'v': return SKS_SDU(variety);
        default: return SKS_SDU(unknown);
    }
}

std::string
style_to(const _Style_value_t& __style)
{
    switch (__style)
    {
        case SKS_SDU(none): return "none";
        case SKS_SDU(physics): return "physics";
        case SKS_SDU(magic): return "magic";
        case SKS_SDU(variety): return "variety";
        default: return "unknown";
    }
}

std::string
style_to(const style& __style)
{ return style_to(__style.data()); }

#undef SKS_SDU
#undef SKS_STYLE_DATA_USING

}
