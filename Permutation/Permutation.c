#include <stdio.h>
#define R 3

int b[R];
int cnt = 0;

void Perint(void) {
	int i;
	for (i = 0; i < R; i++) {
		printf("%5d", b[i]);
	}
	printf("\n");
	cnt++;
}
void exchange(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Permutation(int a[], int n, int r) {
	int i;
	if (r == R) Perint();
	else for (i = r; i < n; i++) {
		exchange(a + r, a + i);
		b[r] = a[r];
		Permutation(a, n, r + 1);
		exchange(a + 0, a + i);
	}
}

int main(void) {
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(int);

	Permutation(a, n, 0);
	printf("순열의 개수 : %d\n", cnt);

	return 0;
}