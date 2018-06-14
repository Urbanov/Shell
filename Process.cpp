//
// Created by kuba on 13.06.18.
//

#include <unistd.h>
#include <iostream>
#include <memory.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <wait.h>
#include "Process.h"

int Process::run() {
    setRedirections();
    int result = fork();
    if(result == 0) {
        changeStandardDescriptors();
        execv(programPath.c_str(), convertProgramArguments());
        for(auto i : descriptors) {
            close(i);
        }
        exit(1);
    }
    else if(result > 0) {
        pid = result;
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

const std::string Process::getValue()  {
    if(!output.empty()) {
        run();
        return "";
    }
    setRedirections();
    const char* path = "/tmp/output_pipe";
    const int buf_len = 512;
    char buf[buf_len];
    int check = mkfifo(path, 0666);
    filePaths[1] = path;
    run();
    int fd = open(path, O_RDONLY);
    ssize_t len = 0;
    std::string value;
    while((len = read(fd, buf, buf_len)) > 0) {
        value.append(buf, static_cast<unsigned long>(len));
    }
    close(fd);
    unlink(path);
    return value;

    //alternatywny kod zmien buf na 512

//    int status = 0;
//    waitpid(pid, &status, 0);
//    auto length = read(fd, buf, 65536);
//    return std::string(buf, static_cast<unsigned long>(length));

    //TODO sprawdz ktora wersja dziala poprawnie
}

Process::Process(const std::string &programPath, const std::vector<std::shared_ptr<Value>> &arguments)
        : programPath(programPath), arguments(arguments), pid(-1)
{
    descriptors.resize(3);
    filePaths.resize(3);
    for(int i = 0; i < filePaths.size(); ++i) {
        descriptors[i] = i;
    }
}

int Process::getPid() const {
    return pid;
}

void Process::changeStandardDescriptors() {
    for(int i =0 ; i < filePaths.size(); ++i) {
        if(!filePaths[i].empty()) {
            int flag = ((i == 0) ? O_WRONLY : O_RDONLY);
            descriptors[i] = open(filePaths[i].c_str(), flag);
            dup2(descriptors[i], i);
            close(descriptors[i]); //TODO check if not problematic line
        }
    }
}

const std::string &Process::getInput() const {
    return input;
}

void Process::setInput(const std::string &input) {
    Process::input = input;
}

const std::string &Process::getOutput() const {
    return output;
}

void Process::setOutput(const std::string &output) {
    Process::output = output;
}

void Process::setRedirections() {
    if(!input.empty()) {
        filePaths[0] = input;
    }

    if(!output.empty()) {
        filePaths[1] = output;
    }
}
