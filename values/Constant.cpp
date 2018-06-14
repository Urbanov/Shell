#include "Constant.h"

const std::string Constant::getValue()
{
    return value;
}

Constant::Constant(const std::string& value)
    : value(value)
{}
