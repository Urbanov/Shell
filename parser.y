%{
#include <stdlib.h>
extern int yylex();
extern int yyparse();
void yyerror(const char *s);
%}

%union {
    char* s;
}

%token VARIABLE_ID COMMAND STRING_VALUE INT_VALUE FLOAT_VALUE EXECUTE EXPORT

%start line

%%


line
: line statement '\n'
| statement '\n'
| error '\n' { yyerrok; }
;
statement
: assignment
| export
| variable_value
| executable
| command
;
assignment
: VARIABLE_ID '=' result
;
result
: VARIABLE_ID
| '`' executable '`'
| constant
;
constant
: STRING_VALUE
| INT_VALUE
| FLOAT_VALUE
;
export
: EXPORT VARIABLE_ID
;
executable
: executable '|' process
| process
;
process
: EXECUTE arguments in_redirection out_redirection
;
arguments
:
| arguments argument
;
argument
: VARIABLE_ID
| constant
;
in_redirection
:
| '<' file
;
out_redirection
:
| '>' file
;
file
: VARIABLE_ID
;
command
: COMMAND
;
variable_value
: '$' VARIABLE_ID
;

%%

#include <stdio.h>

extern char yytext[];

void yyerror(const char* s)
{
    fprintf(stderr, "Wrong command line: %s\n", s);
}

int main()
{
    yyparse();
}
