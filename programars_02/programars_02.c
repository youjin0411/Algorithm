#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int func_a(int s[], int arr_size) {
	int ret = 0;
	for (int i = 0; i < arr_size; i++) {
		if (s[i] > ret) {
			ret = s[i];
		}
	}
	return ret;
}

int func_b(int s[], int arr_size) {
	int ret = 0;
	for (int i = 0; i < arr_size; i++) {
		ret += s[i];
	}
	return ret;
}

int func_c(int s[], int arr_size) {
	int ret = s[0];
	for (int i = 0; i < arr_size; i++) {
		if (s[i] < ret) {
			ret = s[i];
		}
	}
	return ret;
}

int solution(int scores[], int scores_len) {
	int sum = func_b(scores, scores_len);
	int max_score = func_a(scores, scores_len);
	int min_score = func_c(scores, scores_len);
	return sum - max_score - min_score;
}

int main() {
	int scores[] = { 50, 35, 78, 91, 85 };
	int scores_len = 5;
	int ret = solution(scores, scores_len);
	printf("solution 함수의 결과값은 : %d이다\n", ret);
}

