// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <fstream>
#include <filesystem>

#include "../Helpers/Definition.hpp"
#include "../Includes/Output.hpp"
#include "../Includes/Lexer.hpp"
#include "../Includes/Parser.hpp"

class Assembler
{
    private:
        std::ifstream fileReader;
        std::fstream fileWriter;
        std::string path;

    private:
        Lexer* lexer;
        Parser* parser;
    
    private:
        int lineCounter = 0;
        const std::string outputPath = "app.wbin";
        bool ProtocoloIsWritten = false;

    private:
        // # first 24 byte is signature
        // # the last 2 bytes is module, exemple: 00 = 64 bits architecture
        const std::string defaultProtocolo = "01110111011101100110110100";

    public:
        Assembler(std::string path);
        ~Assembler();

    public:
        void Run();

    private:
        bool IsNotEmptyLine(std::string );
        std::string SanitizeLine(std::string& );
        void WriteBin(Data::Bin );
        void CheckOutputPath();
};