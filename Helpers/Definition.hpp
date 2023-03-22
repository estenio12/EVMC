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
}

namespace Delimiter
{
    const char whitespace = ' ';
    const char returning    = '\r';
    const char tabulation = '\t';
    const char newline    = '\n';
    const char comment    = '/';
}