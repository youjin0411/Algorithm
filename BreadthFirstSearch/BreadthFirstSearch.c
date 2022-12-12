#include<stdio.h>
#define 7

int rear = -1, front = 0;
int queue[SIZE];

void add(int item) {
	if (rear >= SIZE) {
		printf("Queue is Full!\n");
		return;  //함수 종료
	}
	queue[++rear] = item;
}

int del(void) {
	if (front > rear) return -1;
	return queue[front++];
}

void BreadthFirstSearch(char v[], int a[][SIZE]) {
	int searchOk[SIZE] = { 0, };
	int i, j;
	char ch;

	printf("\n시작 정점(A~G 중 입력 ): ");
	scanf_s("%c", &ch, 1);

	for (i = 0; i < SIZE; i++) if (ch == v[i]) break;
	printf("\n너비우선탐색 순서 : %c", v[i]);
	searchOk[i] = 1; 
	do {
		for (j = 0; j < SIZE; j++) {
			if (a[i][j] == 1 && searchOk[j] == 0) {
				printf("-> %c", v[j]);
				add(j);
				searchOk[j] = 1;
			}
		}
		i = del();
	} while (i > = 0);
	printf("\n\n")
}