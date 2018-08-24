#ifndef _SKS_SKILL_H
#define _SKS_SKILL_H 1

#include "attr.h"
#include "offen.h"
#include "style.h"
#include "script.h"

namespace sks
{

inline namespace __skill_detail
{

using _Sk_index_t = uint32_t;
using _Sk_name_t = std::string;
using _Sk_attr_t = attribute;
using _Sk_desc_t = std::string;
using _Sk_power_t = uint8_t;
using _Sk_style_t = style;
using _Sk_pp_t = uint8_t;
using _Sk_speed_t = uint8_t;
using _Sk_offen_t = offense;
using _Sk_script_t = script;

}

class skill
{
public:
    using index_type = _Sk_index_t;
    using name_type = _Sk_name_t;
    using attr_type = _Sk_attr_t;
    using desc_type = _Sk_desc_t;
    using power_type = _Sk_power_t;
    using style_type = _Sk_style_t;
    using pp_type = _Sk_pp_t;
    using speed_type = _Sk_speed_t;
    using offen_type = _Sk_offen_t;
    using script_type = _Sk_script_t;

private:
    index_type _M_index;
    name_type _M_name;
    attr_type _M_attr;
    desc_type _M_desc;
    power_type _M_power;
    style_type _M_style;
    pp_type _M_pp;
    speed_type _M_speed;
    offen_type _M_offen;
    script_type _M_active;
    script_type _M_passive;

public:
    skill();

    bool empty() const;

    index_type& index();
    const index_type& index() const;

    name_type& name();
    const name_type& name() const;

    attr_type& attr();
    const attr_type& attr() const;

    desc_type& desc();
    const desc_type& desc() const;

    power_type& power();
    const power_type& power() const;

    style_type& style();
    const style_type& style() const;

    pp_type& pp();
    const pp_type& pp() const;

    speed_type& speed();
    const speed_type& speed() const;

    offen_type& offen();
    const offen_type& offen() const;

    script_type& active();
    const script_type& active() const;

    script_type& passive();
    const script_type& passive() const;
};

}

#endif
