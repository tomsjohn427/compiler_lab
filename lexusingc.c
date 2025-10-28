#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_TOKEN_LEN 100
const char *keywords[] = {"if", "else", "while", "return"};
const int keywords_count = 4;
int is_keyword(const char *str) {
for (int i = 0; i < keywords_count; i++) 
{
if (strcmp(str, keywords[i]) == 0)
return 1;
}
return 0;
}
void lexical_analyzer(const char *source) {
int i = 0;
int len = strlen(source);
char token[MAX_TOKEN_LEN];
int token_index;
while (i < len) { 
if (isspace(source[i])) {
i++;
continue;
}
if (isalpha(source[i]) || source[i] == '_') {
token_index = 0;
while (i < len && (isalnum(source[i]) || source[i] == '_')) {
token[token_index++] = source[i++];
}
token[token_index] = '\0';
if (is_keyword(token))
printf("KEYWORD\t\t%s\n", token);
else
printf("IDENTIFIER\t%s\n", token);
continue;
}
if (isdigit(source[i])) {
token_index = 0;
while (i < len && isdigit(source[i])) {
token[token_index++] = source[i++];
}
token[token_index] = '\0';
printf("NUMBER\t\t%s\n", token);
continue;
} 
if (source[i] == '=' || source[i] == '!' || source[i] == '<' || source[i] == '>') {
if (i + 1 < len && source[i + 1] == '=') {
printf("OPERATOR\t%c%c\n", source[i], source[i + 1]);
i += 2;
} else {
printf("OPERATOR\t%c\n", source[i]);
i++;
}
continue;
}
switch (source[i]) {
case '+': case '-': case '*': case '/':
printf("OPERATOR\t%c\n", source[i]);
i++;
break;
case ';': case ',': case '(': case ')': case '{': case '}':
printf("DELIMITER\t%c\n", source[i]);
i++;
break;
default:
printf("UNKNOWN\t\t%c\n", source[i]);
i++;
break;
}
}
}
int main() {
char input[1000];
printf("Enter a line of code:\n");
fgets(input, sizeof(input), stdin);
lexical_analyzer(input);
return 0;
}
