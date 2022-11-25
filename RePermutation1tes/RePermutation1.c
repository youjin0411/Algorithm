#include<stdio.h>
#define R 3

int b[R] = { 0, };
int cnt = 0; 

void RePerPrint() {
	int i;
	for (i = 0; i < R; i++) printf("%d ", b[i]);
	printf("\n");
}

void RePermutation1(int a[], int n, int r) {
	int i; 

	if (r == R) RePerPrint();
	else for (i = 0; i < n; i++) {
		b[r] = a[i];
		RePermutation1(a, n, r + 1);
	}
}

int main(void) {
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(int);

	RePermutation1(a, n, 0);
	
	return 0;
}