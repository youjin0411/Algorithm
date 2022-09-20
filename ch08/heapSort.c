#include <stdio.h>
#include <limits.h>

void HeapSort(int a[], int n) {
	int i, parent, child, value, size = n;

	//�ִ��� ����
	for (i = n / 2; i >= 1; i--) {
		value = a[i];
		parent = i;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) break;
			a[parent] = a[child];
			parent = child;
		}
		a[parent] = value;
	}

	printf("�ִ���: ");
	for (i = 1; i <= n; i++) printf("%4d", a[i]);
	printf("\n\n");

	//�� ����
	while (n > 1) {
		value = a[n];
		a[n--] = a[1];
		parent = 1;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) break;
			a[parent] = a[child];
			parent = child;
		}
		a[parent] = value;

		printf("�ܰ�%3d:", size - n);
		for (i = 1; i <= size; i++)
			printf("%4d", a[i]);
		printf("\n");
	}
}

int main(void) {
	int a[] = { INT_MIN, 8,6,11,5,47,23,1,7,20,28 };
	int i, n = sizeof(a) / sizeof(int);

	printf("������: ");
	for (i = 1; i < n; i++)	printf("%4d", a[i]);
	printf("\n\n");

	HeapSort(a, n - 1);

	printf("\n������: ");
	for (i = 1; i < n; i++)	printf("%4d", a[i]);
	printf("\n\n");

	return 0;
}