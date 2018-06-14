#ifndef SHELL_RUNNABLE_H
#define SHELL_RUNNABLE_H


#include "Value.h"
#include "Statement.h"

class Runnable : public Value, public Statement {
private:
    std::string test = "xddd";

public:
    void execute() final;

    virtual int run() = 0;

    const std::string getValue() override;
};


#endif //SHELL_RUNNABLE_H
