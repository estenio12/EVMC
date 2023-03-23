// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <fstream>
#include "../Helpers/Definition.hpp"
#include "../Includes/Output.hpp"
#include "../Includes/Lexer.hpp"

class Assembler
{
    private:
        std::fstream fileHandler;
        std::string path;

    private:
        Lexer* lexer;
    
    private:
        int lineCounter = 0;

    public:
        Assembler(std::string path);
        ~Assembler();

    public:
        void Run();

    private:
        bool IsNotEmptyLine(std::string );
        std::string SanitizerLine(std::string& );
};