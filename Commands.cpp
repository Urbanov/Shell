//
// Created by grzegorz on 04.06.18.
//

#include "Commands.h"

Commands::Commands(): numberOfCommands(4)
{
    commandNames = new std::string[numberOfCommands];
    commandNames[0] = "cd";
    commandNames[1] = "ls";
    commandNames[2] = "pwd";
    commandNames[3] = "exit";
    commandFunctions = new std::function<int(std::string*, int)>[numberOfCommands];
    commandFunctions[0] = [this] (std::string* args, int nArgs) { return this->cd(args, nArgs); };
    commandFunctions[1] = [this] (std::string* args, int nArgs) { return this->ls(args, nArgs); };
    commandFunctions[2] = [this] (std::string* args, int nArgs) { return this->pwd(args, nArgs); };
    commandFunctions[3] = [this] (std::string* args, int nArgs) { return this->exit(args, nArgs); };
}

Commands::~Commands()
{
    delete[] commandNames;
    delete[] commandFunctions;
}


int Commands::cd(std::string* args, int nArgs)
{
    if(nArgs == 1)
    {
        std::cerr << "Argument expected\n";
    }
    else if(nArgs > 2)
    {
        std::cerr << "Too many arguments\n";
    }
    else if(chdir(args[1].c_str()) != 0)
    {
        std::cerr << "Given directory does not exist\n";
    }
    return 0;
}

int Commands::ls(std::string* args, int nArgs)
{
    struct dirent **listOfNames;
    int n;
    if(nArgs == 2)
    {
        n = scandir(args[1].c_str(), &listOfNames, NULL, alphasort);
    }
    else if(nArgs == 1)
    {
        n = scandir(".", &listOfNames, NULL, alphasort);
    }
    else
    {
        std::cerr << "Too many arguments\n";
    }
    if(n < 0)
    {
        std::cerr << "Given directory does not exist\n";
    }
    else
    {
        for(int i = 0; i < n; ++i)
        {
            std::cout << listOfNames[i]->d_name << '\n';
            free(listOfNames[i]);
        }
        std::cout << std::endl;
        free(listOfNames);
    }
    return 0;
}

int Commands::pwd(std::string* args, int nArgs)
{
    const int dirLen = 1024;
    char* dir = new char[dirLen];
    if(getcwd(dir, dirLen) == NULL)
    {
        std::cerr << "Full path to current directory is too long\n";
    }
    else if(nArgs == 1)
    {
        std::cout << dir << std::endl;
    }
    else
    {
        std::cerr << "Too many arguments\n";
    }
    return 0;
}

int Commands::exit(std::string* args, int nArgs)
{
    if(nArgs > 1)
    {
        std::cerr << "Too many arguments\n";
    }
    return EXIT_SHELL;
}

int Commands::checkCommands(std::string* args, int& nArgs)
{
    int result = -1;
    for(int i = 0; i < numberOfCommands; ++i)
    {
        if(args[0] == commandNames[i])
        {
            result = commandFunctions[i](args, nArgs);
        }
    }
    return result;
}

