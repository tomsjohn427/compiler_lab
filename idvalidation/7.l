%{
#include "y.tab.h"
%}

%%
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
[ \t] ;
\n { return 0; }
"+" { return '+'; }
"-" { return '-'; }
"*" { return '*'; }
"/" { return '/'; }
[a-zA-Z_][a-zA-Z0-9_]* { return IDENTIFIER; }

%%

int yywrap() {
return 1;
}

