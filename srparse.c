#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

char ip_sym[MAX_LEN], stack[MAX_LEN];
int ip_ptr = 0, st_ptr = 0, len;
char act[30];
void check();

int main() {
printf("SHIFT-REDUCE PARSER\n");
printf("GRAMMAR:\n");
printf("E -> E+E\n");
printf("E -> E-E\n");
printf("E -> E*E\n");
printf("E -> E/E\n");
printf("E -> a\n");
printf("E -> b\n");
printf("Enter the input symbol: ");
fgets(ip_sym, MAX_LEN, stdin);
ip_sym[strcspn(ip_sym, "\n")] = '\0'; // remove newline if any
len = strlen(ip_sym);
printf("\nStack Implementation Table\n");
printf("Stack\t\tInput Symbol\t\tAction\n");
printf("_____\t\t______________\t\t_______\n");
printf("$\t\t%s$\t\t\t--\n", ip_sym);
while (ip_ptr < len) {
stack[st_ptr++] = ip_sym[ip_ptr++];
stack[st_ptr] = '\0';

sprintf(act, "shift %c", stack[st_ptr - 1]);
printf("$%s\t\t%s$\t\t\t%s\n", stack, ip_sym + ip_ptr, act);

check();
}
check();
if (strcmp(stack, "E") == 0 && ip_ptr == len) {
printf("$%s\t\t%s$\t\t\tAccepted\n", stack, ip_sym + ip_ptr);
} else {
printf("$%s\t\t%s$\t\t\tRejected\n", stack, ip_sym + ip_ptr);
}
return 0;
}
void check() {
int reduced;
do {
reduced = 0;
if (st_ptr >= 3 &&
stack[st_ptr - 3] == 'E' &&
stack[st_ptr - 2] == '+' &&
stack[st_ptr - 1] == 'E') {
strcpy(&stack[st_ptr - 3], "E");
st_ptr -= 2;
stack[st_ptr] = '\0';
strcpy(act, "reduce E -> E+E");
printf("$%s\t\t%s$\t\t\t%s\n", stack, ip_sym + ip_ptr, act);
reduced = 1;
}
else if (st_ptr >= 3 &&
 stack[st_ptr - 3] == 'E' &&
 stack[st_ptr - 2] == '-' &&
 stack[st_ptr - 1] == 'E') {
strcpy(&stack[st_ptr - 3], "E");
st_ptr -= 2;
stack[st_ptr] = '\0';
strcpy(act, "reduce E -> E-E");
printf("$%s\t\t%s$\t\t\t%s\n", stack, ip_sym + ip_ptr, act);
reduced = 1;
}
else if (st_ptr >= 3 &&
 stack[st_ptr - 3] == 'E' &&
 stack[st_ptr - 2] == '*' &&
 stack[st_ptr - 1] == 'E') {
strcpy(&stack[st_ptr - 3], "E");
st_ptr -= 2;
stack[st_ptr] = '\0';
strcpy(act, "reduce E -> E*E");
printf("$%s\t\t%s$\t\t\t%s\n", stack, ip_sym + ip_ptr, act);
reduced = 1;
}
else if (st_ptr >= 3 &&
 stack[st_ptr - 3] == 'E' &&
 stack[st_ptr - 2] == '/' &&
 stack[st_ptr - 1] == 'E') {
strcpy(&stack[st_ptr - 3], "E");
st_ptr -= 2;
stack[st_ptr] = '\0';
strcpy(act, "reduce E -> E/E");
printf("$%s\t\t%s$\t\t\t%s\n", stack, ip_sym + ip_ptr, act);
reduced = 1;
}
else if (st_ptr >= 1 && stack[st_ptr - 1] == 'a') {
stack[st_ptr - 1] = 'E';
strcpy(act, "reduce E -> a");
printf("$%s\t\t%s$\t\t\t%s\n", stack, ip_sym + ip_ptr, act);
reduced = 1;
}

else if (st_ptr >= 1 && stack[st_ptr - 1] == 'b') {
stack[st_ptr - 1] = 'E';
strcpy(act, "reduce E -> b");
printf("$%s\t\t%s$\t\t\t%s\n", stack, ip_sym + ip_ptr, act);
reduced = 1;
}
} while (reduced);}

