#include<stdio.h>

int binarySearch(int a[], int n, int key) {
	int left = 0; int right = n - 1; mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (key >= a[mid]) left = mid + 1;
		else if (key < a[mid]) right = mid - 1;
		else return mid;
	}
	return -1;
}