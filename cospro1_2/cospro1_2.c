#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
문제 : 배열의 순서 뒤집기
주어진 배열의 순서를 뒤집으려고 한다.
예를 들어 주어진 배열이 [1,4,2,3]이면, 순서를 뒤집은 배열은[3,2,4,1]이다. 
*/
int* solution(int arr[], int arr_len) {
    int left = 0; 
    int right = arr_len - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left+=1;
        right-=1;
    }
    return arr;
}

int main() {
    int arr[4] = { 1, 4, 2, 3 };
    int arr_len = 4;
    int* ret = solution(arr, arr_len);

    printf("solution 함수의 반환 값은 {");
    for (int i = 0; i < 4; i++) {
        if (i != 0) printf(", ");
        printf("%d", ret[i]);
    }
    printf("} 입니다.\n");
}
