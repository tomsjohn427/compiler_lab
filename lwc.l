%{
#include<stdio.h>
int lc=0, sc=0, wc=0, cc=0;
%}
%%
[\n] {lc++; cc+=yyleng;} 
[ ] {sc++; cc+=yyleng;}
[\t] {sc++; cc+=yyleng;} 
[a-zA-Z0-9]+ {wc++; cc+=yyleng;}
%%
int main()
{
printf("Enter the input \n");
yylex();
printf("no:of words are: %d \n", wc);
printf("no:of characters are: %d \n", cc);
printf("no:of new lines are: %d \n", lc);
printf("no:of spaces are: %d \n", sc); 
}
int yywrap() 
{
return 1;
}
