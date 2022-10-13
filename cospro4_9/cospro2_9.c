#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int height[][4], int height_len) {
    int count = 0; //리턴값 (위험 지역의 수)

    int dx[4] = { -1, 1, 0, 0 }; //배열의 1차원 가로 x축 즉 인덱스라고 생각
    int dy[4] = { 0, 0, -1, 1 }; //배열의 1차원 세로 y축 즉 인덱스라고 생각
    int i, j, k;

    for (i = 0; i < 4; i++) { 
        for (j = 0; j < 4; j++) {
            int is_danger = 1; //위험 지역 1로 초기화 

            for (k = 0; k < 4; k++) { 
                // = > 배열 범위를 안 벗어났을 경우
                // 0보다 i + dx[x]가 크거나 같으면서 i + dx[k]가 4보다 작으면서 j + dy[k]가 0보다 크거나 같으면서 j+dy[k]가 4보다 작은 경우 
                if (0 <= i + dx[k] && i + dx[k] < 4 && 0 <= j + dy[k] && j + dy[k] < 4) {
                    //height[i + dx[k][j + dy[k]]가 height[i][j]보다 작으면 안전 지역으로 판별 
                    if (height[i + dx[k]][j + dy[k]] <= height[i][j])
                        is_danger = 0; //위험 지역 1을 0으로 초기화 해줌 
                }
            }

            if (is_danger == 1) //반복 할 때 마다 is_danger이 1이면 증감을 시켜준다. 
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