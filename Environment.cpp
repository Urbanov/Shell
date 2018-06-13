#include <iostream>
#include <unistd.h>
#include <pwd.h>
#include "Environment.h"

std::shared_ptr<Variable> Environment::getVariable(const std::string& name)
{
    auto search = variables.find(name);
    if (search != variables.end()) {
        return search->second;
    }

    auto variable = std::make_shared<Variable>(name);
    auto value = getenv(name.c_str());
    if (value) {
        variable->assign(value);
    }
    variables.insert(std::make_pair(name, variable));
    return variable;
}

Environment& Environment::getInstance()
{
    static Environment instance;
    return instance;
}

int Environment::getExitCode() const
{
    //TODO
    return 0;
}

void Environment::exportVariable(const std::string& name) const
{
    //TODO
    std::cout << "exporting " << name << std::endl;
}

const char* Environment::getUserName() const
{
    uid_t uid = geteuid();
    struct passwd* pw = getpwuid(uid);
    return pw->pw_name;
}
