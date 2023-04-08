// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <vector>

#include "../Model/Token.hpp"

namespace Data
{
    using Token_list = std::vector<Token*>;
    using Bin = std::string;
}

namespace Delimiter
{
    const char whitespace = ' ';
    const char returning  = '\r';
    const char tabulation = '\t';
    const char newline    = '\n';
    const char backslash  = '/';
}

namespace Result
{
    const std::string error = "-1"; 
}

namespace OUTPUTTYPE
{
    static const uint8_t IO_ERROR    = 0;
    static const uint8_t IO_WARNING  = 1;
    static const uint8_t IO_SUCCESS  = 2;
    static const uint8_t IO_STANDARD = 3;
}

namespace SETTING 
{
    static const int MAX_MEMORY   = 65536;
    static const int MAX_REGISTER = 31;
    static const int MIN_REGISTER = 0;
    static const int MAX_ADDRESS  = MAX_MEMORY - 1;
    static const int MIN_ADDRESS  = 0;
    static const std::string TEMPLATE_8_BITS  = "00000000";
}
