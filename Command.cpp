#include "Command.h"
#include <iostream>
#include <utility>
#include <memory>
#include <vector>

Command::Command(std::string command_id, std::vector<std::shared_ptr<Value>> arguments)
    : command_id(std::move(command_id))
    , arguments(std::move(arguments))
{
    commands.insert(std::make_pair("echo", [this]() { return echo(); }));
    commands.insert(std::make_pair("cd", [this]() { return cd(); }));
    commands.insert(std::make_pair("pwd", [this]() { return pwd(); }));
    commands.insert(std::make_pair("ls", [this]() { return ls(); }));
    commands.insert(std::make_pair("exit", [this]() { return exit(); }));
    commands.insert(std::make_pair("cat", [this]() { return exit(); }));
}

int Command::run()
{
    return commands.at(command_id)();
}

int Command::echo()
{
    if (arguments.size() != 1) {
        //TODO error
    }

    std::cout << arguments[0]->getValue();

    return 0;
}

int Command::cd()
{
    std::cout << "cd";
    return 0;
}

int Command::pwd()
{
    std::cout << "pwd";
    return 0;
}

int Command::ls()
{
    std::cout << "ls";
    return 0;
}

int Command::exit()
{
    std::cout << "exit";
    return 0;
}

int Command::cat()
{
    return 0;
}
