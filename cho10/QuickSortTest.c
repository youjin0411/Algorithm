#include<stdio.h>

void QuickSort(int a[], int left, int right) {
	int pivot = a[left], i = left, j = right, temp;

	if (left < right) {
		while (i < j) {
			while (i < right && pivot >= a[i]) i++;
			while (j > left && pivot <= a[j]) j--;
			if (i < j) {
				temp = a[i]; a[i] = a[j]; a[j] = temp;
			}
		}
		a[left] = a[j];
		a[j] = pivot;
		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);
	}
}

int main(void) {
	int a[] = { 25,23,17,3,11,15,48,30,4,80,26,32 };
	int n = sizeof(a) / sizeof(int);

	QuickSort(a, 0, n - 1);
	printf("ÄüÁ¤·Ä : ");
	for (int i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
	return 0;
}