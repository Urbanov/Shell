#include "Visitor.h"
#include "../Statement.h"
#include "../Assignment.h"
#include "../Return.h"
#include "../Constant.h"
#include "../Command.h"
#include "../ExportEnv.h"
#include "../Process.h"
#include "../Pipe.h"

antlrcpp::Any Visitor::visitStatement(ShellParser::StatementContext* context)
{

    std::shared_ptr<Statement> statement;

    if (context->assignment()) {
        statement = visitAssignment(context->assignment());
    }
    else if (context->runnable()) {
        statement = visitRunnable(context->runnable());
    }
    else if (context->exportEnv()) {
        statement = visitExportEnv(context->exportEnv());
    }

    return statement;
}

antlrcpp::Any Visitor::visitAssignment(ShellParser::AssignmentContext* context)
{
    std::shared_ptr<Statement> statement = std::make_shared<Assignment>(Variable(context->VARIABLE_TOKEN()->getText()), visitValue(context->value()));
    return statement;
}

antlrcpp::Any Visitor::visitValue(ShellParser::ValueContext* context)
{
    std::shared_ptr<Value> value;

    if (context->runnable()) {
        value = std::dynamic_pointer_cast<Value>(visitRunnable(context->runnable()).as<std::shared_ptr<Statement>>());
    }
    else if (context->VARIABLE_VALUE_TOKEN()) {
        value = std::make_shared<Variable>(context->VARIABLE_VALUE_TOKEN()->getText().substr(1));
    }
    else if (context->RETURN_TOKEN()) {
        value = std::make_shared<Return>();
    }
    else if (context->PATH_TOKEN()) {
        value = std::make_shared<Constant>(context->PATH_TOKEN()->getText());
    }
    else if (context->VARIABLE_TOKEN()) {
        value = std::make_shared<Constant>(context->VARIABLE_TOKEN()->getText());
    }
    else if (context->CONSTANT_TOKEN()) {
        value = std::make_shared<Constant>(context->CONSTANT_TOKEN()->getText());
    }
    else if (context->QUOTE_STRING_TOKEN()) {
        value = std::make_shared<Constant>(context->QUOTE_STRING_TOKEN()->getText().substr(1, context->QUOTE_STRING_TOKEN()->getText().size() - 2));
    }

    return value;
}

antlrcpp::Any Visitor::visitExportEnv(ShellParser::ExportEnvContext* context)
{
    std::shared_ptr<Statement> exportEnv = std::make_shared<ExportEnv>(context->VARIABLE_TOKEN()->getText());
    return exportEnv;
}

antlrcpp::Any Visitor::visitRunnable(ShellParser::RunnableContext* context)
{
    std::shared_ptr<Statement> runnable;

    if (context->command()) {
        runnable = visitCommand(context->command());
    }
    else if (context->process()) {
        runnable = visitProcess(context->process());
    }
    else if (context->pipe()) {
        runnable = visitPipe(context->pipe());
    }

    return runnable;
}

antlrcpp::Any Visitor::visitArguments(ShellParser::ArgumentsContext* context)
{
    std::vector<std::shared_ptr<Value>> values;
    for (auto&& value_context : context->value()) {
        std::shared_ptr<Value> argument = visitValue(value_context);
        values.push_back(argument);
    }
    return values;
}

antlrcpp::Any Visitor::visitProcess(ShellParser::ProcessContext* context)
{
    std::shared_ptr<Statement> process = std::make_shared<Process>(context->PATH_TOKEN()->getText(),
                                                                   visitArguments(context->arguments()));
    if (context->INPUT_REDIRECTION_TOKEN()) {
        std::dynamic_pointer_cast<Process>(process)->setInput(context->INPUT_REDIRECTION_TOKEN()->getText());
    }
    if (context->OUTPUT_REDIRECTION_TOKEN()) {
        std::dynamic_pointer_cast<Process>(process)->setInput(context->OUTPUT_REDIRECTION_TOKEN()->getText());
    }
    return process;
}

antlrcpp::Any Visitor::visitCommand(ShellParser::CommandContext* context)
{
    std::shared_ptr<Statement> command = std::make_shared<Command>(context->COMMAND_TOKEN()->getText(), visitArguments(context->arguments()));
    return command;
}

antlrcpp::Any Visitor::visitPipe(ShellParser::PipeContext* context)
{
    std::shared_ptr<Statement> pipes;

    std::list<std::shared_ptr<Process>> processes;
    for (auto&& process_context : context->process()) {
        std::shared_ptr<Process> process = std::dynamic_pointer_cast<Process>(
            visitProcess(process_context).as<std::shared_ptr<Statement>>());
        processes.push_back(process);
    }

    pipes = std::make_shared<Pipe>(processes);
    return pipes;
}
