// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <vector>

#include "../Helpers/Definition.hpp"
#include "../Helpers/Tools.hpp"
#include "../Includes/Output.hpp"

class Lexer
{
    public:
        Lexer();
        ~Lexer();

    public:
        Token* Tokenize(std::string );

    private:
        Token* SpliToken(std::string );

};