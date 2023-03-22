#include "../Includes/Assembler.hpp"

Assembler::Assembler(std::string path):path(path)
{
    this->fileHandler.open(path, std::ios::in | std::ios::binary);
}

Assembler::~Assembler(){}

void Assembler::Run()
{
    std::string line;

    if(this->fileHandler.is_open() && 
       this->fileHandler.good())
    {
        while(std::getline(this->fileHandler, line))
        {
            if(this->IsCommentedLine(line) == true)
            {
                Output::PrintSuccess(line);
            }
        }
    }
    else
    {
        Output::PrintError("File cannot be readed!");
    }
}

bool Assembler::IsCommentedLine(std::string line)
{   
    for(int i = 0; i < line.size(); i++)
    {
        if(line[i] == Delimiter::comment &&
           line[i + 1] == Delimiter::comment)
        {
            return true;
        }

        if(line[i] != Delimiter::whitespace &&
           line[i] != Delimiter::returning &&
           line[i] != Delimiter::newline &&
           line[i] != Delimiter::tabulation)
        {
            return false;
        }
    }

    return false;
}



