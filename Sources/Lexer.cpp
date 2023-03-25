#include "../Includes/Lexer.hpp"

Lexer::Lexer(){}

Lexer::~Lexer(){}

Token* Lexer::Tokenize(std::string line)
{
    return this->SpliToken(line);
}

Token* Lexer::SpliToken(std::string line)
{
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
    
    return new Token(tempTokenList[0],
                     tempTokenList[1],
                     tempTokenList[2]);
}

