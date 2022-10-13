#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int height[][4], int height_len) {
    int count = 0; //리턴값 (위험 지역의 수)

    int dx[4] = { -1, 1, 0, 0 }; //배열의 1차원 가로 x축
    int dy[4] = { 0, 0, -1, 1 }; //배열의 1차원 세로 y축
    int i, j, k;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            int is_danger = 1;

            for (k = 0; k < 4; k++) {
                if (0 <= i + dx[k] && i + dx[k] < 4 && 0 <= j + dy[k] && j + dy[k] < 4) {
                    if (height[i + dx[k]][j + dy[k]] <= height[i][j])
                        is_danger = 0;
                }
            }

            if (is_danger == 1)
                count++;
        }
    }

    return count;
}

int main() {
    int height[4][4] = { {3, 6, 2, 8}, {7, 3, 4, 2}, {8, 6, 7, 3}, {5, 3, 2, 9} };
    int height_len = 4;
    int ret = solution(height, height_len = 4);

    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}