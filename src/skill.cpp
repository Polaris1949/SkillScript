#include "skill.h"

namespace sks
{

skill::
skill()
    : _M_index{}, _M_name{}, _M_attr{}, _M_desc{}, _M_power{}, _M_style{}, \
        _M_pp{}, _M_speed{}, _M_offen{}, _M_active{}, _M_passive{}
{}

bool
skill::
empty() const
{ return this->_M_name.empty(); }

_Sk_index_t&
skill::
index()
{ return this->_M_index; }

const _Sk_index_t&
skill::
index() const
{ return this->_M_index; }

_Sk_name_t&
skill::
name()
{ return this->_M_name; }

const _Sk_name_t&
skill::
name() const
{ return this->_M_name; }

_Sk_attr_t&
skill::
attr()
{ return this->_M_attr; }

const _Sk_attr_t&
skill::
attr() const
{ return this->_M_attr; }

_Sk_desc_t&
skill::
desc()
{ return this->_M_desc; }

const _Sk_desc_t&
skill::
desc() const
{ return this->_M_desc; }

_Sk_power_t&
skill::
power()
{ return this->_M_power; }

const _Sk_power_t&
skill::
power() const
{ return this->_M_power; }

_Sk_style_t&
skill::
style()
{ return this->_M_style; }

const _Sk_style_t&
skill::
style() const
{ return this->_M_style; }

_Sk_pp_t&
skill::
pp()
{ return this->_M_pp; }

const _Sk_pp_t&
skill::
pp() const
{ return this->_M_pp; }

_Sk_speed_t&
skill::
speed()
{ return this->_M_speed; }

const _Sk_speed_t&
skill::
speed() const
{ return this->_M_speed; }

_Sk_offen_t&
skill::
offen()
{ return this->_M_offen; }

const _Sk_offen_t&
skill::
offen() const
{ return this->_M_offen; }

_Sk_script_t&
skill::
active()
{ return this->_M_active; }

const _Sk_script_t&
skill::
active() const
{ return this->_M_active; }

_Sk_script_t&
skill::
passive()
{ return this->_M_passive; }

const _Sk_script_t&
skill::
passive() const
{ return this->_M_passive; }

}
