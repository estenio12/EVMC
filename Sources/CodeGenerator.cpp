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
        argument = Tools::ComplementBinaryTo_8_Bits
        (
            BinaryConverter::FromHexadecimal(list[FIRST_ARGUMENT]->value)
        );
    }
    else if(list[FIRST_ARGUMENT]->type == NAME::DECIMAL)
    {
        argument = Tools::ComplementBinaryTo_8_Bits
        (
            BinaryConverter::FromDecimal(list[FIRST_ARGUMENT]->value)
        );
    }
    else if(list[FIRST_ARGUMENT]->type == NAME::REGISTER)
    {
        argument = Tools::ComplementBinaryTo_8_Bits
        (
            BinaryConverter::FromRegister(list[FIRST_ARGUMENT]->value)
        );
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
        FirstArgument = Tools::ComplementBinaryTo_8_Bits
        (
            BinaryConverter::FromHexadecimal(list[FIRST_ARGUMENT]->value)
        );
    }
    else if(list[FIRST_ARGUMENT]->type == NAME::DECIMAL)
    {
        FirstArgument = Tools::ComplementBinaryTo_8_Bits
        (
            BinaryConverter::FromDecimal(list[FIRST_ARGUMENT]->value)
        );
    }
    else if(list[FIRST_ARGUMENT]->type == NAME::REGISTER)
    {
        FirstArgument = Tools::ComplementBinaryTo_8_Bits
        (
            BinaryConverter::FromRegister(list[FIRST_ARGUMENT]->value)
        );
    }

    // # Second Argument
    if(list[SECOND_ARGUMENT]->type == NAME::HEXADECIMAL)
    {
        SecondArgument = Tools::ComplementBinaryTo_8_Bits
        (
            BinaryConverter::FromHexadecimal(list[SECOND_ARGUMENT]->value)
        );
    }
    else if(list[SECOND_ARGUMENT]->type == NAME::DECIMAL)
    {
        SecondArgument = Tools::ComplementBinaryTo_8_Bits
        (
            BinaryConverter::FromDecimal(list[SECOND_ARGUMENT]->value)
        );
    }
    else if(list[SECOND_ARGUMENT]->type == NAME::REGISTER)
    {
        SecondArgument = Tools::ComplementBinaryTo_8_Bits
        (
            BinaryConverter::FromRegister(list[SECOND_ARGUMENT]->value)
        );
    }

    std::cout << "debug: " << opcode << " | ";
    std::cout << FirstArgument << " | ";
    std::cout << SecondArgument << '\n';

    return opcode + FirstArgument + SecondArgument;
}


