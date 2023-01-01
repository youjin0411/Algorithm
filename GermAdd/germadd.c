#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int solution(int n, int t) {
    int answer = n; //초기 세균의 수 answer에 먼저 대입
    int i = 1;
    while (i <= t) {
        answer = (n *= 2);
        ++i;
    }
    return answer;
}