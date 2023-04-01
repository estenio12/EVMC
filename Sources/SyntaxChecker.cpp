#include "../Includes/Parser.hpp"

bool Parser::SyntaxCheck(Data::Token_list list)
{
    // # Check if valid Keyword
    if(list[COMMAND]->type == NAME::UNRECOGNIZED)
    {
        this->ThrowError("unrecognized opcode | " + list[COMMAND]->value, OUTPUTTYPE::IO_ERROR);
        
        return false;
    }

    if(this->SyntaxCheckerSingleAddressParameter(list)) return true;
    if(this->SyntaxCheckerSingleRegisterParameter(list)) return true;  
    if(this->SyntaxCheckerSingleCommandParameter(list)) return true;  
    if(this->SyntaxCheckerDoubleAddressParameter(list)) return true;  
    if(this->SyntaxCheckerDoubleRegisterParameter(list)) return true;
    if(this->SyntaxCheckerDoubleMixedParameter(list)) return true;

    return false;
}

bool Parser::SyntaxCheckerSingleAddressParameter(Data::Token_list list)
{
    if(list[COMMAND]->value == LANG::KEYWORDS[LANG::JMP] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::JSR] )
    {
        if(list.size() == 2)
        {
            if(list[FIRST_ARGUMENT]->type == NAME::HEXADECIMAL ||
               list[FIRST_ARGUMENT]->type == NAME::DECIMAL)
            {
                return true;
            }

            this->ThrowError(this->BuildMessageSingleArgument(list), OUTPUTTYPE::IO_ERROR);
        }
        else
        {
            this->ThrowError(this->DefaultMessageArgumentErro(), OUTPUTTYPE::IO_ERROR);
        }
    }

    return false;
}

bool Parser::SyntaxCheckerDoubleRegisterParameter(Data::Token_list list)
{
    if(list[COMMAND]->value == LANG::KEYWORDS[LANG::MOV] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::ADD] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::SUB] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::MUL] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::DIV] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::CMP] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::AND] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::OR]  ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::XOR] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::NOT] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::NAND]||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::NOR] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::XNOR] )
    {
        if(list.size() == 3)
        {
            if(list[FIRST_ARGUMENT]->type == NAME::REGISTER &&
               list[SECOND_ARGUMENT]->type == NAME::REGISTER)
            {
                return true;
            }

            this->ThrowError(this->BuildMessageFullRegister(list), OUTPUTTYPE::IO_ERROR);
        }
        else
        {
            this->ThrowError(this->DefaultMessageArgumentErro(), OUTPUTTYPE::IO_ERROR);
        }
    }

    return false;
}

bool Parser::SyntaxCheckerDoubleAddressParameter(Data::Token_list list)
{
    if(list[COMMAND]->value == LANG::KEYWORDS[LANG::BEQ] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::BNE] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::BGT] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::BLT] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::BGE] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::BLE] )
    {
        if(list.size() == 3)
        {
            if((list[FIRST_ARGUMENT]->type == NAME::HEXADECIMAL || 
                list[FIRST_ARGUMENT]->type == NAME::DECIMAL) &&
               (list[SECOND_ARGUMENT]->type == NAME::HEXADECIMAL || 
                list[SECOND_ARGUMENT]->type == NAME::DECIMAL))
            {
                return true;
            }

            this->ThrowError(this->BuildMessageFull(list), OUTPUTTYPE::IO_ERROR);
        }
        else
        {
            this->ThrowError(this->DefaultMessageArgumentErro(), OUTPUTTYPE::IO_ERROR);
        }
    }

    return false;
}

bool Parser::SyntaxCheckerSingleRegisterParameter(Data::Token_list list)
{
    if(list[COMMAND]->value == LANG::KEYWORDS[LANG::CLR])
    {
        if(list.size() == 2)
        {
            if(list[FIRST_ARGUMENT]->type == NAME::REGISTER)
            {
                return true;
            }

            this->ThrowError(this->BuildMessageSingleRegister(list), OUTPUTTYPE::IO_ERROR);
        }
        else
        {
            this->ThrowError(this->DefaultMessageArgumentErro(), OUTPUTTYPE::IO_ERROR);
        }
    }

    return false;
}

bool Parser::SyntaxCheckerSingleCommandParameter(Data::Token_list list)
{
    if(list[COMMAND]->value == LANG::KEYWORDS[LANG::NOP] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::RTS] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::OFF] )
    {
        if(list.size() == 1)
        {
            return true;
        }
        else
        {
            this->ThrowError(this->DefaultMessageArgumentErro(), OUTPUTTYPE::IO_ERROR);
        }
    }

    return false;
}

bool Parser::SyntaxCheckerDoubleMixedParameter(Data::Token_list list)
{
    bool FirstArgumentValid  = false;
    bool SecondArgumentValid = false;

    if(list.size() == 3)
    {
        if(list[COMMAND]->value == LANG::KEYWORDS[LANG::LDX] )
        {
            if(list[FIRST_ARGUMENT]->type == NAME::HEXADECIMAL || 
               list[FIRST_ARGUMENT]->type == NAME::DECIMAL )
            {
                FirstArgumentValid  = true;
            }

            if(list[SECOND_ARGUMENT]->type == NAME::REGISTER)
            {
                SecondArgumentValid = true;
            }
        }

        
        if(list[COMMAND]->value == LANG::KEYWORDS[LANG::STX] )
        {
            if(list[FIRST_ARGUMENT]->type == NAME::REGISTER)
            {
                FirstArgumentValid  = true;
            }
            
            if(list[SECOND_ARGUMENT]->type == NAME::HEXADECIMAL || 
               list[SECOND_ARGUMENT]->type == NAME::DECIMAL )
            {
                SecondArgumentValid = true;
            }
        }

        this->ThrowError(this->BuildMessageFull(list), OUTPUTTYPE::IO_ERROR);
    }
    else
    {
        this->ThrowError(this->DefaultMessageArgumentErro(), OUTPUTTYPE::IO_ERROR);
    }

    return FirstArgumentValid && SecondArgumentValid;
}

