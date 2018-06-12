#include "Shell.h"
extern "C"
{
#include "parser.tab.h"
}


int main()
{
    yyparse();
    Shell sh;
    return sh.run();
}

