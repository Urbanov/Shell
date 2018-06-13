#include <iostream>
#include "Runnable.h"

const std::string& Runnable::getValue() const
{
    return "testujemy looo";
}

void Runnable::execute()
{
    run();
}
