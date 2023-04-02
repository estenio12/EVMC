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
#include "../Includes/Parser.hpp"

class Assembler
{
    private:
        std::ifstream fileReader;
        std::ofstream fileWriter;
        std::string path;

    private:
        Lexer* lexer;
        Parser* parser;
    
    private:
        int lineCounter = 0;

    public:
        Assembler(std::string path,
                  std::string outputPath);
        ~Assembler();

    public:
        void Run();

    private:
        bool IsNotEmptyLine(std::string );
        std::string SanitizeLine(std::string& );
        void WriteBin(Data::Bin );
        std::string CheckOutputPath(std::string );
};