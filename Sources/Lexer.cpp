#include "../Includes/Lexer.hpp"

Lexer::Lexer(){}

Lexer::~Lexer(){}

Data::Token_list Lexer::Tokenize(std::string line)
{
    Data::Token_list list;

    Output::Print(Tools::toUpperCase(line));

    return list;
}




