%{
#include <stdio.h>
#include <stdlib.h>
int flag = 0;
%}

%token NUMBER
%token IDENTIFIER
%left '+' '-'
%left '*' '/'

%%
ArithmeticExpression: E { printf("\nResult=%d\n", $$); return 0; }
E: E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E { $$ = $1 / $3; }
  | NUMBER { $$ = $1; }
  | IDENTIFIER { $$ = 1; }  // For identifiers, you can handle validation here
%%

void main() {
  printf("Enter the expression:\n");
  yyparse();
  if(flag == 0) {
    printf("Entered arithmetic expression is Valid\n");
  }
}

void yyerror() {
  printf("Entered arithmetic expression is Invalid\n");
  flag = 1;
}

