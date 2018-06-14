#ifndef SHELL_CONSTANT_H
#define SHELL_CONSTANT_H


#include "Value.h"

class Constant : public Value {
private:
    std::string value;

public:
    Constant(const std::string& value);

    const std::string getValue() override;
};


#endif //SHELL_CONSTANT_H
