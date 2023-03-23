// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include "../Helpers/Definition.hpp"
#include "../Helpers/Tools.hpp"
#include "../Includes/Output.hpp"

class Lexer
{
    public:
        Lexer();
        ~Lexer();

    public:
        Data::Token_list Tokenize(std::string );

    private:
        

};