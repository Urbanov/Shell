#include <iostream>
#include "Runnable.h"
#include "../Environment.h"

void Runnable::execute()
{
    if(!Environment::getInstance().isTerminated) {
        Environment::getInstance().setExitCode(run());
    }
}