
// Generated from ShellParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "ShellParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ShellParser.
 */
class  ShellParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ShellParser.
   */
    virtual antlrcpp::Any visitStatement(ShellParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(ShellParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitValue(ShellParser::ValueContext *context) = 0;

    virtual antlrcpp::Any visitExportEnv(ShellParser::ExportEnvContext *context) = 0;

    virtual antlrcpp::Any visitRunnable(ShellParser::RunnableContext *context) = 0;

    virtual antlrcpp::Any visitArguments(ShellParser::ArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitProcess(ShellParser::ProcessContext *context) = 0;

    virtual antlrcpp::Any visitCommand(ShellParser::CommandContext *context) = 0;

    virtual antlrcpp::Any visitPipe(ShellParser::PipeContext *context) = 0;


};

