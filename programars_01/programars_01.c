#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

int func_a(int m) {
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		sum += i;
	}
	return sum;
}

int solution(int n, int m) {
	int sum_to_m = func_a(m);
	int sum_to_n = func_a(n - 1);
	int answer = sum_to_m - sum_to_n;
	return answer;
}

int main() {
	int n1 = 5;
	int m1 = 10;
	int ret1 = solution(n1, m1);
	printf("solution �Լ��� ��� ���� : %d �̴�\n", ret1);

	int n2 = 6;
	int m2 = 6;
	int ret2 = solution(n2, m2);
	printf("solution �Լ��� ��� ���� : %d �̴�", ret2);
}