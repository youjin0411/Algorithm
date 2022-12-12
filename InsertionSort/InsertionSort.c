#include<stdio.h>

void InsertionSort(int a[], int n) {
	int i, j, key;

	for (i = 1; i < n; i++) { //1~n까지인 이유: 삽입정렬은 2번째 값부터 비교를 시작하기 때문
		key = a[i]; //key에 a[i]로 처음에는 두 번째 값을 key자리에 넣어준다. 
		for (j = i - 1; j >= 0; j--) { //i-1부터 인 이유: key의 왼쪽 자리를 비교하기 위해서 사용 
			if (key >= a[j]) break; //key보다 a[j]가 작거나 같을 때는 멈춘다. 
			a[j + 1] = a[j]; //key값보다 a[j]가 클 때는 a[j+1] 자리에 a[j]값을 대입해준다. 
		}
		a[j + 1] = key;  //key값을 a[j+1]번자리에 넣어준 후 다시 처음 for문으로 돌아가 i=2부터 시작 
	}
}

int main(void) {
	int a[] = { 7,12,6,11,3,8,5,2 };
	int i, n = sizeof(a) / sizeof(int);

	printf("정렬 전 : ");
	for (i = 0; i < n; i++) printf("%d   ", a[i]);

	InsertionSort(a, n);

	printf("\n삽입정렬 후 : ");
	for (i = 0; i < n; i++) printf("%d    ", a[i]);

	return 0;
}