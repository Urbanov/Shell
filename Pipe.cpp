//
// Created by kuba on 14.06.18.
//

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <iostream>
#include "Pipe.h"

const int alphabet_length = 25;
const int capital_a_ascii_number = 65;

Pipe::Pipe(const std::list<std::shared_ptr<Process>>& processList) : processList(processList)
{
    namedPipes.resize(processList.size() - 1);
    for (int i = 0; i < namedPipes.size(); ++i) {
        namedPipes[i] = "/tmp/pipe_";
        int value = i;
        do {
            namedPipes[i].push_back(static_cast<char>(capital_a_ascii_number + value % alphabet_length));
            value /= alphabet_length;
        } while (value != 0);
    }
}

int Pipe::run()
{
    createPipes();
    for (auto& process : processList) {
        process->forkNewProcess();
    }
    waitForProcesses();
    destroyPipes();
}

const std::string Pipe::getValue()
{
    createPipes();
    auto iterator = processList.begin();
    for (int i = 0; i < processList.size() - 1; ++i) {
        (*iterator)->forkNewProcess();
        ++iterator;
    }
    std::string result = (*iterator)->getValue();
    waitForProcesses();
    destroyPipes();
    return result;
}

void Pipe::createPipes()
{
    auto iterator = processList.begin();
    for (auto &namedPipe : namedPipes) {
        mkfifo(namedPipe.c_str(), 0666);
        (*iterator)->setDescPath(1, namedPipe);
        ++iterator;
        (*iterator)->setDescPath(0, namedPipe);
    }
}

void Pipe::waitForProcesses()
{
    int status = 0;
    while (wait(&status) > 0); //waiting for all child processes to end
}

void Pipe::destroyPipes()
{
    for (const auto& pipePath : namedPipes) {
        unlink(pipePath.c_str());
    }
}
