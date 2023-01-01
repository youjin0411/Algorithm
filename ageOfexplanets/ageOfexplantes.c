#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//���� : ���α׷��ӽ� �ܰ��༺�� ���� 
char* solution(int age) {
    char temp[10]; //age �������� ���ڿ��� �ٲ� char���ڿ� 
    sprintf(temp, "%d", age); //age ������ -> temp ���ڿ� ������ ���ڿ��� ��ȯ�Ͽ� ����
    int len = strlen(temp); //�� ���ڿ��� ����
    char* answer = (char*)malloc(len); //���ڿ��� ���̸�ŭ ���� �Ҵ� 
    char* num[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' }; //�ܰ��༺ ����ǥ 0, 1, 2, 3 ....
    int i = 0;
    answer[len] = '\0'; //������ �� ������ ó�� 
    while (age != 0) { //��Ŭ���� ȣ���� Ȱ�� (�ִ����� ���ϴ� ��� Ȱ����)
        int r = age % 10; //23 % 10 = 3
        answer[--len] = num[r];
        int res = age / 10; //23 / 10 = 2
        age = res;
    }
    return answer;
}