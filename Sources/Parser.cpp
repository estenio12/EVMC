#include "../Includes/Parser.hpp"

Parser::Parser(){}

Parser::~Parser(){}

Data::Bin Parser::Parse(Data::Token_list list)
{
    for(auto token : list)
    {
        if(this->CheckSyntax(token) &&
           this->CheckSematic(token))
        {
            return this->CodeGenerator(token);
        }
    }

    return Result::error;
}

Data::Bin Parser::CodeGenerator(Token* token)
{
    return "";
}