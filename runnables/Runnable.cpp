#include <iostream>
#include "Runnable.h"
#include "../Environment.h"

void Runnable::execute()
{
    Environment::getInstance().setExitCode(run());
}