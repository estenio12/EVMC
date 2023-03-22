// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#include <string>

class Token
{
    public:
        std::string command; 
        std::string param1; 
        std::string param2; 

    public:
        Token(std::string command, 
              std::string param1, 
              std::string param2):
              command(command),
              param1(param1),
              param2(param2){}

        ~Token(){}
};