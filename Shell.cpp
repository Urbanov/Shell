//
// Created by grzegorz on 04.06.18.
//

#include "Shell.h"
#include "Process.h"

Shell::Shell()
{
    //ctor
}

Shell::~Shell()
{
    //dtor
}

int Shell::run()
{
    Commands commands;
    Process process;
    std::string line;
    std::string* args = nullptr;
    int nArgs = 0;
    int result = 0;
    do
    {
        std::cout << "> ";
        nArgs = 0;
        std::getline(std::cin, line);
        nArgs = splitArgs(line, args);
        if(nArgs > 0)
        {
            result = commands.checkCommands(args, nArgs);
            if(result < 0)
            {
                process.parseArgsAndExecute(args, nArgs);
                //TODO
            }
            delete[] args;
        }

    }while(result != EXIT_SHELL);
    return 0;
}

int Shell::splitArgs(std::string& line, std::string*& args)
{
    std::istringstream iss(line);
    int numberOfArgs = countArgs(line);
    if(numberOfArgs == 0)
    {
        return 0;
    }
    args = new std::string[numberOfArgs];
    for(int i = 0; i < numberOfArgs; ++i)
    {
        iss >> args[i];
    }
    return numberOfArgs;
}

int Shell::countArgs(std::string& line)
{
    int numberOfSpaces = 0;
    unsigned int i = 0;
    bool lastSpace = false;
    if(line.size() == 0)
    {
        return 0;
    }

    while(isspace(line.at(i)))
    {
        ++i;
    }

    for(; i < line.size(); ++i)
    {
        if(isspace(line.at(i)))
        {
            if(!lastSpace)
            {
                lastSpace = true;
                ++numberOfSpaces;
            }
        }
        else
        {
            lastSpace = false;
        }
    }
    return numberOfSpaces + 1;
}
