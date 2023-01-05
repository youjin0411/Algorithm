#include<stdio.h>
#include<stdlib.h>
int func_a(int a[], int n, int length) {
	for (int i = 0; i < n; i++) {
		if (a[i] >= length) {
			return i;
		}
	}
	return -1;
}
int solution(int N, int orders[], int orders_len) {
	int* material = (int*)malloc(sizeof(int) * N);
	int k = 0;
	int price = 0; 
	//������ �ִ� ������ �� ��ŭ �����Ҵ� ���� �迭 ���� 
	for (int i = 0; i < orders_len; i++) material[i] = 8;
	//�ֹ����� ��ŭ �ݺ����� ������, �ֹ����� ��ŭ ������ �ִ� ���翡�� �ڸ� �� �ִ��� Ȯ��
	for (int i = 0; i < orders_len; i++) {
		k = func_a(material, N, orders[i]);
		if (k >= 0) {
			material[k] -= orders[i];
			price += (3000 * orders[i]);
		}
	}
	return price;
}
int main() {
	int N = 4;
	int orders[] = { 2, 6 , 3, 1};
	int orders_len = 4;
	printf("%d", solution(N, orders, orders_len));
}