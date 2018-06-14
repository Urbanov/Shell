#include "Assignment.h"
#include "../Environment.h"


void Assignment::execute()
{
    Environment::getInstance().getVariable(variable.getName())->assign(value->getValue());
}

Assignment::Assignment(Variable&& variable, std::shared_ptr<Value> value)
    : variable(std::forward<Variable>(variable))
    , value(std::move(value))
{}
