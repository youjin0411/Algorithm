#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
/*
���� ��¥�� �� ��¥�� ���� ��¥ ���ϱ�
���� ��¥�� �� ��¥�� �־��� ��, �� ��¥�� ��ĥ��ŭ ������ �ִ���(D-day)�� ���Ϸ�
�մϴ�. �̸� ���� ������ ���� 3�ܰ�� ������ ���α׷� ���� �ۼ�(�� ������ ��� X)
1�ܰ�: ���� ��¥�� 1�� 1�Ϸκ��� ��ĥ��ŭ ������ �ִ��� ���Ѵ�.
2�ܰ�: �� ��¥�� 1�� 1�Ϸκ��� ��ĥ��ŭ ������ �ִ��� ���Ѵ�.
3�ܰ�: (2�ܰ迡�� ���� ��¥) - (1�ܰ迡�� ���� ��¥)�� ���Ѵ�. 
*/
int func_a(int month, int day) {
	int month_list[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //�� ���� ���������ΰ�
	int total = 0; //���� ��, ������ �ִ� ���� �� 
	for (int i = 0; i < month-1; i++) { //0���� month-1�� ���ؼ� �޸�ŭ �ݺ�
		total += month_list[i]; //���� �ϼ��� ���ϰ��� ������ 
	}
	total += day;
	return total - 1; //�ڱ� �ڽ� ���� 
}

int solution(int start_month, int start_day, int end_month, int end_day) {
	int start_total = func_a(start_month, start_day); //���۴��� �ϼ� ���ϱ�
	int end_total = func_a(end_month, end_day); //������ �ϼ� ���ϱ�
	return end_total - start_total; //�����ϰ� ���� ������ ��¥ 
}

int main() {
	int start_month = 1;
	int start_day = 2;
	int end_month = 2;
	int end_day = 2;
	int ret = solution(start_month, start_day, end_month, end_day);

	printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret);
}