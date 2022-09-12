#include<stdio.h>


int main(void) {
	int a[] = { 15,7,2,20,33,17,26,5,21,30,27,29,11,10,3 };
	int i, n = sizeof(a) / sizeof(int);

	QuickSort(a, 0, n - 1);
	printf("\nÄü Á¤·Ä : ");
	for (int i = 0; i < n; i++) printf("%5d", a[i]);
	printf("\n");

	return 0; 
}