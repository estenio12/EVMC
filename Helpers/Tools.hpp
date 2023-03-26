// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "../Helpers/SymbolTable.hpp"

namespace Tools
{
    static std::string ToUpperCase(std::string value)
    {
        std::string word; 

        for(char letter : value)
        {
            word.push_back(toupper(letter));
        }

        return word;
    }

    static bool Contains(std::string source, char target)
    {
        for(char letter : source)
        {
            if(letter == target)
            {
                return true;
            }
        }

        return false;
    }

    static std::vector<std::string> Split(std::string source, char condition)
    {
        std::vector<std::string> list;
        std::string chunk;

        for(char letter : source)
        {
            if(letter == condition)
            {
                list.push_back(chunk);
                chunk.clear();
            }
            else
            {
                chunk.push_back(letter);
            }
        }

        if(chunk.size() > 0)
        {
            list.push_back(chunk);
            chunk.clear();
        }

        return list;
    }

    static bool IsValidHexadecimal(std::string value)
    {
        if(value.empty()) return false;

        auto list = Tools::Split(value, 'X');

        if(list.size() > 2)
        {
            return false;
        }

        std::string NON_VALID_HEXA_VALUES = "GHIKLMNOPQRSTVXYZ";
        bool hitted = false;

        if(Tools::Contains(value, 'X'))
        {
            for(char letter : value)
            {
                for(char non_hexa_letter : NON_VALID_HEXA_VALUES)
                {
                    if(letter == non_hexa_letter )
                    {
                        if(letter == 'X' && hitted == false)
                        {
                            hitted = true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
            
            return true;
        }

        return false;
    }

    static bool IsHexadecimal(std::string value)
    {
        if(value.empty()) return false;

        std::string NON_VALID_HEXA_VALUES = "GHIKLMNOPQRSTVYZ";

        if(Tools::Contains(value, 'X'))
        {
            for(char letter : value)
            {
                for(char non_hexa_letter : NON_VALID_HEXA_VALUES)
                {
                    if(letter == non_hexa_letter)
                    {
                        return false;
                    }
                }
            }
            
            return Tools::IsValidHexadecimal(value);
        }

        return false;
    }

    static bool IsDecimal(std::string value)
    {
        std::string digit = "0123456789";
        bool hitted = false;

        for(char letter : value)
        {
            hitted = false;

            for(char letterdigit : digit)
            {
                if(letter == letterdigit)
                {
                    hitted = true;
                }
            }

            if(!hitted)
            {
                return false;
            }
        }

        return true;
    }

    static std::string ComplementBinaryTo64Bits(std::string value)
    {
        std::string buildBin;
        const int SIZE_64 = 64;

        for(int i = 0; i <= (SIZE_64 - value.size()); i++)
        {
            buildBin.push_back('0');
        }

        return buildBin += value;
    }
}

namespace BinaryConverter
{
    static std::string FromHexadecimal(std::string value)
    {
        std::string bin;
        value = Tools::Split(value, 'X')[1];

        for(char letter : value)
        {
            for(auto map : BINARYMAPPER::HEXADECIMAL)
            {
                if(letter == map.first)
                {
                    bin += map.second;
                }
            }    
        }

        return bin;
    }

    static std::string FromDecimal(std::string value)
    {
        std::string buildBin;
        std::string bin;
        int nval = std::stoi(value);
    
        while(nval > 0)
        {
            buildBin.push_back(BINARYMAPPER::BIT(nval % 2));
            nval /= 2;
        }

        for(int i = buildBin.size(); i >= 0; i--)
        {
            bin.push_back(buildBin[i]);
        }

        return bin;
    }

    static std::string FromCommand(std::string value)
    {
        std::string binary = "-1";

        for(auto bin : BINARYMAPPER::MNEMONICS)
        {
            if(bin.first == value)
            {
                binary = bin.second;
            }
        }

        return binary;
    }

    static std::string FromRegister(std::string value)
    {
        std::string bin;

        for(auto map : BINARYMAPPER::REGISTER)
        {
            if(value == map.first)
            {
                bin += map.second;
            }
        }    
        

        return bin;
    }
}