//
// Created by grzegorz on 04.06.18.
//

#ifndef SHELL_PROCESS_H
#define SHELL_PROCESS_H
#include "Commands.h"

class Process {
public:
    Process() {}
    ~Process() {}
    int parseArgsAndExecute(std::string* args, int& nArgs);

private:
    int countPipes(std::string* args, int& nArgs);
    std::string* checkRedirect(std::string* args, int& nArgs, std::string redirectType);
    int createSingleProcess(char**, std::string*, std::string*);
    char** stringToCStringTable(std::string* args, int& nArgs);
};


#endif //SHELL_PROCESS_H
