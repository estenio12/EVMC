// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#include <iostream>

#include "../Includes/Assembler.hpp"

int main(int argc, char** argv)
{
    Assembler* compiler = new Assembler(argv[1]);
    compiler->Run();

    return EXIT_SUCCESS;
}