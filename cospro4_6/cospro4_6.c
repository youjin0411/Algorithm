#include<stdio.h>
/*
열심히 모은 포인터 다시 돌려드립니다. 
포인트는 100포인트 단위로 사용합니다. 
1000포인트 이상일 경우에만 사용이 가능합니다. 
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

    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}