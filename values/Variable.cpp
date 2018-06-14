#include <iostream>
#include "Variable.h"
#include "../Environment.h"

Variable::Variable(const std::string& name)
    : name(name)
{}

void Variable::assign(const std::string& value)
{
    this->value = value;
}

bool Variable::operator==(const Variable& rhs) const
{
    return name == rhs.name;
}

const std::string Variable::getValue()
{
    return Environment::getInstance().getVariable(name)->value;
}

const std::string& Variable::getName() const
{
    return name;
}

const std::string Variable::getDirectValue() const
{
    return value;
}
