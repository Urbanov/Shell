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
    const int buf_len = 512;
    char buf[buf_len];
    int status = 0;
    int check = mkfifo("/tmp/output_pipe", 0666);
    filePaths[1] = "/tmp/output_pipe";
    run();
    int fd = open("/tmp/output_pipe", O_RDONLY);
    ssize_t len = 0;
    std::string value;
    while((len = read(fd, buf, buf_len)) > 0) {
        value.append(buf, static_cast<unsigned long>(len));
    }
    close(fd);
    unlink("/tmp/output_pipe");
    return value;

    //alternatywny kod zmien buf na 512

//
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
