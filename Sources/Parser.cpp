#include "../Includes/Parser.hpp"

Parser::Parser(){}

Parser::~Parser(){}

Data::Bin Parser::Parse(Token* token)
{
    if(this->Checker(token))
    {
        return this->ConvertToBinary(token);
    }

    return Result::error;
}

bool Parser::Checker(Token* token)
{

    return false;
}

Data::Bin Parser::ConvertToBinary(Token* token)
{
    return "";
}