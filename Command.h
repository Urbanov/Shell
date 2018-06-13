#ifndef SHELL_COMMAND_H
#define SHELL_COMMAND_H


#include <memory>
#include <vector>
#include "Runnable.h"

class Command : public Runnable {
private:
    std::string command_id;
    std::vector<std::shared_ptr<Value>> arguments;

    void echo();
public:
    Command(std::string command_id, std::vector<std::shared_ptr<Value>> arguments);

    void run() override;
};


#endif //SHELL_COMMAND_H
