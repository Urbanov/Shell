//
// Created by kuba on 14.06.18.
//

#ifndef SHELL_REDIRECT_H
#define SHELL_REDIRECT_H


#include "Process.h"

class Redirect : public Process {
public:
    Redirect(const std::string &programPath, const std::vector<std::shared_ptr<Value>> &arguments);

    const std::string &getInput() const;

    void setInput(const std::string &input);

    const std::string &getOutput() const;

    void setOutput(const std::string &output);

private:
    std::string input;
    std::string output;

    int run() override;

    const std::string getValue() override;

    void setRedirections();
};


#endif //SHELL_REDIRECT_H
