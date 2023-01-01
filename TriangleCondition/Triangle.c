#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int sides[], size_t sides_len) {
    int answer = 2; //���� �� ���� ��쿡 ������ 2�� �ʱ�ȭ ������ 
    int max = 0, total = 0; //�ִ밪�� ���� max�� �� ���� ���� ���� total ���� ���� 
    for (int i = 0; i < sides_len; i++) { 
        total += sides[i]; //������ ��� ���� 
        if (sides[i] > max) max = sides[i]; //�ִ밪�� ���� 
    }
    if (max < (total - max)) answer = 1; //�ִ밪�� ������ �� - �ִ밪���� ���� ��� �ﰢ�� ���� �� ���� 1����

    return answer;
}