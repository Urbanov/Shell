#include "ExportEnv.h"
#include "Environment.h"

void ExportEnv::execute()
{
    Environment::getInstance().exportVariable(name);
}

ExportEnv::ExportEnv(const std::string& name)
    : name(name)
{}
