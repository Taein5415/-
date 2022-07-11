#define _CRT_SECURE_NO_WARNINGS
#define MAX 100001
#include <stdio.h>
#include <string.h>

int deq[MAX];
int head = 0; int rear = 0;

int is_full() {
	if (((rear + 1) % MAX) == head)
		return 1;
	return 0;
}

int empty() {
	if (rear == head)
		return 1;
	else
		return 0;
}

void push_front(int data) {
	if (is_full()) {
		printf("덱이 차있습니다.\n");
		return;;
	}
	deq[head] = data;
	head = (head + MAX - 1) % MAX;
}

void push_back(int data) {
	if (is_full()) {
		printf("덱이 차있습니다.\n");
		return;;
	}
	rear = (rear + 1) % MAX;
	deq[rear] = data;
}

int pop_front() {
	if (empty())
		return -1;
	head = (head + 1) % MAX;
	return deq[head];
}

int pop_back() {
	if (empty())
		return -1;
	int temp = deq[rear];
	rear = (rear + MAX - 1) % MAX;
	return temp;
}
int size() {
	return ((rear - head+MAX) % MAX);
}

int front() {
	if (empty())
		return -1;
	return deq[(head+1)%MAX];
}

int back() {
	if (empty())
		return -1;
	return deq[rear];
}


int main(void) {
	int n;
	char input[20];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &input);

		if (strcmp(input, "push_front") == 0) {
			int num;
			scanf("%d", &num);
			push_front(num);
		}
		else if (strcmp(input, "push_back") == 0) {
			int num;
			scanf("%d", &num);
			push_back(num);
		}
		else if (strcmp(input, "pop_front")==0)
			printf("%d\n", pop_front());
		else if (strcmp(input, "pop_back")==0)
			printf("%d\n", pop_back());
		else if (strcmp(input, "size")==0)
			printf("%d\n", size());
		else if (strcmp(input, "empty")==0)
			printf("%d\n", empty());
		else if (strcmp(input, "front")==0)
			printf("%d\n", front());
		else if (strcmp(input, "back")==0)
			printf("%d\n", back());
	}
	return 0;
}