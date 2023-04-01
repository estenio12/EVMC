// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <iostream>
#include <vector>
#include "../Helpers/Definition.hpp"
#include "../Helpers/Tools.hpp"
#include "../Includes/Output.hpp"

class Parser
{
    private:
        int* lineCounter = 0;
        std::vector<std::pair<std::string, uint8_t>> StackTrace;

    private:
        const uint8_t COMMAND         = 0;
        const uint8_t FIRST_ARGUMENT  = 1;
        const uint8_t SECOND_ARGUMENT = 2;

    public:
        Parser(int* lineCounter);
        ~Parser();

    public:
        Data::Bin Parse(Data::Token_list );

    private:
        // Data::Bin CodeGenerator(Data::Token_list );
        bool SyntaxCheck(Data::Token_list );
        bool SematicCheck(Data::Token_list );
        void ThrowError(std::string, uint8_t );
        void PrintStackTrace();
        std::string BuildMessageSingleArgument(Data::Token_list );
        std::string BuildMessageFull(Data::Token_list);
        std::string BuildMessageFullRegister(Data::Token_list);
        std::string BuildMessageSingleRegister(Data::Token_list);
        std::string BaseMessageRegister();
        std::string BaseMessageAddress();
        std::string DefaultMessageArgumentErro();
        std::string DefaultMessageOutOfAddressRange(std::string);
        std::string DefaultMessageRegisterUnknow(std::string);

    // # Syntax
    private:
        bool SyntaxCheckerSingleAddressParameter(Data::Token_list );
        bool SyntaxCheckerSingleRegisterParameter(Data::Token_list );
        bool SyntaxCheckerSingleCommandParameter(Data::Token_list );
        bool SyntaxCheckerDoubleAddressParameter(Data::Token_list );
        bool SyntaxCheckerDoubleRegisterParameter(Data::Token_list );

    // # Semantic
    private:
        bool SemanticCheckerSingleAddressParameter(Data::Token_list );
        bool SemanticCheckerSingleRegisterParameter(Data::Token_list );
        bool SemanticCheckerDoubleAddressParameter(Data::Token_list );
        bool SemanticCheckerDoubleRegisterParameter(Data::Token_list );
        bool SemanticCheckerMixed(Data::Token_list );

};