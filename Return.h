#ifndef SHELL_RETURN_H
#define SHELL_RETURN_H


#include "Value.h"

class Return : public Value {
public:
    const std::string& getValue() const override;
};


#endif //SHELL_RETURN_H
