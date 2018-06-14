#include <ANTLRInputStream.h>
#include "Parser.h"
#include "generated/ShellLexer.h"
#include "generated/ShellParser.h"
#include "generated/ShellParserVisitor.h"
#include "Visitor.h"
#include "ErrorListener.h"

std::shared_ptr<Statement> Parser::parse(std::string line)
{
    ErrorListener errorListener;

    antlr4::ANTLRInputStream input(line);
    ShellLexer lexer(&input);
    lexer.removeErrorListeners();
    lexer.addErrorListener(&errorListener);

    antlr4::CommonTokenStream tokens(&lexer);
    ShellParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);

    Visitor visitor;
    return visitor.visitStatement(parser.statement()).as<std::shared_ptr<Statement>>();
}
