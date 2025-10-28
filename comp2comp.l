%{
#include <stdio.h>
int i;
%}
%%
[a-zA-Z]* {for(i=0;i<=yyleng;i++){
if((yytext[i]=='c')&&(yytext[i+1]=='o')&&(yytext[i+2]=='m')&&(yytext[i+3]=='p'))
{
yytext[i]='C';
yytext[i+1]='O';
yytext[i+2]='M';
yytext[i+3]='P';
}
}
printf("%s",yytext);
}
%%
int yywrap(){
return 1;
}
int main()
{
printf("enter the string");
yylex();
}
