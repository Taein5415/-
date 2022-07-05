#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int num;
	struct node* link;
}node;

typedef struct QueueType{
	node* head;
	node* tail;
}QueueType;

void init(QueueType *q) {
	q->head = NULL;
	q->tail = NULL;
}

void push(int data, QueueType* q) {
	node* temp = (node*)malloc(sizeof(node));
	temp->num = data;
	temp->link = NULL;
	if (q->head == NULL) {
		q->head = q->tail = temp;
	}
	else {
		q->tail->link = temp;
		q->tail = temp;
	}
}

void pop(QueueType *q) {
	if (q->head == NULL) {
		printf("-1\n");
		return;
	}
	node* temp = q->head;
	printf("%d\n", q->head->num);
	q->head = q->head->link;
	free(temp);
}

void size(QueueType* q) {
	int size = 0;
	for (node* temp = q->head; temp != NULL; temp = temp->link) {
		size++;
	}
	printf("%d\n", size);
}

void empty(QueueType* q) {
	if (q->head == NULL) 
		printf("1\n");
	else
		printf("0\n");
}

void front(QueueType* q) {
	if (q->head == NULL) {
		printf("-1\n");
		return;
	}
	printf("%d\n", q->head->num);
}

void back(QueueType *q) {
	if (q->tail == NULL) {
		printf("-1\n");
		return;
	}
	printf("%d\n", q->tail->num);
}

int main(void) {
	int n;
	QueueType queue;
	init(&queue);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char s[10];
		scanf("%s", &s);
		if (!strcmp(s, "push")) {
			int num;
			scanf("%d", &num);
			push(num, &queue);
		}
		else if (!strcmp(s, "pop"))
			pop(&queue);
		else if (!strcmp(s, "size"))
			size(&queue);
		else if (!strcmp(s, "empty"))
			empty(&queue);
		else if (!strcmp(s, "front"))
			front(&queue);
		else if (!strcmp(s, "back"))
			back(&queue);
	}
	return 0;
}