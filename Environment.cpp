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
    return exitCode;
}

void Environment::exportVariable(const std::string& name)
{
    setenv(name.c_str(), getVariable(name)->getDirectValue().c_str(), 1);
}

const char* Environment::getUserName() const
{
    uid_t uid = geteuid();
    struct passwd* pw = getpwuid(uid);
    return pw->pw_name;
}

void Environment::setExitCode(int exit)
{
    exitCode = exit;
}

Environment::Environment()
    : exitCode(0)
    , running(true)
{}

bool Environment::isRunning() const
{
    return running;
}

void Environment::exit()
{
    running = false;
}
