#include <iostream>
#include "Runnable.h"
#include "Environment.h"

void Runnable::execute()
{
    int exitCode = run();
    if (exitCode != 0) {
        std::cout << "Process exited with exit code " << exitCode << std::endl;
    }
    Environment::getInstance().setExitCode(exitCode);
}

//Environment::getInstance().setExitCode(run());
//TODO change to one liner