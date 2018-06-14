#ifndef SHELL_ENVIRONMENT_H
#define SHELL_ENVIRONMENT_H


#include <memory>
#include <vector>
#include <unordered_map>
#include "values/Variable.h"

class Environment {
private:
    std::unordered_map<std::string, std::shared_ptr<Variable>> variables;
    int exitCode;
    bool running;

    Environment();

public:
    Environment(const Environment& other) = delete;

    Environment(Environment&& other) = delete;

    static Environment& getInstance();

    std::shared_ptr<Variable> getVariable(const std::string& name);

    void exportVariable(const std::string& name);

    int getExitCode() const;

    void setExitCode(int exit);

    const char* getUserName() const;

    bool isRunning() const;

    void exit();
};


#endif //SHELL_ENVIRONMENT_H
