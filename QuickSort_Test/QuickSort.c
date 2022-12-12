#include<stdio.h>

void QuickSort(int* a, int left, int right) {
	int i, j, pivot, temp;
	if (left < right) {
		pivot = a[left];
		i = left;
		j = right;
		while (i < j)
		{
			while (i < right && a[i] <= pivot) i++;
			while (j > left && a[j] >= pivot) j--;
			if (i < j) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		a[left] = a[j];
		a[j] = pivot;

		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);
	}

}