#ifndef SHELL_VARIABLE_H
#define SHELL_VARIABLE_H


#include <string>
#include "Value.h"

class Variable : public Value {
private:
    std::string name;
    std::string value;

public:
    explicit Variable(const std::string& name);

    void exportEnv() const;

    void assign(const std::string& value);

    bool operator==(const Variable& rhs) const;

    const std::string& getName() const;

    const std::string getValue() const override;
};


#endif //SHELL_VARIABLE_H
