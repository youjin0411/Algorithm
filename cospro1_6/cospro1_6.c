#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

/*
팰린드롬 판단하기
앞에서부터 읽을 때와 뒤에서부터 읽을 때 똑같은 단어 또는 문장을 팰린드롬이라 함
소문자 알파벳, 공백(""), 그리고 마침표(".")로 이루어진 문장이 팰린드롬 문장인지
점검하려고 한다. 문장 내에서 알파벳만 추출하였을 때에 팰린드롬 단어이면 팰린드롬 문장이다. 
*/

bool solution(char* sentence) {
    char* str = (char*)malloc(sizeof(char) * 103);
    int len = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        char ch = sentence[i];
        if (ch != ' ' && ch != '.') str[len++] = ch;
    }
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) return false;
    }
    return true;
}

int main() {
    char sentence1[19] = "never odd or even.";
    bool ret1 = solution(sentence1);

    printf("solution 함수의 반환 값은 %s 입니다.\n", ret1 == true ? "true" : "false");

    char sentence2[19] = "palindrome";
    bool ret2 = solution(sentence2);

    printf("solution 함수의 반환 값은 %s 입니다.\n", ret2 == true ? "true" : "false");
}
