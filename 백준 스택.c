#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	int num;
	struct node* link;
} node;

typedef struct StackType {
	node* top;
} StackType;
void init(StackType *s) {
	s->top = NULL;
}
void push(int data,StackType* s) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->num = data;
	tmp->link = s->top;
	s->top = tmp;
}
int empty(StackType* s) {
	if (s->top == NULL)
		return 1;
	else
		return 0;
}
void pop(StackType *s) {
	if (empty(s)) {
		printf("-1\n");
		return;
	}
	node* tmp = s->top;
	s->top = s->top->link;
	printf("%d\n", tmp->num);
	free(tmp);
}
void size(StackType *s) {
	node* tmp;
	int size = 0;
	for (tmp = s->top; tmp != NULL; tmp = tmp->link) {
		size++;
	}
	printf("%d\n", size);
}
void top(StackType *s) {
	if (empty(s)) {
		printf("-1\n");
		return;
	}
	printf("%d\n", s->top->num);
}

int main(void) {
	int n;
	char s[MAX];
	StackType stack;
	init(&stack);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &s);
		if (!strcmp(s, "push")) {
			int num;
			scanf("%d", &num);
			push(num, &stack);
		}
		else if (!strcmp(s, "pop"))
			pop(&stack);
		else if (!strcmp(s, "size"))
			size(&stack);
		else if (!strcmp(s, "empty"))
			printf("%d\n",empty(&stack));
		else if (!strcmp(s, "top"))
			top(&stack);
	}

	return 0;
}