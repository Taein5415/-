#define _CRT_SECURE_NO_WARNINGS
#define MAX 500000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int num;
	struct node* link;
}node;

typedef struct {
	node* head;
	node* tail;
}QueueType;

void init(QueueType* q) {
	q->head = q->tail = NULL;
}

void push(QueueType *q,int data) {
	node* temp = (node*)malloc(sizeof(node));
	temp->num = data;
	temp->link = NULL;
	if (q->head == NULL) {
		q->head = q->tail = temp;
		return;
	}
	q->tail->link = temp;
	q->tail = temp;
}

int pop(QueueType *q) {
	node* temp = q->head;
	int n = temp->num;
	q->head = q->head->link;
	free(temp);

	return n;
}


int main(void) {
	QueueType queue;
	int n;
	init(&queue);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		push(&queue, i + 1);
	}
	while (queue.head != queue.tail) {
		pop(&queue);
		push(&queue, pop(&queue));
	}
	printf("%d\n", pop(&queue));
	return 0;
}