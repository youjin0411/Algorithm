#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/* 369 ���� �ڼ��� ������? 
���� �� 3, 6, 9�� �ϳ��� �����ϰ� �ִٸ� 
���ڿ� ���Ե� 3, 6, 9��ŭ �ڼ��� ġ�� ���α׷� 

��ȹ : for�ݺ��� -> while -> if -> count -> /10
*/

//solution�Լ�
int solution(int number) {
    int answer = 0; //�ڼ��� �� 
    for (int i = 0; i < number; i++) { //���ڸ�ŭ �ݺ�
        int current = i; //while�� ��� �� �ʱ������ ���� ���� ���� 
        while (current != 0) //current(i)�� 0�� �ƴ� ������ 
        {
            if (current % 10 == 3 || current % 10 == 6 || current % 10 == 9) { //���� �ڸ����� 3,6,9���ϱ�
                answer++; //���̸� �ڼ��� �� ����
            }
            current /= 10; //���� �ڸ�, ���� �ڸ� ���� ���� ���ϱ� ���� ��� 
        }
    }
    return answer;
}

//maing�Լ�
int main() {
    int number = 40;
    int ret = solution(number);

    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret);
}