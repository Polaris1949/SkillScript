#ifndef _SKS_SCRIPT_H
#define _SKS_SCRIPT_H 1

#include <fstream>
#include <string>

namespace sks
{

class script
{
public:
    using file_type = std::string;

private:
    file_type _M_file;

public:
    script() = default;

    file_type& file();
    const file_type& file() const;
};

}

#endif
