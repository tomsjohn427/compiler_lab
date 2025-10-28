
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char expr[100];
int tempCount = 1;

int findOperator(char op);
void getOperands(int pos, char *left, char *right, int *start, int *end);
void replaceWithTemp(int start, int end, char *temp);

int main() {
printf("Enter the expression: ");
scanf("%s", expr);

printf("The intermediate code:\n");
printf("\tExpression\n");

char ops[] = {'*', '/', '+', '-'};

for (int k = 0; k < 4; k++) {
while (1) {
int pos = findOperator(ops[k]);
if (pos == -1) break;

char left[20], right[20];
int start, end;
getOperands(pos, left, right, &start, &end);

char temp[10];
sprintf(temp, "T%d", tempCount++);

printf("It%s = %s %c %s\t\t%s\n", temp, left, expr[pos], right, expr);
replaceWithTemp(start, end, temp);
}
}

return 0;
}

// Find the first operator of given type
int findOperator(char op) {
for (int i = 0; expr[i] != '\0'; i++) {
if (expr[i] == op) return i;
}
return -1;
}

// Extract operands from around the operator
void getOperands(int pos, char *left, char *right, int *start, int *end) {
int i = pos - 1, l = 0;

// Extract left operand
while (i >= 0 && (isalnum(expr[i]) || expr[i] == '_')) {
left[l++] = expr[i--];
}
left[l] = '\0';

// Reverse left operand (we built it backwards)
for (int j = 0; j < l / 2; j++) {
char tmp = left[j];
left[j] = left[l - j - 1];
left[l - j - 1] = tmp;
}
*start = i + 1;
 i = pos + 1;
int r = 0;
while (expr[i] != '\0' && (isalnum(expr[i]) || expr[i] == '_')) {
right[r++] = expr[i++];
}
right[r] = '\0';

*end = i - 1;
}
void replaceWithTemp(int start, int end, char *temp) {
char newExpr[100] = "";
strncat(newExpr, expr, start);
strcat(newExpr, temp);
strcat(newExpr, &expr[end + 1]);
strcpy(expr, newExpr);
}



