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
    return BinaryConverter::FromCommand(list[COMMAND]->value);
}

Data::Bin Parser::CodeGenerateOpcodeSingleArgument(Data::Token_list list)
{
    std::string opcode;
    std::string argument;

    // # Opcode
    opcode = BinaryConverter::FromCommand(list[COMMAND]->value);

    // # First Argument
    if(list[FIRST_ARGUMENT]->type == NAME::HEXADECIMAL)
    {
        argument = this->CodeGenerateHexadecimal(list[COMMAND]->value, list[FIRST_ARGUMENT]->value);
    }
    else if(list[FIRST_ARGUMENT]->type == NAME::DECIMAL)
    {
        argument = BinaryConverter::FromDecimal(list[FIRST_ARGUMENT]->value);
    }
    else if(list[FIRST_ARGUMENT]->type == NAME::REGISTER)
    {
        argument = BinaryConverter::FromRegister(list[FIRST_ARGUMENT]->value);
    }

    return opcode + argument;
}

Data::Bin Parser::CodeGenerateOpcodeDoubleArgument(Data::Token_list list)
{
    std::string opcode;
    std::string FirstArgument;
    std::string SecondArgument;

    // # Opcode
    opcode = BinaryConverter::FromCommand(list[COMMAND]->value);

    // # First Argument
    if(list[FIRST_ARGUMENT]->type == NAME::HEXADECIMAL)
    {
        FirstArgument = this->CodeGenerateHexadecimal(list[COMMAND]->value, 
                                                      list[FIRST_ARGUMENT]->value);
    }
    else if(list[FIRST_ARGUMENT]->type == NAME::DECIMAL)
    {
        FirstArgument = BinaryConverter::FromDecimal(list[FIRST_ARGUMENT]->value);
    }
    else if(list[FIRST_ARGUMENT]->type == NAME::REGISTER)
    {
        FirstArgument = BinaryConverter::FromRegister(list[FIRST_ARGUMENT]->value);
    }

    // # Second Argument
    if(list[SECOND_ARGUMENT]->type == NAME::HEXADECIMAL)
    {
        SecondArgument = this->CodeGenerateHexadecimal(list[COMMAND]->value, 
                                                       list[SECOND_ARGUMENT]->value);
    }
    else if(list[SECOND_ARGUMENT]->type == NAME::DECIMAL)
    {
        SecondArgument = BinaryConverter::FromDecimal(list[SECOND_ARGUMENT]->value);
    }
    else if(list[SECOND_ARGUMENT]->type == NAME::REGISTER)
    {
        SecondArgument = BinaryConverter::FromRegister(list[SECOND_ARGUMENT]->value);
    }

    return opcode + FirstArgument + SecondArgument;
}

Data::Bin Parser::CodeGenerateHexadecimal(std::string opcode, std::string hexadecimal)
{
    if(opcode == LANG::KEYWORDS[LANG::SET])
    {
        return BinaryConverter::FromHexadecimal_8_Bits(hexadecimal);
    }

    return BinaryConverter::FromHexadecimal_16_Bits(hexadecimal);
}
