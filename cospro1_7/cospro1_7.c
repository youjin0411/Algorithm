#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

/*
���� : �ߺ����� �����ϱ�
���ĺ� ���ڿ��� �־��� ��, �����ϴ� �ߺ� ���ڸ� �����Ϸ��� �Ѵ�.
*/
int solution(char* characters) {
    char* answer = (char*)malloc(sizeof(char) * 103);
    answer[0] = characters[0];

}

int main() {
    char* characters = "senteeeencccccceeee";
    char* ret = solution(characters);

    printf("solution �Լ��� ��ȯ ���� %s �Դϴ�.\n", ret);
}
