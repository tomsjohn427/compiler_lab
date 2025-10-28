%{#include<stdio.h>
#include<string.h>
%}
keyword if|then|else|while|do
arith["+","-","*","/"]
assign["="]
rel["">","<""]
num[0-9]+
paren["(",")"]
id[A-Za-z][A-Za-z0-9]*
%%
{keyword} {printf("keyword:%s\n",yytext);}
{id} {printf("identifier:%s\n",yytext);}
{num} {printf("number:%s\n",yytext);}
{arith} {printf("Arithmetic op:%s\n",yytext);}
{rel} {printf("relational op:%s\n",yytext);}
{paren} {printf("parenthesis:%s\n",yytext);}
{assign} {printf("Assignment op:%s\n",yytext);}
%%
int yywrap() {return 1;
}
int main() {
FILE *file=fopen("input.txt","r");
if(!file){
perror("unable to open file");
exit(EXIT_FAILURE);}
printf("enter the string");
yyin=file;
yylex();
fclose(file);
return 0;
}
