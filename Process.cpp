//
// Created by kuba on 13.06.18.
//

#include <unistd.h>
#include <iostream>
#include <memory.h>
#include "Process.h"

int Process::run() {
    int result = fork();
    if(result == 0) {
        for(int i =0 ; i < newDescriptors.size(); ++i) {
            if(newDescriptors[i] != i) {
                dup2(newDescriptors[i], i);
            }
        }
        execv(programPath.c_str(), convertProgramArguments());
        for(auto i : newDescriptors) {
            close(i);
        }
        exit(1);
    }
    else if(result > 0) {

    }
    else {
        std::cerr << "Fork failed." << std::endl;
    }
}

char **Process::convertProgramArguments() {
    auto **convertedArguments = new char*[arguments.size()];
    int count = 0;
    for(auto &element : arguments) {
        convertedArguments[count] = strdup(element->getValue().c_str());
        count++;
    }
    return convertedArguments;
}

const std::string Process::getValue() const {
    return Runnable::getValue();
}

Process::Process(const std::string &programPath, const std::vector<std::shared_ptr<Value>> &arguments)
        : programPath(programPath), arguments(arguments)

{
    newDescriptors.resize(3);
    for(int i = 0; i < newDescriptors.size(); ++i) {
        newDescriptors[i] = i;
    }
}
