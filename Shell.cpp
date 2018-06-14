#include <iostream>
#include <memory>
#include "Shell.h"
#include "parser/Parser.h"
#include "statements/Statement.h"
#include "Environment.h"

void Shell::start() const
{
    std::string line;

    do {
        Environment::getInstance().isTerminated = false;

        printPrompt();
        std::getline(std::cin, line);

        if (!line.empty()) {
            try {
                auto statement = Parser::parse(line);
                statement->execute();
            }
            catch (std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }

    } while (Environment::getInstance().isRunning());
}

void Shell::printPrompt() const
{
    std::cout << Environment::getInstance().getUserName() << "@uxpshell $ ";
}
