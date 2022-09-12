#include<stdio.h>
void QuickSort(int a[], int left, int right) {
	//i�� ���� left�� �������� ������ ���� �߿��� left�� ������ ū �� 
	//j�� ���� right�� �������� left ���� ���� ���� �� 
	//pivot�� ���������� pivot���� ũ�� i, pivot���� ������ j
	//temp�� i�� j�� ��ġ�� ������ �� �־�� �� �� 
	int i = left, j = right, pivot = a[left], temp;

	//right�� �ε����� left���� Ŭ ��
	if (left < right) {
		//j�� i���� Ŭ ��, j�� �ε����� i�� �ε������� ū ��� 
		while (i < j)
		{
			//right���� i�ε����� �����鼭 ���� i�� ���� ���������� ���� �� i���� ����
			while (i < right && a[i] <= pivot) i++;
			//left���� j�� �ε����� �� Ŭ ��, j�� ���� ���������� �� Ŭ �� j�� �� ����
			while (j > left && a[j] >= pivot) j--;
			// ���� ���ǵ��� ���� ���� �� ��, j�� i�� �ε������� Ŭ �� 
			// i�� ���� pivot���� ũ��, j�� ���� pivot���� ���� �� 
			if (i < j) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

		//i�� j���� Ŭ ��, j��� pivot�� ��ȯ�� �����̹Ƿ� a[j]�� �ε����� 0�� 
		//�׷��� a[j]�� a[left]�� ���� 
		a[left] = a[j];
		//pivot �������� a[j]�濡 ���� 
		//���� a[j]�� �ִ� �ε��� �濡 a[left] �� pivot ���� ��ȯ���ش�. 
		a[j] = pivot;

		//��� ȣ�� 
		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);
	}

}

int main(void) {
	int a[] = { 15,7,2,20,33,17,26,5,21,30,27,29,11,10,3 };
	int i, n = sizeof(a) / sizeof(int);

	QuickSort(a, 0, n - 1);
	printf("\n�� ���� : ");
	for (int i = 0; i < n; i++) printf("%5d", a[i]);
	printf("\n");

	return 0; 
}