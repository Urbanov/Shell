#ifndef SHELL_ASSIGNMENT_H
#define SHELL_ASSIGNMENT_H


#include <memory>
#include "../values/Variable.h"
#include "Statement.h"
#include "../values/Value.h"

class Assignment : public Statement {
private:
    Variable variable;
    std::shared_ptr<Value> value;

public:
    Assignment(Variable&& variable, std::shared_ptr<Value> value);

    void execute() override;
};


#endif //SHELL_ASSIGNMENT_H
