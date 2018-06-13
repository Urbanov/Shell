#include <iostream>
#include "Runnable.h"

const std::string& Runnable::getValue() const
{
    return test;
}

void Runnable::execute()
{
    run();
}
