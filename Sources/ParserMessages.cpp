#include "../Includes/Parser.hpp"


std::string Parser::BuildMessageFull(Data::Token_list list)
{
    return "unexpected argument | COMMAND: "+ list[COMMAND]->value +" | argument 1: " + list[FIRST_ARGUMENT]->value + " | argument 2:  " + list[SECOND_ARGUMENT]->value +
           this->BaseMessageAddress();
}

std::string Parser::BuildMessageFullRegister(Data::Token_list list)
{
    return "unexpected argument | COMMAND: "+ list[COMMAND]->value +" | argument 1: " + list[FIRST_ARGUMENT]->value + " | argument 2:  " + list[SECOND_ARGUMENT]->value +
           this->BaseMessageRegister();
}

std::string Parser::BuildMessageSingleArgument(Data::Token_list list)
{
    return "unexpected argument | COMMAND: "+ list[COMMAND]->value +" | argument: " + list[FIRST_ARGUMENT]->value +
           this->BaseMessageAddress();
}

std::string Parser::BuildMessageSingleRegister(Data::Token_list list)
{
    return "unexpected argument | COMMAND: "+ list[COMMAND]->value +" | argument 1: " + list[FIRST_ARGUMENT]->value +
           this->BaseMessageRegister();
}

std::string Parser::DefaultMessageArgumentErro()
{
    return "the number of arguments passed is not compatible with the command used.";
}

std::string Parser::BaseMessageRegister()
{
    return "\nDo you not forgotten to use '$' sign before register name? \nExemple: $15; "
           "\nExemplo opcode: mov $23 $4"
           "\nNote: All register has a name, and your nomenclature stay between $0 ~ $" +
           std::to_string(BINARYMAPPER::REGISTER.size() - 1);
}

std::string Parser::BaseMessageAddress()
{
    return "\nFor the opcodes that expect an address, you must pass decimal values or hexadecimal values."
           "\nExemple Decimal: LDX 453"
           "\nExemple Hexadecimal: LDX 0x3F"
           "\nExemple Hexadecimal: BEQ 0x3F 0x2DE";
}

std::string Parser::DefaultMessageOutOfAddressRange(std::string target)
{
    return "The address value passed is outside the supported address range. "
           "\nargument: " + target +
           "\nMax address memory: " + std::to_string(SETTING::MAX_ADDRESS);
}

std::string Parser::DefaultMessageRegisterUnknow(std::string target)
{
    return "The register name does not exist.\nargument: " + target;
}

std::string Parser::DefaultMessageInvalidDecimalRange()
{
    return "The number of digits entered in the integer is greater than the 64-bit limit.";
}