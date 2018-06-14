lexer grammar ShellLexer;

WHITESPACE
    : [ \t\r\n]+ -> skip
    ;

COMMAND_TOKEN
    : 'cd' | 'pwd' | 'ls' | 'echo' | 'exit' | 'export'
    ;

VARIABLE_TOKEN
    : [a-zA-Z] ([a-zA-Z0-9])*
    ;

PATH_TOKEN
    : [-_.a-zA-Z0-9]* '/' [-_.a-zA-Z0-9/]+
    ;

QUOTE_STRING_TOKEN
    : '\'' .*? '\''
    ;

PIPE_TOKEN
    : '|'
    ;

BACK_QUOTE_TOKEN
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
    : '<' [-_.a-zA-Z0-9/]+
    ;

OUTPUT_REDIRECTION_TOKEN
    : '>' [-_.a-zA-Z0-9/]+
    ;

CONSTANT_TOKEN
    : [-_.a-zA-Z0-9/]+
    ;
