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
                    auto token  = this->lexer->Tokenize(nline);
                    auto binary = this->parser->Parse(token);
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
       if(i == 0 && line[0] == Delimiter::whitespace ||
          line[i] == Delimiter::whitespace && 
          line[i - 1] == Delimiter::whitespace )
       {
            continue;
       }
       else
       {
            if((i + 1) < line.size())
            {
                if(line[i] == Delimiter::backslash &&
                   line[i + 1] == Delimiter::backslash)
                {
                    return nline;
                }
            }

            if(line[i] != Delimiter::newline &&
               line[i] != Delimiter::returning &&
               line[i] != Delimiter::tabulation)
            {
                nline.push_back(line[i]);
            }
       }
        
    }

    return nline;
}


