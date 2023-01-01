#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//숫자 찾기 프로그래머스 Lv. 0
int solution(int num, int k) {
    int answer = 0;
    char charnum[20]; //num을 문자열로 변경할 변수
    char chark[10]; //k를 문자열로 변경할 변수
    sprintf(charnum, "%d", num); //num 문자열로 변경
    sprintf(chark, "%d", k); //k를 문자열로 변경 
    for (int i = 0; i < strlen(charnum); i++) { //문자열의 길이만큼 반복
        if (charnum[i] == chark[0]) { //charnum[i]안에 chark가 있으면 
            answer = i + 1; //인덱스 0부터 시작으므로 i + 1 리턴 
            break;
        }
    }
    if (answer == 0) return -1; //answer  = 0 즉 없다면 -1을 리턴함 
    return answer;
}