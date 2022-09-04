#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/*
등장하는 가장 많은 수와 가장 적은 수 구하기
자연수가 들어있는 배열에서 가장 많이 등장하는 숫자의 개수는 가장 적게 등장하는
숫자 개수의 몇 배인지 구하려고 한다. 
1단계 : 배열에 들어있는 각 자연수의 개수를 센다.
2단계 : 가장 많이 등장하는 수의 개수를 구한다.
3단계 : 가장 적게 등장하는 수의 개수를 구한다,,
4단계 : 가장 많이 등장하는 수가 가장 적게 등장하는 수보다 
몇 배 더 많은지 구한다. 
*/

int* func_a(int arr[], int arr_len) { //배열안에 각 자리별 개수 구하기 
    int* counter = (int*)malloc(sizeof(int) * 1001); //동적할당 
    for (int i = 0; i < 1001; i++) //초기화 (쓰레기 값이 나오지 않도록) 
        counter[i] = 0; //전부 0으로 초기화 해줌  
    for (int i = 0; i < arr_len; i++) //배열의 길이만큼 순환
        counter[arr[i]]++; //각 자리별 수를 증감 시켜줌 
    return counter;
}

int func_b(int arr[], int arr_len) { //최대로 많이 들어있는 수의 개수 구하기 
    int ret = 0;
    for (int i = 0; i < arr_len; i++) { //반복문 순환 
        if (ret < arr[i]) // 만약 ret보다 비교할 배열 방이 더 클때 
            ret = arr[i]; // 리턴값 ret에 비교한 배열 방 대입 
    }
    return ret;
}

int func_c(int arr[], int arr_len) { //제일 적게 들어있는 배열의 수 구하기
    const int INF = 1001;
    int ret = INF;
    for (int i = 0; i < arr_len; i++) { //배열 순환
        if (arr[i] != 0 && ret > arr[i]) //비교할 수가 0이 아니고 ret보다 적을 때  
            ret = arr[i]; //ret에 비교할 수 대입 
    }
    return ret;
}

int solution(int arr[], int arr_len) { //solution 함수
    int* counter = func_a(arr, arr_len); //배열 안에 들어있는 각 각의 숫자 개수 세기
    int max_cnt = func_b(counter, arr_len); // 가장 많은 들어있는 숫자의 개수 구하기
    int min_cnt = func_c(counter, arr_len); // 가장 적게 들어있는 숫자의 개수 구하기 
    return max_cnt / min_cnt;
}

int main() { //main함수
    int arr[10] = { 1, 2, 3, 3, 1, 3, 3, 2, 3, 2 }; 
    int arr_len = 10;
    int ret = solution(arr, arr_len);

    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}