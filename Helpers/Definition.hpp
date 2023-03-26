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
    const char backslash    = '/';
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
