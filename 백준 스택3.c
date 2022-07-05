#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char c;
	struct node* link;
}node;

typedef struct {
	node* top;
}StackType;

void init(StackType* s) {
	s->top = NULL;
}

void push(StackType* s, char data) {
	node* temp = (node*)malloc(sizeof(node));
	temp->c = data;
	temp->link = s->top;
	s->top = temp;
}

char pop(StackType* s) {
	if (s->top == NULL) {
		return -1;
	}
	node* temp = s->top;
	char output = temp->c;
	s->top = s->top->link;
	free(temp);
	return output;
}
char peek(StackType* s) {
	if (s->top == NULL)
		return -1;
	return s->top->c;
}
void freeAll(StackType *s){
	for (node* temp = s->top; temp != NULL;temp = s->top) {
		s->top = s->top->link;
		free(temp);
	}
}
int main(void) {
	int n;
	StackType stack;
	init(&stack);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char s[MAX];
		scanf("%s", s);
		int j = 0;
		while (s[j]!='\0') {
			if (s[j] == '(')
				push(&stack, '(');
			else {
				if (peek(&stack) == -1) {
					break;
				}
				pop(&stack);
			}
			j++;
		}//end of while
		if ((pop(&stack) != -1)||(s[j]!='\0'))
			printf("NO\n");
		else
			printf("YES\n");
	}//end of for

	return 0;
}