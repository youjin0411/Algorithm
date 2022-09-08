#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*
단체 티셔츠 주문하기
[XS, S, M, L, XL, XXL] 사이즈 개수 순서
*/
int main() {
	char* shirt_size[] = { "XS", "S", "L", "L", "XL", "S" };
	int shirt_size_len = 6;
	int* ret = solution(shirt_size, shirt_size_len);

	printf("solution 함수의 반환 값은 {");
	for (int i = 0; i < 6; i++) {
		if (i != 0) printf(", ");
		printf("%d", ret[i]);
	}
	printf("} 입니다.\n");
}
