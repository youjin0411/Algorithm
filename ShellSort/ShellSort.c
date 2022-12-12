#include<stdio.h>

void ShellSort(int a[], int n) {
	int i, j, t, key;

	for (t = n / 2; t >= 1; t /= 2) {
		for (i = t; i < n; i++) {
			key = a[i];
			for (j = i - t; j >= 0; j -= t) {
				if (key >= a[j]) break;
				else a[j + t] = a[j];
			}
			a[j + t] = key;
		}
	}
}
int main(void) {
	int a[] = { 7,12,6,11,3,8,5,2 };
	int i, n = sizeof(a) / sizeof(int);

	printf("정렬 전 : ");
	for (i = 0; i < n; i++) printf("%d   ", a[i]);

	ShellSort(a, n);

	printf("\n삽입정렬 후 : ");
	for (i = 0; i < n; i++) printf("%d    ", a[i]);

	return 0;
}