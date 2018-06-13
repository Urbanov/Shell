#ifndef SHELL_RUNNABLE_H
#define SHELL_RUNNABLE_H


#include "Value.h"
#include "Statement.h"

class Runnable : public Value, public Statement {
private:
    std::string test;

public:
    void execute() override;

    virtual void run() = 0;

    const std::string& getValue() const override;
};


#endif //SHELL_RUNNABLE_H
