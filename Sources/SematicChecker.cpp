#include "../Includes/Parser.hpp"

bool Parser::SematicCheck(Data::Token_list list)
{
    if(this->SemanticCheckerSingleAddressParameter(list)) return true;
    if(this->SemanticCheckerSingleRegisterParameter(list)) return true;  
    if(this->SemanticCheckerDoubleAddressParameter(list)) return true;  
    if(this->SemanticCheckerDoubleRegisterParameter(list)) return true;
    if(this->SemanticCheckerDoubleMixedParameter(list)) return true;

    return false;
}

bool Parser::SemanticCheckerSingleAddressParameter(Data::Token_list list)
{
    if(list[COMMAND]->value == LANG::KEYWORDS[LANG::JMP] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::JSR] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::INP] )
    {
        if(list[FIRST_ARGUMENT]->type == NAME::HEXADECIMAL)
        {
            return SemanticTools::IsValidAddressFromSetting
            (
                DecimalConverter::FromHexadecimal(list[FIRST_ARGUMENT]->value)
            );
        }

        if(list[FIRST_ARGUMENT]->type == NAME::DECIMAL)
        {
            if(!SemanticTools::IsValidForConvert(list[FIRST_ARGUMENT]->value)) 
            {
                this->ThrowError(this->DefaultMessageInvalidDecimalRange(), OUTPUTTYPE::IO_ERROR);
                return false;
            }

            return SemanticTools::IsValidAddressFromSetting
            (
                DecimalConverter::FromString(list[FIRST_ARGUMENT]->value)
            );
        }

        this->ThrowError(this->DefaultMessageOutOfAddressRange(list[FIRST_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);
    }

    return false;
}

bool Parser::SemanticCheckerDoubleRegisterParameter(Data::Token_list list)
{
    bool FirstArgumentValid  = false;
    bool SecondArgumentValid = false;

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
       list[COMMAND]->value == LANG::KEYWORDS[LANG::XNOR]||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::ROL] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::ROR] )
    {
        if(SemanticTools::IsValidRegisterFromSetting(DecimalConverter::FromRegister(list[FIRST_ARGUMENT]->value)))
        {
            FirstArgumentValid = true;
        }
        else
        {
            this->ThrowError(this->DefaultMessageRegisterUnknow(list[FIRST_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);        
        }

        if(SemanticTools::IsValidRegisterFromSetting(DecimalConverter::FromRegister(list[SECOND_ARGUMENT]->value)) )
        {
            SecondArgumentValid = true;
        }
        else
        {
            this->ThrowError(this->DefaultMessageRegisterUnknow(list[SECOND_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);        
        }
    }

    return FirstArgumentValid && SecondArgumentValid;
}

bool Parser::SemanticCheckerDoubleAddressParameter(Data::Token_list list)
{
    bool FirstArgumentValid  = false;
    bool SecondArgumentValid = false;

    if(list[COMMAND]->value == LANG::KEYWORDS[LANG::BEQ] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::BNE] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::BGT] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::BLT] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::BGE] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::BLE] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::PRT] )
    {
        if(list[FIRST_ARGUMENT]->type == NAME::HEXADECIMAL)
        {
            if(SemanticTools::IsValidAddressFromSetting(DecimalConverter::FromHexadecimal(list[FIRST_ARGUMENT]->value)))
            {
                FirstArgumentValid = true;
            }
            else
            {
                this->ThrowError(this->DefaultMessageOutOfAddressRange(list[FIRST_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);        
            }
        }

        if(list[FIRST_ARGUMENT]->type == NAME::DECIMAL)
        {
            if(!SemanticTools::IsValidForConvert(list[FIRST_ARGUMENT]->value)) 
            {
                this->ThrowError(this->DefaultMessageInvalidDecimalRange(), OUTPUTTYPE::IO_ERROR);
                return false;
            }

            if(SemanticTools::IsValidAddressFromSetting(DecimalConverter::FromString(list[FIRST_ARGUMENT]->value)))
            {
                FirstArgumentValid = true;
            }
            else
            {
                this->ThrowError(this->DefaultMessageOutOfAddressRange(list[FIRST_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);        
            }
        }

        if(list[SECOND_ARGUMENT]->type == NAME::HEXADECIMAL)
        {
            if(SemanticTools::IsValidAddressFromSetting(DecimalConverter::FromHexadecimal(list[SECOND_ARGUMENT]->value)))
            {
                SecondArgumentValid = true;
            }
            else
            {
                this->ThrowError(this->DefaultMessageOutOfAddressRange(list[SECOND_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);        
            }
        }

        if(list[SECOND_ARGUMENT]->type == NAME::DECIMAL)
        {
            if(!SemanticTools::IsValidForConvert(list[FIRST_ARGUMENT]->value)) 
            {
                this->ThrowError(this->DefaultMessageInvalidDecimalRange(), OUTPUTTYPE::IO_ERROR);
                return false;
            }

            if(SemanticTools::IsValidAddressFromSetting(DecimalConverter::FromString(list[SECOND_ARGUMENT]->value)))
            {
                SecondArgumentValid = true;
            }
            else
            {
                this->ThrowError(this->DefaultMessageOutOfAddressRange(list[SECOND_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);        
            }
        }
    }

    return FirstArgumentValid && SecondArgumentValid;
}

bool Parser::SemanticCheckerSingleRegisterParameter(Data::Token_list list)
{
    if(list[COMMAND]->value == LANG::KEYWORDS[LANG::CLR])
    {
        if(SemanticTools::IsValidRegisterFromSetting(DecimalConverter::FromRegister(list[FIRST_ARGUMENT]->value)))
        {
            return true;
        }

        this->ThrowError(this->DefaultMessageRegisterUnknow(list[FIRST_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);
    }

    return false;
}

bool Parser::SemanticCheckerDoubleMixedParameter(Data::Token_list list)
{
    bool FirstArgumentValid  = false;
    bool SecondArgumentValid = false;

    if(list[COMMAND]->value == LANG::KEYWORDS[LANG::LDX] ||
       list[COMMAND]->value == LANG::KEYWORDS[LANG::SET] )
    {
        if(list[FIRST_ARGUMENT]->type == NAME::HEXADECIMAL)
        {
            if(SemanticTools::IsValidAddressFromSetting(DecimalConverter::FromHexadecimal(list[FIRST_ARGUMENT]->value)))
            {
                FirstArgumentValid = true;
            }
            else
            {
                this->ThrowError(this->DefaultMessageOutOfAddressRange(list[FIRST_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);        
            }
        }

        if(list[FIRST_ARGUMENT]->type == NAME::DECIMAL)
        {
            if(!SemanticTools::IsValidForConvert(list[FIRST_ARGUMENT]->value)) 
            {
                this->ThrowError(this->DefaultMessageInvalidDecimalRange(), OUTPUTTYPE::IO_ERROR);
                return false;
            }

            if(SemanticTools::IsValidAddressFromSetting(DecimalConverter::FromString(list[FIRST_ARGUMENT]->value)))
            {
                FirstArgumentValid = true;
            }
            else
            {
                this->ThrowError(this->DefaultMessageOutOfAddressRange(list[FIRST_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);        
            }
        }
    
        if(SemanticTools::IsValidRegisterFromSetting(DecimalConverter::FromRegister(list[SECOND_ARGUMENT]->value)))
        {
            SecondArgumentValid = true;
        }
        else
        {
            this->ThrowError(this->DefaultMessageRegisterUnknow(list[SECOND_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);        
        }
    }

    if(list[COMMAND]->value == LANG::KEYWORDS[LANG::STX] )
    {
        if(SemanticTools::IsValidRegisterFromSetting(DecimalConverter::FromRegister(list[FIRST_ARGUMENT]->value)))
        {
            FirstArgumentValid = true;
        }
        else
        {
            this->ThrowError(this->DefaultMessageRegisterUnknow(list[FIRST_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);        
        }


        if(list[SECOND_ARGUMENT]->type == NAME::HEXADECIMAL)
        {
            if(SemanticTools::IsValidAddressFromSetting(DecimalConverter::FromHexadecimal(list[SECOND_ARGUMENT]->value)))
            {
                SecondArgumentValid = true;
            }
            else
            {
                this->ThrowError(this->DefaultMessageOutOfAddressRange(list[SECOND_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);        
            }
        }


        if(list[SECOND_ARGUMENT]->type == NAME::DECIMAL)
        {
            if(!SemanticTools::IsValidForConvert(list[FIRST_ARGUMENT]->value)) 
            {
                this->ThrowError(this->DefaultMessageInvalidDecimalRange(), OUTPUTTYPE::IO_ERROR);
                return false;
            }
            
            if(SemanticTools::IsValidAddressFromSetting(DecimalConverter::FromString(list[SECOND_ARGUMENT]->value)))
            {
                SecondArgumentValid = true;
            }
            else
            {
                this->ThrowError(this->DefaultMessageOutOfAddressRange(list[SECOND_ARGUMENT]->value), OUTPUTTYPE::IO_ERROR);        
            }
        }
    
    }

    return FirstArgumentValid && SecondArgumentValid;
}

