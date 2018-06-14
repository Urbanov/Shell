#ifndef SHELL_VALUE_H
#define SHELL_VALUE_H


#include <string>

class Value {
public:
    virtual const std::string getValue() = 0;
};


#endif //SHELL_VALUE_H
