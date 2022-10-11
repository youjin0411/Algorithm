#include<stdio.h>
/*
오늘 먹은 열량이 그동안 먹은 식단의 열량 중 최솟값보다 큰 경우
운동을 하여 그 차이만큼 소모하는 식당 
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

    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}