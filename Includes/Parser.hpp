// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <iostream>
#include "../Helpers/Definition.hpp"
#include "../Helpers/Tools.hpp"
#include "../Includes/Output.hpp"

class Parser
{
    public:
        Parser();
        ~Parser();

    public:
        Data::Bin Parse(Data::Token_list );

    private:
        Data::Bin CodeGenerator(Token* );
        bool CheckSyntax(Token* );
        bool CheckSematic(Token* );
};