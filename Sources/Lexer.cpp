#include "../Includes/Lexer.hpp"

Lexer::Lexer(){}

Lexer::~Lexer(){}

Data::Token_list Lexer::Tokenize(std::string line)
{
    auto list = this->SpliToken(line);
    Data::Token_list TList;

    for(auto token : list)
    {
        TList.push_back(this->TokenIdentifier(Tools::ToUpperCase(token)));
    }

    list.clear();

    return TList;
}

std::vector<std::string> Lexer::SpliToken(std::string line)
{
    std::vector<std::string> list;
    std::string token = "";

    for(char letter : line)
    {
        if(letter == Delimiter::whitespace)
        {
            list.push_back(token);
            token.clear();
        }
        else
        {
            token.push_back(letter);
        }
    }

    if(token.size() > 0)
    {
        list.push_back(token);
    }
    
    return list;
}

Token* Lexer::TokenIdentifier(std::string token)
{
    const char REGISTER_SYMBOL = '$';

    // # Check if is a keyword
    for(auto keyword : LANG::KEYWORDS)
    {
        if(token == keyword)
        {
            return new Token(NAME::KEYWORD, token);
        }
    }

    // # Check if is a register name
    if(token[0] == REGISTER_SYMBOL)
    {
        return new Token(NAME::REGISTER, token);
    }

    // # Check if is a decimal number
    if(Tools::IsDecimal(token))
    {
        return new Token(NAME::DECIMAL, token);
    }

    // # Check if is a hexadecimal number
    if(Tools::IsHexadecimal(token))
    {
        return new Token(NAME::HEXADECIMAL, token);
    }

    return new Token(NAME::UNRECOGNIZED, token);
}