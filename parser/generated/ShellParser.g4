parser grammar ShellParser;

options { tokenVocab=ShellLexer; }

statement
    : assignment
    | exportEnv
    | runnable
    ;

assignment
    : VARIABLE_TOKEN EQUALS_TOKEN value
    ;

value
    : BACK_QOUTE_TOKEN runnable BACK_QOUTE_TOKEN | VARIABLE_VALUE_TOKEN | RETURN_TOKEN | CONSTANT_TOKEN
    ;

exportEnv
    : EXPORT_TOKEN (VARIABLE_TOKEN | assignment)
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