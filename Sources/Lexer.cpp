#include "../Includes/Lexer.hpp"

Lexer::Lexer(){}

Lexer::~Lexer(){}

Data::Token_list Lexer::Tokenize(std::string line)
{
    Data::Token_list list;

    Output::Print(Tools::toUpperCase(line));

    return list;
}

Token_list_item Lexer::SpliToken(std::string line)
{
    Token_list_item tokens;
    std::string tempTokenList[3]{"", "", ""};
    std::string token = "";
    int index = 0;

    for(char letter : line)
    {
        if(letter == Delimiter::whitespace)
        {
            tempTokenList[index] = token;
            token.clear();
            index++;
        }
        else
        {
            token.push_back(letter);
        }
    }

    if(token.size() != 0)
    {
        tempTokenList[2] = token;
    }

    tokens = new Token_list_item(tempTokenList[0],
                                 tempTokenList[1],
                                 tempTokenList[2]);

    return tokens;
}

