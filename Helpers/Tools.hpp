// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <string>

namespace Tools
{
    static std::string toUpperCase(std::string value)
    {
        std::string word; 

        for(char letter : value)
        {
            word.push_back(toupper(letter));
        }

        return word;
    }
};