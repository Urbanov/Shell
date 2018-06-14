#include <iostream>
#include "Runnable.h"
#include "Environment.h"

const std::string Runnable::getValue()
{
    return test;
}

void Runnable::execute()
{
    int exitCode = run();
    if(exitCode != 0) {
        std::cout<<"Process exited with exit code " << exitCode << std::endl;
    }
    Environment::getInstance().setExitCode(exitCode);
}
