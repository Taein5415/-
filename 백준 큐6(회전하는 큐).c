#define _CRT_SECURE_NO_WARNINGS
#define MAX 51
#include <stdio.h>
#include <string.h>
#include <math.h>
int queue[MAX];
int front = 0; int rear = 0;
int num[MAX - 1];
int count=0;
int is_empty() {
	if (front == rear)
		return 1;
	return 0;
}

int is_full() {
	if (((rear + 1) % MAX) == front)
		return 1;
	return 0;
}

void push_rear(int data) {
	if (is_full()) {
		printf("큐가 포화상태입니다.\n");
		return;
	}
	rear = (rear + 1) % MAX;
	queue[rear] = data;
}

void push_front(int data) {
	if (is_full()) {
		printf("큐가 포화상태입니다.\n");
		return;
	}
	queue[front] = data;
	front = (front - 1 + MAX) % MAX;
}
int pop_front() {
	if (is_empty()) {
		printf("큐가 비어상태입니다.\n");
		return -1;
	}
	front = (front + 1) % MAX;
	return queue[front];
}
int pop_rear() {
	if (is_empty()) {
		printf("큐가 비어상태입니다.\n");
		return -1;
	}
	int temp = queue[rear];
	rear = (rear - 1 + MAX) % MAX;
	return temp;
}
int peek() {
	if (is_empty()) {
		return -1;
	}
	return queue[(front + 1) % MAX];
}

void turn(int n) {
	int i;
	int cnt = 0;
	for (i = front + 1; i != rear; i = (i + 1) % MAX) {
		if (queue[i] == n)
			break;
		cnt++;
	}
	if (cnt < (rear-i+MAX+1)%MAX) {
		while (queue[(front+1)%MAX] != n) {
			push_rear(pop_front());
			count++;
		}
	}
	else{
		while ((queue[(front+1)%MAX] != n)) {
			push_front(pop_rear());
			count++;
		}
	}
}
int main(void) {
	int N, M;               //N: 큐의 크기, M: 뽑아내려고 하는 수의 개수 
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		push_rear(i + 1);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < M; i++) {
		turn(num[i]);
		pop_front();
	
	}
	printf("%d", count);
	return 0;
}