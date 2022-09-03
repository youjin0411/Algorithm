#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/* 369 게임 박수의 갯수는? 
숫자 중 3, 6, 9를 하나라도 포함하고 있다면 
숫자에 포함된 3, 6, 9만큼 박수를 치는 프로그램 

계획 : for반복문 -> while -> if -> count -> /10
*/

//solution함수
int solution(int number) {
    int answer = 0; //박수의 수 
    for (int i = 0; i < number; i++) { //숫자만큼 반복
        int current = i; //while문 사용 시 초기식으로 변수 새로 생성 
        while (current != 0) //current(i)가 0이 아닐 때까지 
        {
            if (current % 10 == 3 || current % 10 == 6 || current % 10 == 9) { //일의 자리수가 3,6,9구하기
                answer++; //참이면 박수의 수 증감
            }
            current /= 10; //십의 자리, 백의 자리 등의 숫자 구하기 위해 사용 
        }
    }
    return answer;
}

//maing함수
int main() {
    int number = 40;
    int ret = solution(number);

    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}