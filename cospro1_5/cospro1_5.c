#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
/*
���� ���� ����� �� ���ϱ�
�ʱ� ���� ���Ǵ� ���ͽ��迡�� 650�� �̻� 800�� �̸��� ������ ����� �л����� ����������� �ϰ� �ִ�. 
*/
int solution(int scores[], int scores_len) {
    int count = 0; //������ �� 
    for (int i = 0; i < scores_len; i++) { //�迭�� ���̸�ŭ ��ȯ 
        if (scores[i] >= 650 && scores[i] < 800) { //���� 650�̻� 800�̸� 
            count++; //������ �� ���� 
        }
    }
    return count;
}

int main() {
    int scores[10] = { 650, 722, 914, 558, 714, 803, 650, 679, 669, 800 };
    int scores_len = 10;
    int ret = solution(scores, scores_len);

    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret);
}
