#include <iostream>
#include <memory>
#include "Shell.h"
#include "parser/Parser.h"
#include "Statement.h"

void Shell::start()
{
    std::string line;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);

        auto statement = Parser::parse(line);
        statement->execute();
    }
}
