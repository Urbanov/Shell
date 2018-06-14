#ifndef SHELL_PARSER_H
#define SHELL_PARSER_H


#include <string>
#include "../statements/Statement.h"

class Parser {
public:
    static std::shared_ptr<Statement> parse(std::string line);
};


#endif //SHELL_PARSER_H
