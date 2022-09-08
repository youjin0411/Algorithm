#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*
 쇼핑몰 등급별 할인 금액 구하기
 등급 : S -> 할인율 : 5%
 등급 : G -> 할인율 : 10%
 등급 : V -> 할인율 : 15%
*/
int solution(int price, char* grade) {
	int answer = 0; 
	if (strcmp(grade, "S") == 0) answer = price * 0.95;
	if (strcmp(grade, "G") == 0) answer = price * 0.9;
	if (strcmp(grade, "V") == 0) answer = price * 0.85;

	return answer;
}

int main() {
	int price1 = 2500;
	char* grade1 = "V";
	int ret1 = solution(price1, grade1);

	printf("solution 함수의 반환 값은 %d 입니다.\n", ret1);

	int price2 = 96900;
	char* grade2 = "S";
	int ret2 = solution(price2, grade2);

	printf("solution 함수의 반환 값은 %d 입니다.\n", ret2);
}
