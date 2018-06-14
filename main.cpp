#include <signal.h>
#include <iostream>
#include <unistd.h>
#include "Shell.h"
#include "Environment.h"

void kill_em_all(int sig)
{
    Environment::getInstance().isTerminated = true;
    Environment::getInstance().propagateSIGINT();
    std::cout<<std::endl;
}

int main()
{
    signal(SIGINT, (void (*)(int)) kill_em_all);
    Shell shell;
    shell.start();
}

