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
        const std::string outputPath = "app.bin";
        bool ProtocoloIsWritten = false;

    private:
        // # first 24 byte is signature
        const std::string defaultProtocolo = "011001010111011001101101";

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