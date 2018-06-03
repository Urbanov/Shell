//
// Created by grzegorz on 04.06.18.
//

#ifndef SHELL_COMMANDS_H
#define SHELL_COMMANDS_H
#include <sys/wait.h>
#include <sys/types.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <dirent.h>
#include <fcntl.h>
#include <functional>
#include <sstream>
#define EXIT_SHELL 1

class Commands {
public:
    Commands();
    virtual ~Commands();
    int checkCommands(std::string*, int&);
private:
    const int numberOfCommands;
    std::string* commandNames;
    std::function<int(std::string*, int)>* commandFunctions;
    int cd(std::string*, int nArgs);
    int ls(std::string*, int nArgs);
    int pwd(std::string*, int nArgs);
    int exit(std::string*, int nArgs);
};


#endif //SHELL_COMMANDS_H
