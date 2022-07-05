#define _CRT_SECURE_NO_WARNINGS
#define MAX 100000
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node* link;
}node;

typedef struct {
	node* top;
} StackType;

void init(StackType* s) {
	s->top = NULL;
}
void push(StackType* s, int data) {
	node* temp = (node*)malloc(sizeof(node));
	temp->num = data;
	temp->link = s->top;
	s->top = temp;
}
void pop(StackType* s) {
	if (s->top == NULL) {
		printf("스택이 비어있습니다.");
		exit(0);
	}
	node* temp = s->top;
	s->top = s->top->link;
	free(temp);
}

int sum(StackType* s) {
	if (s->top == NULL)
		return 0;
	int sum = 0;
	for (node* temp = s->top; temp != NULL; temp = temp->link) {
		sum += temp->num;
	}
	return sum;
}
int main(void) {
	int n;
	StackType stack;
	init(&stack);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		if (num == 0)
			pop(&stack);
		else
			push(&stack, num);
	}
	printf("%d", sum(&stack));
	return 0;
}