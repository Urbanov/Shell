#include <IntStream.h>
#include <Recognizer.h>
#include "ErrorListener.h"

void ErrorListener::syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line,
                                size_t charPositionInLine, const std::string& msg, std::exception_ptr e)
{
    throw std::runtime_error("Syntax error in line " + std::to_string(line) + ":" + std::to_string(charPositionInLine));
}
