#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//���� ã�� ���α׷��ӽ� Lv. 0
int solution(int num, int k) {
    int answer = 0;
    char charnum[20]; //num�� ���ڿ��� ������ ����
    char chark[10]; //k�� ���ڿ��� ������ ����
    sprintf(charnum, "%d", num); //num ���ڿ��� ����
    sprintf(chark, "%d", k); //k�� ���ڿ��� ���� 
    for (int i = 0; i < strlen(charnum); i++) { //���ڿ��� ���̸�ŭ �ݺ�
        if (charnum[i] == chark[0]) { //charnum[i]�ȿ� chark�� ������ 
            answer = i + 1; //�ε��� 0���� �������Ƿ� i + 1 ���� 
            break;
        }
    }
    if (answer == 0) return -1; //answer  = 0 �� ���ٸ� -1�� ������ 
    return answer;
}