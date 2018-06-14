#ifndef SHELL_VISITOR_H
#define SHELL_VISITOR_H


#include "generated/ShellParserVisitor.h"

class Visitor : public ShellParserVisitor {
public:
    antlrcpp::Any visitStatement(ShellParser::StatementContext* context) override;

    antlrcpp::Any visitAssignment(ShellParser::AssignmentContext* context) override;

    antlrcpp::Any visitValue(ShellParser::ValueContext* context) override;

    antlrcpp::Any visitRunnable(ShellParser::RunnableContext* context) override;

    antlrcpp::Any visitArguments(ShellParser::ArgumentsContext* context) override;

    antlrcpp::Any visitProcess(ShellParser::ProcessContext* context) override;

    antlrcpp::Any visitCommand(ShellParser::CommandContext* context) override;

    antlrcpp::Any visitPipe(ShellParser::PipeContext* context) override;

};


#endif //SHELL_VISITOR_H
