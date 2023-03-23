// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <string>

namespace Tools
{
    static std::string ToUpperCase(std::string value)
    {
        std::string word; 

        for(char letter : value)
        {
            word.push_back(toupper(letter));
        }

        return word;
    }
};