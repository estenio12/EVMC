#include "../Includes/Parser.hpp"

Parser::Parser(int* lineCounter):lineCounter(lineCounter){}

Parser::~Parser(){}

Data::Bin Parser::Parse(Data::Token_list list)
{
    if(this->SyntaxCheck(list))
    {
        Output::PrintSuccess("Ok");
    }
    else
    {
        this->PrintStackTrace();
    }
    // if(this->CheckSyntax(list) &&
    //     this->CheckSematic(list))
    // {
    //     return this->CodeGenerator(list);
    // }
    // else
    // {
    //     this->PrintStackTrace();
    // }

    return Result::error;
}

void Parser::ThrowError(std::string message, uint8_t out = OUTPUTTYPE::IO_STANDARD)
{
    std::string newMessage = "Line: ";
    newMessage += std::to_string(*this->lineCounter);
    newMessage += " | " + message;

    this->StackTrace.push_back(std::make_pair(newMessage, out));
}

void Parser::PrintStackTrace()
{
    for(auto out : this->StackTrace)
    {
        switch (out.second)
        {
            case OUTPUTTYPE::IO_ERROR:
                Output::PrintError(out.first);
            break;

            case OUTPUTTYPE::IO_WARNING:
                Output::PrintWarning(out.first);
            break;

            case OUTPUTTYPE::IO_SUCCESS:
                Output::PrintSuccess(out.first);
            break;
        
            default:
                Output::Print(out.first);
            break;
        }
    }
}

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
