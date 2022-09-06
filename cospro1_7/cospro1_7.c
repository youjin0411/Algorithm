#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

/*
문제 : 중복문자 삭제하기
알파벳 문자열이 주어질 때, 연속하는 중복 문자를 삭제하려고 한다.
*/
char* solution(char* characters) { //문자열 매개변수로 받음
    //중복하지 않은 문자를 담을 포인터 char 배열을 동적할당 생성 
    char* answer = (char*)malloc(sizeof(char) * 103);
    int str_len = 0;
    answer[0] = characters[0];
    str_len++;
    for (int i = 1; i < strlen(characters); i++) {
        if (characters[i - 1] != characters[i]) {
            answer[str_len] = characters[i];
            str_len++;
        }
    }
    answer[str_len] = NULL;
    return answer;
}

int main() {
    char* characters = "senteeeencccccceeee";
    char* ret = solution(characters);

    printf("solution 함수의 반환 값은 %s 입니다.\n", ret);
}
