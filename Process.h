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
    Process(const std::string& programPath, const std::vector<std::shared_ptr<Value>>& arguments);

    int run() const override;

    const std::string getValue() override;

    char** convertProgramArguments() const;

    //program can change descriptors of child process using this vector
    std::vector<int> newDescriptors;

private:
    const std::string programPath;

    std::vector<std::shared_ptr<Value>> arguments;

};


#endif //SHELL_PROCESS_H
