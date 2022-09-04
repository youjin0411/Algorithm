#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
/*
시작 날짜와 끝 날짜의 사이 날짜 구하기
시작 날짜와 끝 날짜가 주어질 때, 두 날짜가 며칠만큼 떨어져 있는지(D-day)를 구하려
합니다. 이를 위해 다음과 같이 3단계로 간단히 프로그램 구조 작성(단 윤년은 고려 X)
1단계: 시작 날짜가 1월 1일로부터 며칠만큼 떨어져 있는지 구한다.
2단계: 끝 날짜가 1월 1일로부터 며칠만큼 떨어져 있는지 구한다.
3단계: (2단계에서 구한 날짜) - (1단계에서 구한 날짜)를 구한다. 
*/
int func_a(int month, int day) {
	int month_list[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //각 달이 언제까지인가
	int total = 0; //리턴 값, 떨어져 있는 수의 합 
	for (int i = 0; i < month-1; i++) { //0부터 month-1를 통해서 달만큼 반복
		total += month_list[i]; //달의 일수를 리턴값에 더해줌 
	}
	total += day;
	return total - 1; //자기 자신 제외 
}

int solution(int start_month, int start_day, int end_month, int end_day) {
	int start_total = func_a(start_month, start_day); //시작달의 일수 구하기
	int end_total = func_a(end_month, end_day); //끝날의 일수 구하기
	return end_total - start_total; //시작일과 끝일 사이의 날짜 
}

int main() {
	int start_month = 1;
	int start_day = 2;
	int end_month = 2;
	int end_day = 2;
	int ret = solution(start_month, start_day, end_month, end_day);

	printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}