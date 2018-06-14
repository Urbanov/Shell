//
// Created by kuba on 14.06.18.
//

#ifndef SHELL_PIPE_H
#define SHELL_PIPE_H


#include "Runnable.h"
#include "Process.h"

class Pipe : public Runnable {
public:
    explicit Pipe(const std::list<Process>& processList);

    int run() override;

    const std::string getValue() override;

private:
    std::list<Process> processList;
    std::vector<std::string> namedPipes;

    void createPipes();

    void waitForProcesses();

    void destroyPipes();
};


#endif //SHELL_PIPE_H
