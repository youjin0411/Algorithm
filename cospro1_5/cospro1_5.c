#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
/*
영어 수강 대상자 수 구하기
초급 영어 강의는 토익시험에서 650점 이상 800점 미만의 성적을 취득한 학생만을 수강대상으로 하고 있다. 
*/
int solution(int scores[], int scores_len) {
    int count = 0; //수강자 수 
    for (int i = 0; i < scores_len; i++) { //배열의 길이만큼 순환 
        if (scores[i] >= 650 && scores[i] < 800) { //조건 650이상 800미만 
            count++; //수강자 수 증감 
        }
    }
    return count;
}

int main() {
    int scores[10] = { 650, 722, 914, 558, 714, 803, 650, 679, 669, 800 };
    int scores_len = 10;
    int ret = solution(scores, scores_len);

    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}
