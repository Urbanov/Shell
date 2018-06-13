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

    int echo();
    int cd();
    int pwd();
    int ls();
    int exit();
    int cat();

public:
    Command(std::string command_id, std::vector<std::shared_ptr<Value>> arguments);

    int run() override;
};


#endif //SHELL_COMMAND_H
