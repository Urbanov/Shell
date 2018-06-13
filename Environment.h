#ifndef SHELL_ENVIRONMENT_H
#define SHELL_ENVIRONMENT_H


#include <memory>
#include <vector>
#include <unordered_map>
#include "Variable.h"

class Environment {
private:
    std::unordered_map<std::string, std::shared_ptr<Variable>> variables;

public:
    static Environment& getInstance();

    std::shared_ptr<Variable> getVariable(const std::string& name);

    void exportVariable(const std::string& name);

    int getExitCode();
};


#endif //SHELL_ENVIRONMENT_H
