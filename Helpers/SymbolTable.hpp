// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <string>
#include <vector>

namespace BINARYMAPPER
{
    static std::vector<std::pair<std::string, std::string>> MNEMONICS
    {
        {"NOP", "00000000"},{"LDX", "00000001"},{"STX", "00000010"},
        {"MOV", "00000011"},{"ADD", "00000100"},{"SUB", "00000101"},
        {"MUL", "00000110"},{"DIV", "00000111"},{"JMP", "00001000"},
        {"JSR", "00001001"},{"RTS", "00001010"},{"CMP", "00001011"},
        {"BEQ", "00001100"},{"BNE", "00001101"},{"BGT", "00001110"},
        {"BLT", "00001111"},{"BGE", "00010000"},{"BLE", "00010001"},
        {"CLR", "00010010"},{"OFF", "00010011"},{"AND", "00010100"},
        {"OR", "00010101"}, {"XOR", "00010110"},{"NOT", "00010111"},
        {"NAND", "00011000"},{"NOR", "00011001"},{"XNOR", "00011010"}
    };

    static std::vector<std::pair<char, std::string>> HEXADECIMAL
    {
        {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, 
        {'3', "0011"}, {'4', "0100"}, {'5', "0101"},
        {'6', "0110"}, {'7', "0111"}, {'8', "1000"}, 
        {'9', "1001"}, {'A', "1010"}, {'B', "1011"}, 
        {'C', "1100"}, {'D', "1101"}, {'E', "1110"},
        {'F', "1111"}
    };

    static char BIT(int value)
    {
        if(value == 1)
        {
            return '1';
        }

        return '0';
    }

    static std::vector<std::pair<std::string, std::string>> REGISTER
    {
        {"$0",  "00000000"}, {"$1",  "00000001"}, 
        {"$2",  "00000010"}, {"$3",  "00000011"}, 
        {"$4",  "00000100"}, {"$5",  "00000101"}, 
        {"$6",  "00000110"}, {"$7",  "00000111"}, 
        {"$8",  "00001000"}, {"$9",  "00001001"}, 
        {"$10", "00001010"}, {"$11", "00001011"}, 
        {"$12", "00001100"}, {"$13", "00001101"}, 
        {"$14", "00001110"}, {"$15", "00001111"}, 
        {"$16", "00010000"}, {"$17", "00010001"}, 
        {"$18", "00010010"}, {"$19", "00010011"}, 
        {"$20", "00010100"}, {"$21", "00010101"}, 
        {"$22", "00010110"}, {"$23", "00010111"}, 
        {"$24", "00011000"}, {"$25", "00011001"}, 
        {"$26", "00011010"}, {"$27", "00011011"}, 
        {"$28", "00011100"}, {"$29", "00011101"}, 
        {"$30", "00011110"}, {"$31", "00011111"}, 
    };
};

namespace LANG
{
    static std::vector<std::string> KEYWORDS
    {
        "NOP", "LDX", "STX", 
        "MOV", "ADD", "SUB", 
        "MUL", "DIV", "JMP", 
        "JSR", "RTS", "CMP", 
        "BEQ", "BNE", "BGT", 
        "BLT", "BGE", "BLE", 
        "CLR", "OFF", "AND", 
        "OR",  "XOR", "NOT", 
        "NAND", "NOR", "XNOR"
     };
}

namespace NAME
{
    static std::string KEYWORD      = "keyword";
    static std::string REGISTER     = "register";
    static std::string DECIMAL      = "decimal";
    static std::string HEXADECIMAL  = "hexadecimal";
    static std::string UNRECOGNIZED = "unrecognized";
}

