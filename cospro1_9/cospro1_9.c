#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*
��ü Ƽ���� �ֹ��ϱ�
[XS, S, M, L, XL, XXL] ������ ���� ����
*/
int main() {
	char* shirt_size[] = { "XS", "S", "L", "L", "XL", "S" };
	int shirt_size_len = 6;
	int* ret = solution(shirt_size, shirt_size_len);

	printf("solution �Լ��� ��ȯ ���� {");
	for (int i = 0; i < 6; i++) {
		if (i != 0) printf(", ");
		printf("%d", ret[i]);
	}
	printf("} �Դϴ�.\n");
}
