#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//숫자만 있는 copy배열을 만드는 함수
int func_a(char dest[], char src[]) {
	int k = 0;
	for (int i = 0; src[i] != 0; i++) {
		if ('0' <= src[i] && src[i] <= '9')
			dest[k++] = src[i];
	}
	dest[k] = 0;
	return k;
}

char* solution(char number[]) {
	char* copy = (char*)malloc(sizeof(char) * strlen(number) + 1);
	char* answer = (char*)malloc(sizeof(char) * 14);
	int k = 0;
	if (number[0] != '0') copy[k++] = '0'; //번호의 시작이 0이 아니면 copy 배열의 0번 0초기화
	func_a(copy + k, number);
	if (strlen(copy + 3) < 8) answer[4] = 0; //000-0000-0000
	k = 0;
	for (int i = 0; copy[i] != 0; i++) {
		answer[k++] = copy[i];
		if (k == 3 || k == 8) {
			answer[k++] = '-';
		}
		if (k == 4 && answer[k] != '0') k++;
	}
	answer[k] = 0;
	free(copy);
	return answer;
}
int main() {
	char number[] = { "10-222-1111" };
	char* result = solution(number);
	for (int i = 0; i < 13; i++) {
		printf("%c", result[i]);
	}
}