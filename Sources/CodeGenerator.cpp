#include "../Includes/Parser.hpp"

Data::Bin Parser::CodeGenerator(Data::Token_list list)
{
    if(list.size() == 1) return this->CodeGenerateOpcodeNoArgument(list);
    if(list.size() == 2) return this->CodeGenerateOpcodeSingleArgument(list);
    if(list.size() == 3) return this->CodeGenerateOpcodeDoubleArgument(list);

    Output::PrintError("An error accured in Code Generator.");
    exit(EXIT_FAILURE);

    return "";
}

Data::Bin Parser::CodeGenerateOpcodeNoArgument(Data::Token_list list)
{
    std::string opcode;

    for(auto item : BINARYMAPPER::MNEMONICS)
    {
        if(item.first == list[COMMAND]->value)
        {
            opcode = item.second;
        }
    } 

    return opcode;
}

Data::Bin Parser::CodeGenerateOpcodeSingleArgument(Data::Token_list list)
{
    std::string opcode;
    std::string argument;

    // # Opcode
    for(auto item : BINARYMAPPER::MNEMONICS)
    {
        if(item.first == list[COMMAND]->value)
        {
            opcode = item.second;
        }
    }

    // # First Argument
    if(list[FIRST_ARGUMENT]->type == NAME::HEXADECIMAL)
    {
        argument = BinaryConverter::FromHexadecimal(list[FIRST_ARGUMENT]->value);
    }
    else if(list[FIRST_ARGUMENT]->type == NAME::DECIMAL)
    {
        argument = BinaryConverter::FromDecimal(list[FIRST_ARGUMENT]->value);
    }
    else if(list[FIRST_ARGUMENT]->type == NAME::REGISTER)
    {
        argument = BinaryConverter::FromDecimal(list[FIRST_ARGUMENT]->value);
    }

    return opcode + argument;
}

Data::Bin Parser::CodeGenerateOpcodeDoubleArgument(Data::Token_list list)
{
    std::string opcode;
    std::string FirstArgument;
    std::string SecondArgument;

    // # Opcode
    for(auto item : BINARYMAPPER::MNEMONICS)
    {
        if(item.first == list[COMMAND]->value)
        {
            opcode = item.second;
        }
    }

    // # First Argument
    if(list[FIRST_ARGUMENT]->type == NAME::HEXADECIMAL)
    {
        FirstArgument = BinaryConverter::FromHexadecimal(list[FIRST_ARGUMENT]->value);
    }
    else if(list[FIRST_ARGUMENT]->type == NAME::DECIMAL)
    {
        FirstArgument = BinaryConverter::FromDecimal(list[FIRST_ARGUMENT]->value);
    }
    else if(list[FIRST_ARGUMENT]->type == NAME::REGISTER)
    {
        FirstArgument = BinaryConverter::FromDecimal(list[FIRST_ARGUMENT]->value);
    }

    // # Second Argument
    if(list[SECOND_ARGUMENT]->type == NAME::HEXADECIMAL)
    {
        FirstArgument = BinaryConverter::FromHexadecimal(list[SECOND_ARGUMENT]->value);
    }
    else if(list[SECOND_ARGUMENT]->type == NAME::DECIMAL)
    {
        FirstArgument = BinaryConverter::FromDecimal(list[SECOND_ARGUMENT]->value);
    }
    else if(list[SECOND_ARGUMENT]->type == NAME::REGISTER)
    {
        FirstArgument = BinaryConverter::FromDecimal(list[SECOND_ARGUMENT]->value);
    }

    return opcode + FirstArgument + SecondArgument;
}


