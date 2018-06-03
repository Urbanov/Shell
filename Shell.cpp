//
// Created by grzegorz on 04.06.18.
//

#include "Shell.h"

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
    std::string line;
    std::string* args = nullptr;
    int nArgs = 0;
    int result = 0;
    do
    {
        std::cout << "> ";
        std::getline(std::cin, line);
        nArgs = splitArgs(line, args);
        if(nArgs > 0)
        {
            result = commands.checkCommands(args, nArgs);
            if(result < 0)
            {
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
            ++numberOfSpaces;
            while(isspace(line.at(i++)))
            {
                if(line.at(i) == '\0')
                {
                    --numberOfSpaces;
                }
            }
        }
    }
    return numberOfSpaces + 1;
}
int Shell::createSingleProcess(std::string* args, std::string* in = nullptr, std::string* out = nullptr)
{
    pid_t pid;
    int status;
    //char *arg[] = {"./a.out", NULL};
    pid = fork();
    if(pid == 0)
    {
        if(in != nullptr)
        {
            int inFd = open((*in).c_str(), O_RDWR | O_CREAT);
            dup2(inFd, 0);
        }
        if(out != nullptr)
        {
            int outFd = open((*out).c_str(), O_RDWR | O_CREAT);
            dup2(outFd, 1);
        }
        if(execvp(args[0].c_str(), NULL) == -1)
        {
            std::cerr << "Program exec does not exist\n";
        }
    }
    else if(pid < 0)
    {
        std::cerr << "Cannot create new process\n";
    }
    else
    {
        waitpid(pid, &status, WUNTRACED);
        //can do something with the status
    }
    return 0;
}
