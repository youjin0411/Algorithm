#include<stdio.h>
#include<stdlib.h>

//최소 금액을 찾는 함수
double func_a(double a[], int n) {
	double min;
	min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

int solution(int price[][2], int price_len) {
	double* sales = (*double)malloc(sizeof(double) * price_len);
	double percent;
	for (int i = 0; i < price_len; i++) {
		if (price[i][0] < 5000) percent = 0.25;
		else if (price[i][0] < 15000) percent = 0.2;
		else if (price[i][0] < 100000) percent = 0.15;
		else percent = 0.1;
		sales[i] = price[i][0] * price[i][1]  * percent;
	}
	return (int)func_a(sales, price_len);
}
int main() {
	int price[][2] = { { 6000, 20 }, {80000, 100}, {4000, 90} };
	int price_len = 3;
	printf("%d", solution(price, price_len));
}