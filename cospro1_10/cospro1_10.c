#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*
 ���θ� ��޺� ���� �ݾ� ���ϱ�
 ��� : S -> ������ : 5%
 ��� : S -> ������ : 10%
 ��� : S -> ������ : 15%
*/


int main() {
	int price1 = 2500;
	char* grade1 = "V";
	int ret1 = solution(price1, grade1);

	printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret1);

	int price2 = 96900;
	char* grade2 = "S";
	int ret2 = solution(price2, grade2);

	printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret2);
}
