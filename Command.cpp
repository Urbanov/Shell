#include "Command.h"
#include "Environment.h"
#include <iostream>
#include <utility>
#include <memory>
#include <vector>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>

Command::Command(std::string command_id, std::vector<std::shared_ptr<Value>> arguments)
    : command_id(std::move(command_id))
    , arguments(std::move(arguments))
{
    commands.insert(std::make_pair("echo", [this]() { return echo(); }));
    commands.insert(std::make_pair("cd", [this]() { return cd(); }));
    commands.insert(std::make_pair("pwd", [this]() { return pwd(); }));
    commands.insert(std::make_pair("ls", [this]() { return ls(); }));
    commands.insert(std::make_pair("export", [this]() { return exportVar(); })),
    commands.insert(std::make_pair("exit", [this]() { return exit(); }));
}

int Command::run()
{
    return commands.at(command_id)();
}

int Command::echo() const
{
    if (arguments.size() != 1) {
        std::cerr << "Invalid number of parameters" << std::endl;
        return 1;
    }

    std::cout << arguments[0]->getValue() << std::endl;

    return 0;
}

int Command::cd() const
{
    if (arguments.size() != 1) {
        std::cerr << "Invalid number of parameters" << std::endl;
        return 1;
    }

    if (chdir(arguments[0]->getValue().c_str()) != 0) {
        std::cerr << "Directory does not exist" << std::endl;
        return 1;
    }

    return 0;
}

int Command::pwd() const
{
    const int dir_len = 1024;
    char dir[dir_len];
    getcwd(dir, dir_len);
    std::cout << dir << std::endl;
    return 0;
}

int Command::ls() const
{
    struct dirent** list_of_names = nullptr;
    int n = 0;

    if (!arguments.empty()) {
        std::cerr << "Invalid number of parameters" << std::endl;
        return 1;
    }

    n = scandir(".", &list_of_names, nullptr, alphasort);

    for (int i = 0; i < n; ++i) {
        std::cout << list_of_names[i]->d_name << std::endl;
        free(list_of_names[i]);
    }
    free(list_of_names);

    return 0;
}

int Command::exit() const
{
    Environment::getInstance().exit();
    return 0;
}

int Command::exportVar() const
{
    if (arguments.empty()) {
        int i = 1;
        char* var = *environ;
        for (i; var; i++) {
            std::cout << var << std::endl;
            var = *(environ + i);
        }
        return 0;
    }

    if (arguments.size() == 1) {
        Environment::getInstance().exportVariable(arguments[0]->getValue());
        return 0;
    }

    std::cerr << "Invalid number of parameters" << std::endl;
    return 1;
}

const std::string Command::getValue()
{
    int len = 65536;
    int saved_stdout = dup(1);
    char buffer[len];
    const char* path = "/tmp/command_pipe";
    mkfifo(path, 0666);

    int fd_in = open(path, O_RDONLY | O_NONBLOCK);
    int fd_out = open(path, O_WRONLY);
    dup2(fd_out, 1);

    run();
    auto fetched = read(fd_in, buffer, static_cast<size_t>(len));

    close(fd_in);
    close(fd_out);
    unlink(path);
    dup2(saved_stdout, 1);

    std::string result;
    for (int i = 0; i < fetched; ++i) {
        result += buffer[i];
    }

    return result;
}
