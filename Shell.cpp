#include <iostream>
#include <memory>
#include "Shell.h"
#include "parser/Parser.h"
#include "Statement.h"
#include "Environment.h"

void Shell::start() const
{
    std::string line;

    while (true) {
        printPrompt();
        std::getline(std::cin, line);

        auto statement = Parser::parse(line);

        try {
            statement->execute();
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

    }
}

void Shell::printPrompt() const
{
    std::cout << Environment::getInstance().getUserName() << "@uxpshell $ ";
}
