#include<stdio.h>
#include<string.h>
#include<stdio.h>

int func_a(int a) {
	return ((a / 100) * 60) + (a % 100);
}
int solution(int arr[], int arr_len) {
	int answer = 0;
	int min_a;
	int min_b;
	min_a = func_a(2200);
	for (int i = 0; i < arr_len; i++) {
		min_b = func_a(arr[i]);
		answer += 1000 + ((min_a - min_b) / 10) * 500;
	}
	return answer;
}
int main() {
	int arr[] = { 1400, 530 };
	int arr_len = 2;
	printf("%d", solution(arr, arr_len));
}
