#include "Command.h"
#include <iostream>
#include <utility>
#include <memory>
#include <vector>

void Command::run()
{
    // TODO
    echo();
}

void Command::echo()
{
    if (arguments.size() != 1) {
        //TODO error
    }

    std::cout << arguments[0]->getValue();
}

Command::Command(std::string command_id, std::vector<std::shared_ptr<Value>> arguments)
    : command_id(std::move(command_id))
    , arguments(std::move(arguments))
{}
