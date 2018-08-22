#ifndef _SKS_FILE_H
#define _SKS_FILE_H 1

#include <string>
#include "skill.h"

namespace sks
{

class file
{
public:
    using file_type = std::string;

private:
    file_type _M_file;

public:
    file() = default;
    file(const file_type& __file);

    skill operator() (bool __msg = true) const;
};

}

#endif
