#include <stdio.h>
#define R 3

int b[R];

void RePerint(void) {
	int i;
	for (i = 0; i < R; i++) {
		printf("%5d", b[i]);
	}
	printf("\n");
}
void exchange(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void RePermutation(int a[], int n, int r) {
	int i;
	if (r == R)RePerint();
	else for (i = 0; i < n; i++) {
		exchange(a + 0, a + i);
		b[r] = a[0];
		RePermutation(a, n, r + 1);
		exchange(a + 0, a + i);
	}
}

int main(void) {
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(int);

	RePermutation(a, n, 0);

	return 0;
}