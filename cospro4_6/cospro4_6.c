#include<stdio.h>
/*
������ ���� ������ �ٽ� �����帳�ϴ�. 
����Ʈ�� 100����Ʈ ������ ����մϴ�. 
1000����Ʈ �̻��� ��쿡�� ����� �����մϴ�. 
*/

int solution(int point) {
    int answer = 0;
    if (point >= 1000) {
        answer = (point / 100) * 100;
    }
    return answer;
}

int main() {
    int point = 2323;
    int ret = solution(point);

    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret);
}