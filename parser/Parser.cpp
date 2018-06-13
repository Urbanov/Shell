#include <ANTLRInputStream.h>
#include "Parser.h"
#include "generated/ShellLexer.h"
#include "generated/ShellParser.h"
#include "generated/ShellParserVisitor.h"
#include "Visitor.h"

std::shared_ptr<Statement> Parser::parse(std::string line)
{
    antlr4::ANTLRInputStream input(line);
    ShellLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    ShellParser parser(&tokens);

    Visitor visitor;
    return visitor.visitStatement(parser.statement()).as<std::shared_ptr<Statement>>();
}
