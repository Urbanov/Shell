#ifndef SHELL_RUNNABLE_H
#define SHELL_RUNNABLE_H


#include "../values/Value.h"
#include "../statements/Statement.h"

class Runnable : public Value, public Statement {
public:
    void execute() final;

    virtual int run() = 0;
};


#endif //SHELL_RUNNABLE_H
