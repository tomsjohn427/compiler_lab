%{
#include<stdio.h>
int flag=0;
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
ArithmeticExpression: E{
printf("\nResult=%d\n",$$);
return 0;
};
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|E'%'E {$$=$1%$3;}
|'('E')'E {$$=$2;}
|NUMBER {$$=$1;}
;
%%
void main()
{
 printf("\n Enter Arithmetic Expression \n");
 yyparse();
 if(flag==0)
 printf("Entered Arithmetic Expression is valid\n\n");
}
 void yyerror()
{
 printf("\nEntered arithmetic expression is invalid\n\n");
 flag=1;
}
