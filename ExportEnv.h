#ifndef SHELL_EXPORTENV_H
#define SHELL_EXPORTENV_H


#include "Statement.h"

class ExportEnv : public Statement {
public:
    void execute() override;
};


#endif //SHELL_EXPORTENV_H
