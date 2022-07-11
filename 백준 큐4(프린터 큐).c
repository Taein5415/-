#define _CRT_SECURE_NO_WARNINGS
#define MAX 101
#include <stdio.h>

typedef struct file{
	int n;
	int priority;
}file;

int max;
int head, rear;
file queue[MAX];
void push(file data) {
	rear = (rear + 1) % MAX ;
	queue[rear] = data;
}

file pop() {
	head = (head + 1) % MAX ;
	return queue[head];
}

int main(void) {
	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		int turn;
		int count = 0;
		head = 0; rear = 0;
		
		scanf("%d %d", &max, &turn);

		for (int j = 0; j < max; j++) {
			file tmp = { j };
			scanf("%d", &tmp.priority);
			push(tmp);
		}
		while (1) {
			int i = head;
			for (; i != rear; i = (i + 1) % MAX) {
				if (queue[(head+1)%MAX].priority < queue[i+1].priority) {
					push(pop(&queue));
					break;
				}
			}//end of for
			if (i == rear) {
				file output = pop(&queue);
				count++;
				if (output.n == turn) {
					printf("%d\n", count);
					break;
				}
			}
		}
	}//end of for

	return 0;
}