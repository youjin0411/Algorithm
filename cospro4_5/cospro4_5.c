#include<stdio.h>
/*
���� ���� ������ �׵��� ���� �Ĵ��� ���� �� �ּڰ����� ū ���
��� �Ͽ� �� ���̸�ŭ �Ҹ��ϴ� �Ĵ� 
*/
int solution(int calorie[], int calorie_len) {
    int beforecalorie = calorie[0];
    int answer = 0;
    for (int i = 0; i < calorie_len; i++) {
        if (beforecalorie < calorie[i]) {
            answer += (calorie[i] - beforecalorie);
        }
        else {
            beforecalorie = calorie[i];
        }
    }
    return answer;
}


int main() {
    int calorie[] = { 713, 665, 873, 500, 751 };
    int ret = solution(calorie, 5);

    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret);
}