#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int sides[], size_t sides_len) {
    int answer = 2; //만들 수 없을 경우에 리턴할 2로 초기화 시켜줌 
    int max = 0, total = 0; //최대값을 구할 max와 세 변의 합을 담을 total 변수 선언 
    for (int i = 0; i < sides_len; i++) { 
        total += sides[i]; //세변을 모두 더함 
        if (sides[i] > max) max = sides[i]; //최대값을 구함 
    }
    if (max < (total - max)) answer = 1; //최대값이 세변의 합 - 최대값보다 작은 경우 삼각형 만들 수 있음 1리턴

    return answer;
}