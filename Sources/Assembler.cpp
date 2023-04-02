#include "../Includes/Assembler.hpp"

Assembler::Assembler(std::string path, std::string outputPath = ""):path(path)
{
    this->lexer  = new Lexer();
    this->parser = new Parser(&this->lineCounter);
    this->fileReader.open(path, std::ios::in | std::ios::binary);
    
    outputPath = this->CheckOutputPath(outputPath);
    this->fileWriter.open(outputPath, std::ios::out | std::ios::binary | std::ios::app);
}

Assembler::~Assembler(){}

void Assembler::Run()
{
    std::string line;

    if(this->fileReader.is_open() && 
       this->fileReader.good())
    {
        while(std::getline(this->fileReader, line))
        {
            this->lineCounter++;

            if(this->IsNotEmptyLine(line))
            {
                auto nline = this->SanitizeLine(line);

                if(this->IsNotEmptyLine(nline))
                {
                    auto token  = this->lexer->Tokenize(nline);
                    auto binary = this->parser->Parse(token);
                    this->WriteBin(binary);
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

std::string Assembler::SanitizeLine(std::string& line)
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

void Assembler::WriteBin(Data::Bin binary)
{
    if(this->fileWriter.is_open() && this->fileWriter.good())
    {
        this->fileWriter.write(binary.c_str(), binary.size());
    }
    else
    {
        Output::PrintError("An error accured while trying to save the binary.");
    }
}

std::string Assembler::CheckOutputPath(std::string path)
{
    std::string defaultAppName = "app.wbin";

    if(path.empty())
    {
        return defaultAppName;
    }

    return path;
}


