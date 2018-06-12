%{
#include "parser.tab.h"
#include <string.h>
%}

%%
"|" 	|
"`" 	|
"<"	|
">"	|
"\n"	|
"="	|
"$"			{ return yytext[0]; }

"cd"	|
"ls" 	|
"pwd"	|
"exit"	|
"echo"			{ yylval.s = strdup(yytext); return COMMAND; }

"export"		{ return EXPORT; }

[a-zA-Z][a-zA-Z0-9]*	{ yylval.s = strdup(yytext); return VARIABLE_ID; }

L?\"(\\.|[^\\"])*\"	{ yylval.s = strdup(yytext); return STRING_VALUE; }
[1-9][0-9]*|0			{ yylval.s = strdup(yytext); return INT_VALUE; }
([1-9][0-9]*|0)"."[0-9]+	{ yylval.s = strdup(yytext); return FLOAT_VALUE; }

"./"[a-zA-Z][a-zA-Z0-9]*		{ yylval.s = strdup(yytext); return EXECUTE; }

.			{ }

%%

