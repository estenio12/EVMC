// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#include <string>

class Token
{
    public:
        std::string type;
        std::string value;

    public:
        Token(std::string type, 
              std::string value):
              type(type),
              value(value){}
        ~Token(){}
};