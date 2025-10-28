%{
#include <stdio.h>
float prev=0, m=0, x, op=1;
%}
%%
[0-9]+ {
m=1;
x=atoi(yytext);
if(op==1)
prev=prev+x;
else if(op==2)
prev=prev-x;
else if(op==3)
prev=prev*x;
else if(op==4)
prev=prev/x;
}
"+" {op=1;}
"-" {op=2;}
"*" {op=3;}
"/" {op=4;}
"\n" {if(m!=0)
printf("result=%f \n", prev);}
%%
int main()
{
printf("enter input\n");
yylex();
return 0;
}
int yywrap()
{
return 1;
}

