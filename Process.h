//
// Created by kuba on 13.06.18.
//

#ifndef SHELL_PROCESS_H
#define SHELL_PROCESS_H


#include "Runnable.h"
#include <list>
#include <vector>
#include <memory>

class Process : public Runnable {
public:
    Process(const std::string &programPath, const std::vector<std::shared_ptr<Value>> &arguments);

    int run() override;

    const std::string getValue() override;


    //program can change descriptors of child process using this vector
    std::vector<std::string> filePaths;

    int getPid() const;

private:
    char **convertProgramArguments();

    void changeStandardDescriptors();

    const std::string programPath;

    std::vector<std::shared_ptr<Value>> arguments;

    int pid;

    std::vector<int> descriptors;
};


#endif //SHELL_PROCESS_H
