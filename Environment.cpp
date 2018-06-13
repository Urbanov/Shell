#include <iostream>
#include "Environment.h"

std::shared_ptr<Variable> Environment::getVariable(const std::string& name)
{
    auto search = variables.find(name);
    if (search != variables.end()) {
        return search->second;
    }

    variables.insert(std::make_pair(name, std::make_shared<Variable>(name)));
    return variables.at(name);
}

Environment& Environment::getInstance()
{
    static Environment instance;
    return instance;
}

int Environment::getExitCode()
{
    //TODO
    return 0;
}

void Environment::exportVariable(const std::string& name)
{
    //TODO
    std::cout << "exporting " << name << std::endl;
}
