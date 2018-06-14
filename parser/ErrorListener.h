#ifndef SHELL_ERRORLISTENER_H
#define SHELL_ERRORLISTENER_H


#include <BaseErrorListener.h>

class ErrorListener : public antlr4::BaseErrorListener {
    void
    syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line, size_t charPositionInLine,
                const std::string& msg, std::exception_ptr e) override;
};


#endif //SHELL_ERRORLISTENER_H
