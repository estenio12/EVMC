// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include "../Helpers/Definition.hpp"

class Parser
{
    public:
        Parser();
        ~Parser();

    public:
        Data::Bin Parse(Token* );

    private:
        bool Checker(Token* );
        Data::Bin ConvertToBinary(Token* );
};