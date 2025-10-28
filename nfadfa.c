#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct Node {
int state;
struct Node* next;
} Node;

typedef struct {
int states[MAX];
} StateSet;

Node* transitions[MAX][MAX];// NFA transition table
StateSet dfaStates[MAX];
char alphabet[MAX];
int numStates, numAlpha, startState, finalStates[MAX], numFinal, numTransitions;
int dfaCount = 0;

int findAlphaIndex(char c) {
for (int i = 0; i < numAlpha; i++)
if (alphabet[i] == c) return i;
return -1;
}

void addTransition(int from, char symbol, int to) {
int alphaIndex = findAlphaIndex(symbol);
if (alphaIndex == -1) {
printf("Invalid symbol.\n");
exit(1);
}
Node* newNode = malloc(sizeof(Node));
newNode->state = to;
newNode->next = transitions[from][alphaIndex];
transitions[from][alphaIndex] = newNode;
}

int isEqual(StateSet a, StateSet b) {
return memcmp(a.states, b.states, sizeof(a.states)) == 0;
}

int addDFAState(StateSet state) {
for (int i = 0; i < dfaCount; i++)
if (isEqual(dfaStates[i], state)) return i;
dfaStates[dfaCount] = state;
return dfaCount++;
}

void printState(StateSet state) {
printf("{");
for (int i = 0; i < numStates; i++)
if (state.states[i]) printf("q%d,", i);
printf("}");
}

int isFinalState(StateSet s) {
for (int i = 0; i < numStates; i++)
if (s.states[i])
for (int j = 0; j < numFinal; j++)
if (i == finalStates[j]) return 1;
return 0;
}

int main() {
printf("Enter number of alphabets: ");
scanf("%d", &numAlpha);
printf("Enter alphabets: ");
for (int i = 0; i < numAlpha; i++) scanf(" %c", &alphabet[i]);

printf("Enter number of states: ");
scanf("%d", &numStates);

printf("Enter start state: ");
scanf("%d", &startState);

printf("Enter number of final states: ");
scanf("%d", &numFinal);
printf("Enter final states: ");
for (int i = 0; i < numFinal; i++) scanf("%d", &finalStates[i]);

printf("Enter number of transitions: ");
scanf("%d", &numTransitions);
printf("Enter transitions (from symbol to):\n");
for (int i = 0; i < numTransitions; i++) {
int from, to;
char symbol;
scanf("%d %c %d", &from, &symbol, &to);
addTransition(from, symbol, to);
}

// Initialize DFA
StateSet start = {0};
start.states[startState] = 1;
addDFAState(start);

printf("\nDFA Transitions:\n");
for (int i = 0; i < dfaCount; i++) {
for (int a = 0; a < numAlpha; a++) {
StateSet newSet = {0};
for (int s = 0; s < numStates; s++) {
if (dfaStates[i].states[s]) {
for (Node* p = transitions[s][a]; p; p = p->next)
newSet.states[p->state] = 1;
}
}
if (memcmp(newSet.states, (int[MAX]){0}, sizeof(newSet.states)) == 0) continue;
int index = addDFAState(newSet);
printState(dfaStates[i]);
printf(" --%c--> ", alphabet[a]);
printState(newSet);
printf("\n");
}
}

printf("\nDFA States:\n");
for (int i = 0; i < dfaCount; i++) printState(dfaStates[i]), printf("\n");

printf("\nStart State:\n");
printState(dfaStates[0]);
printf("\n");

printf("\nFinal States:\n");
for (int i = 0; i < dfaCount; i++)
if (isFinalState(dfaStates[i]))
printState(dfaStates[i]), printf("\n");

return 0;}

