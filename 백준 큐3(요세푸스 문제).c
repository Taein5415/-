#define _CRT_SECURE_NO_WARNINGS
#define MAX 1001
#include <stdio.h>
#include <stdlib.h>

int queue[MAX];
int front = 0, rear = 0;
int N, K;

void push(int data) {
	rear = (rear + 1) % (N+1);
	queue[rear] = data;
}

int pop() {
	front = (front + 1) % (N+1);
	return queue[front];
}
int main(void) {
	int cnt = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		push(i + 1);
	}
	printf("<");
	while (front != rear) {
		for (int i = 0; i < K-1; i++) {
			push(pop());
		}
		cnt++;
		if (cnt == N)
			printf("%d>", pop());
		else
			printf("%d, ",pop());
	}

	return 0;
}