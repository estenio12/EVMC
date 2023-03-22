// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <fstream>
#include "../Helpers/Definition.hpp"
#include "../Includes/Output.hpp"

class Assembler
{
    private:
        std::fstream fileHandler;
        std::string path;
    
    private:
        int lineCounter = 0;

    public:
        Assembler(std::string path);
        ~Assembler();

    public:
        void Run();

    private:
        bool IsCommentedLine(std::string );
};