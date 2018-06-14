//
// Created by kuba on 14.06.18.
//

#include "Redirect.h"

Redirect::Redirect(const std::string& programPath, const std::vector<std::shared_ptr<Value>>& arguments) : Process(
    programPath, arguments)
{}

int Redirect::run()
{
    setRedirections();
    return Process::run();
}

const std::string Redirect::getValue()
{
    if (!output.empty()) {
        run();
        return "";
    }
    setRedirections();
    return Process::getValue();
}

const std::string& Redirect::getInput() const
{
    return input;
}

void Redirect::setInput(const std::string& input)
{
    Redirect::input = input;
}

const std::string& Redirect::getOutput() const
{
    return output;
}

void Redirect::setOutput(const std::string& output)
{
    Redirect::output = output;
}

void Redirect::setRedirections()
{
    if (!input.empty()) {
        filePaths[0] = input;
    }

    if (!output.empty()) {
        filePaths[1] = output;
    }
}


