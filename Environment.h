#ifndef SHELL_ENVIRONMENT_H
#define SHELL_ENVIRONMENT_H


#include <memory>
#include <vector>
#include <unordered_map>
#include "Variable.h"

class Environment {
private:
    std::unordered_map<std::string, std::shared_ptr<Variable>> variables;

    static int exitCode = 0;
    Environment();

public:

    Environment(const Environment &other) = delete;
    Environment(Environment &&other) = delete;

    static Environment& getInstance();

    std::shared_ptr<Variable> getVariable(const std::string& name);

    void exportVariable(const std::string& name) const;

    int getExitCode();

    void setExitCode(int exit);

    int getExitCode() const;

    const char* getUserName() const;
};


#endif //SHELL_ENVIRONMENT_H
