#include "../Includes/Assembler.hpp"

Assembler::Assembler(std::string path):path(path)
{
    this->lexer = new Lexer();
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
            this->lineCounter++;

            if(this->IsNotEmptyLine(line))
            {
                auto nline = this->SanitizerLine(line);

                if(this->IsNotEmptyLine(nline))
                {
                    this->lexer->Tokenize(nline);
                }
            }
        }
    }
    else
    {
        Output::PrintError("File cannot be readed!");
    }
}

bool Assembler::IsNotEmptyLine(std::string line)
{
    for(char letter : line)
    {
        if(letter != Delimiter::whitespace && 
           letter != Delimiter::returning && 
           letter != Delimiter::tabulation && 
           letter != Delimiter::newline )
        {
            return true;
        }
    }

    return false;
}

std::string Assembler::SanitizerLine(std::string& line)
{
    std::string nline;

    for(int i = 0; i < line.size(); i++)
    {
        if(line[i] == Delimiter::comment &&
           line[i + 1] == Delimiter::comment)
        {
            return nline;
        }

        if(line[i] != Delimiter::newline &&
           line[i] != Delimiter::returning &&
           line[i] != Delimiter::tabulation)
        {
            if(line[i] == Delimiter::whitespace &&
               line[i + 1] != Delimiter::whitespace)
            {
                nline.push_back(line[i]);
            }
            else
            {
                nline.push_back(line[i]);
            }
        }
    }

    return nline;
}


