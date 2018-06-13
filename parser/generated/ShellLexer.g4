lexer grammar ShellLexer;

WHITESPACE
    : [ \t\r\n]+ -> skip
    ;

COMMAND_TOKEN
    : ('cd' | 'pwd' | 'ls' | 'echo' | 'exit') -> pushMode(ARGUMENTS)
    ;

EXPORT_TOKEN
    : 'export'
    ;

VARIABLE_TOKEN
    : [_a-zA-Z] ([_a-zA-Z0-9])* -> pushMode(ARGUMENTS)
    ;

PATH_TOKEN
    : (QUOTE_STRING_TOKEN
    | ~[ \t\r\n"'`]* '/' ~[ \t\r\n"'`]+) -> pushMode(ARGUMENTS)
    ;

mode ARGUMENTS;
QUOTE_STRING_TOKEN
    : '\'' .*? '\''
    ;

ARGUMENTS_WHITESPACE
    : [ \t\r\n]+ -> skip
    ;

PIPE_TOKEN
    : '|'
    ;

BACK_QOUTE_TOKEN
    : '`'
    ;

EQUALS_TOKEN
    : '='
    ;

VARIABLE_VALUE_TOKEN
    : '$' VARIABLE_TOKEN
    ;

RETURN_TOKEN
    : '$?'
    ;

INPUT_REDIRECTION_TOKEN
    : '<' QUOTE_STRING_TOKEN
    | '<' ~[ \t\r\n"'`=<>]+
    ;

OUTPUT_REDIRECTION_TOKEN
    : '>' QUOTE_STRING_TOKEN
    | '>' ~[ \t\r\n"'`=<>]+
    ;

CONSTANT_TOKEN
    : QUOTE_STRING_TOKEN
    | ~[ \t\r\n"'`=<>]+
    ;
