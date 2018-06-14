#ifndef SHELL_EXPORTENV_H
#define SHELL_EXPORTENV_H


#include <memory>
#include "Statement.h"

class ExportEnv : public Statement {
private:
    std::string name;

public:
    explicit ExportEnv(const std::string& name);

    void execute() override;
};


#endif //SHELL_EXPORTENV_H
