#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

/*
문제 : 중복문자 삭제하기
알파벳 문자열이 주어질 때, 연속하는 중복 문자를 삭제하려고 한다.
*/
int solution(char* characters) {
    char* answer = (char*)malloc(sizeof(char) * 103);
    answer[0] = characters[0];

}

int main() {
    char* characters = "senteeeencccccceeee";
    char* ret = solution(characters);

    printf("solution 함수의 반환 값은 %s 입니다.\n", ret);
}
