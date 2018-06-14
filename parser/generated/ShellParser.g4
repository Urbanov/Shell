parser grammar ShellParser;

options { tokenVocab=ShellLexer; }

statement
    : assignment
    | runnable
    ;

assignment
    : VARIABLE_TOKEN EQUALS_TOKEN value
    ;

value
    : BACK_QUOTE_TOKEN runnable BACK_QUOTE_TOKEN | VARIABLE_VALUE_TOKEN | RETURN_TOKEN | PATH_TOKEN | VARIABLE_TOKEN | QUOTE_STRING_TOKEN | CONSTANT_TOKEN
    ;

runnable
    : process
    | command
    | pipe
    ;

arguments
    : value*
    ;

process
    : PATH_TOKEN arguments INPUT_REDIRECTION_TOKEN? OUTPUT_REDIRECTION_TOKEN?
    ;

command
    : COMMAND_TOKEN arguments
    ;

pipe
    : process (PIPE_TOKEN process)+
    ;