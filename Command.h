#ifndef SHELL_COMMAND_H
#define SHELL_COMMAND_H


#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>
#include "Runnable.h"

class Command : public Runnable {
private:
    std::string command_id;
    std::vector<std::shared_ptr<Value>> arguments;
    std::unordered_map<std::string, std::function<int(void)>> commands;

    int echo() const;
    int cd() const;
    int pwd() const;
    int ls() const;
    int exit() const;

public:
    Command(std::string command_id, std::vector<std::shared_ptr<Value>> arguments);

    int run() override;

    const std::string getValue() override;
};


#endif //SHELL_COMMAND_H
