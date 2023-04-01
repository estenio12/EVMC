#include "../Includes/Parser.hpp"

Parser::Parser(int* lineCounter):lineCounter(lineCounter){}

Parser::~Parser(){}

Data::Bin Parser::Parse(Data::Token_list list)
{
    if(this->SyntaxCheck(list) &&
        this->SematicCheck(list))
    {
        // return this->CodeGenerator(list);
        Output::PrintSuccess("OK");
    }
    else
    {
        this->PrintStackTrace();
    }

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


