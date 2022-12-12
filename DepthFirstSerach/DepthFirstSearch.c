#include<stdio.h>
#define SIZE 8

int stack[SIZE] = { 0, };
int top = -1;

typedef enum {false, true} bool;

bool push(int index) {
	if (top == SIZE) return false;
	stack[++top] = index;
	return true;
}

int pop() {
	if (top == -1) return -1;
	return stack[top--];
}

void DepthFirstSearch(char v[], bool a[][SIZE]) {
	bool searchOk[SIZE] = { false, };
	int i, j;
	char vertex;

	printf("\n시작 정점(A~G 중 입력) : ");
	scanf_s("%c", &vertex, 1);

	for (i = 0; i < SIZE; i++) if (vertex == v[i]) break;
	searchOk[i] = true;

	printf("\n깊이우선탐색 순서 : %c", v[i]);
	do {
		for (j = 0; j < SIZE; j++){
			if (a[i][j] == 1 && searchOk[j] == false) {
				printf("-> %c", v[i]);
				push(i);
				searchOk[j] = true;
				i = j
				break;
			}
		}
		if (j >= SIZE) i = pop();
	} while (i >= 0);
}