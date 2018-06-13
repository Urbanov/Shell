//
// Created by kuba on 14.06.18.
//

#ifndef SHELL_PIPE_H
#define SHELL_PIPE_H


#include "Runnable.h"
#include "Process.h"

class Pipe : public Runnable {
public:
    Pipe(const std::list<Process> &processList);

private:
    std::list<Process> processList;
};


#endif //SHELL_PIPE_H
