%{ 
#include<stdio.h> 
int v=0,c=0; 
%} 
%% 
[ \t\n]+ ; 
[aeiouAEIOU] {v++;} 
[^aeiouAEIOU] {c++;} 
%% 
int yywrap() 
{ 
return 1; 
} 
int main() 
{ 
printf("enter the input string\n"); 
yylex(); 
printf("no of vowels =%d \n no of consonants =%d\n",v,c); } 

