#include<stdio.h>

void InsertionSort(int a[], int n) {
	int i, j, key;

	for (i = 1; i < n; i++) { //1~n������ ����: ���������� 2��° ������ �񱳸� �����ϱ� ����
		key = a[i]; //key�� a[i]�� ó������ �� ��° ���� key�ڸ��� �־��ش�. 
		for (j = i - 1; j >= 0; j--) { //i-1���� �� ����: key�� ���� �ڸ��� ���ϱ� ���ؼ� ��� 
			if (key >= a[j]) break; //key���� a[j]�� �۰ų� ���� ���� �����. 
			a[j + 1] = a[j]; //key������ a[j]�� Ŭ ���� a[j+1] �ڸ��� a[j]���� �������ش�. 
		}
		a[j + 1] = key;  //key���� a[j+1]���ڸ��� �־��� �� �ٽ� ó�� for������ ���ư� i=2���� ���� 
	}
}

int main(void) {
	int a[] = { 7,12,6,11,3,8,5,2 };
	int i, n = sizeof(a) / sizeof(int);

	printf("���� �� : ");
	for (i = 0; i < n; i++) printf("%d   ", a[i]);

	InsertionSort(a, n);

	printf("\n�������� �� : ");
	for (i = 0; i < n; i++) printf("%d    ", a[i]);

	return 0;
}