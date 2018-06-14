#include "Return.h"
#include "Environment.h"

const std::string Return::getValue()
{
    return std::to_string(Environment::getInstance().getExitCode());
}
