//
// Created by grzegorz on 04.06.18.
//

#ifndef SHELL_SHELL_H
#define SHELL_SHELL_H
#include "Commands.h"

class Shell {
public:
    Shell();
    virtual ~Shell();
    int run();
private:
    int splitArgs(std::string&, std::string*&);
    int countArgs(std::string&);
};


#endif //SHELL_SHELL_H
