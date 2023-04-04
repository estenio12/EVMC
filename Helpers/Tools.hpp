// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

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
        if(value.empty() || value[1] != 'X') return false;

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

    static std::string ComplementBinaryTo_8_Bits(std::string value)
    {
        std::string buildBin;
        const int SIZE_8 = 8;

        if(value.size() >= SIZE_8) return value;
        
        for(int i = 0; i <= (SIZE_8 - value.size()); i++)
        {
            buildBin.push_back('0');
            std::cout << i << ',' << std::endl;
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

namespace DecimalConverter
{
    static const int ERROR = -1;

    static int FromHexadecimal(std::string value)
    {
        if(value.empty()) return ERROR;

        
        value = Tools::Split(value, 'X')[1];
        std::cout << "entrei " << "\n";

        if(value.empty()) return ERROR;
        
        std::vector<std::pair<char, int>> map
        {   
            {'0', 0},  {'1', 1},  {'2', 2}, 
            {'3', 3},  {'4', 4},  {'5', 5}, 
            {'6', 6},  {'7', 7},  {'8', 8}, 
            {'9', 9},  {'A', 10}, {'B', 11}, 
            {'C', 12}, {'D', 13}, {'E', 14}, 
            {'F', 15}
        };

        std::vector<int> operands;
        int result = 0;
        int base   = 0;
        int index  = 0;
        const int hexa_base = 16;

        for(char letter : value)
        {
            for(auto item : map)
            {
                if(item.first == letter) 
                {
                    operands.push_back(item.second);
                }
            }
        }
    
        for(int i = operands.size() - 1; i >= 0; i--)
        {
            base    = pow(hexa_base, i);
            index   = i - (operands.size() - 1);
            result += operands[abs(index)] * base;
        }

        return result;
    }

    static int FromRegister(std::string value)
    {
        if(value.empty()) return ERROR;

        value = Tools::Split(value, '$')[1];

        if(value.empty()) return ERROR;
        
        return std::stoi(value);
    }

    static int FromString(std::string value)
    {
        return std::stoi(value);
    }
}

namespace SemanticTools
{
    static bool IsValidRegisterFromSetting(int target)
    {
        if(target <= SETTING::MAX_REGISTER &&
           target >= SETTING::MIN_REGISTER )
        {
            return true;
        }

        return false;
    }

    static bool IsValidAddressFromSetting(int target)
    {
        if(target <= SETTING::MAX_ADDRESS &&
           target >= SETTING::MIN_ADDRESS )
        {
            return true;
        }

        return false;
    }

    static bool IsValidForConvert(std::string value)
    {
        if(value.length() <= 10 && value.length() >= 0)
        {
            return true;
        }

        return false;
    }
}


