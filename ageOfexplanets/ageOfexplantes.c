#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//문제 : 프로그래머스 외계행성의 나이 
char* solution(int age) {
    char temp[10]; //age 정수형을 문자열로 바꿀 char문자열 
    sprintf(temp, "%d", age); //age 정수형 -> temp 문자열 변수에 문자열로 변환하여 대입
    int len = strlen(temp); //즉 문자열의 길이
    char* answer = (char*)malloc(len); //문자열의 길이만큼 동적 할당 
    char* num[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' }; //외계행성 나이표 0, 1, 2, 3 ....
    int i = 0;
    answer[len] = '\0'; //마지막 값 쓰레기 처리 
    while (age != 0) { //유클리드 호제법 활용 (최대공약수 구하는 방법 활용함)
        int r = age % 10; //23 % 10 = 3
        answer[--len] = num[r];
        int res = age / 10; //23 / 10 = 2
        age = res;
    }
    return answer;
}