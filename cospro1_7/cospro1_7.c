#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

/*
���� : �ߺ����� �����ϱ�
���ĺ� ���ڿ��� �־��� ��, �����ϴ� �ߺ� ���ڸ� �����Ϸ��� �Ѵ�.
*/
char* solution(char* characters) { //���ڿ� �Ű������� ����
    //�ߺ����� ���� ���ڸ� ���� ������ char �迭�� �����Ҵ� ���� 
    char* answer = (char*)malloc(sizeof(char) * 103);
    int str_len = 0;
    answer[0] = characters[0];
    str_len++;
    for (int i = 1; i < strlen(characters); i++) {
        if (characters[i - 1] != characters[i]) {
            answer[str_len] = characters[i];
            str_len++;
        }
    }
    answer[str_len] = NULL;
    return answer;
}

int main() {
    char* characters = "senteeeencccccceeee";
    char* ret = solution(characters);

    printf("solution �Լ��� ��ȯ ���� %s �Դϴ�.\n", ret);
}
