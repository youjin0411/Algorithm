#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int solution(int n, int t) {
    int answer = n; //�ʱ� ������ �� answer�� ���� ����
    int i = 1;
    while (i <= t) {
        answer = (n *= 2);
        ++i;
    }
    return answer;
}