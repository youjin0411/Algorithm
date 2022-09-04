#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/*
�����ϴ� ���� ���� ���� ���� ���� �� ���ϱ�
�ڿ����� ����ִ� �迭���� ���� ���� �����ϴ� ������ ������ ���� ���� �����ϴ�
���� ������ �� ������ ���Ϸ��� �Ѵ�. 
1�ܰ� : �迭�� ����ִ� �� �ڿ����� ������ ����.
2�ܰ� : ���� ���� �����ϴ� ���� ������ ���Ѵ�.
3�ܰ� : ���� ���� �����ϴ� ���� ������ ���Ѵ�,,
4�ܰ� : ���� ���� �����ϴ� ���� ���� ���� �����ϴ� ������ 
�� �� �� ������ ���Ѵ�. 
*/

int* func_a(int arr[], int arr_len) { //�迭�ȿ� �� �ڸ��� ���� ���ϱ� 
    int* counter = (int*)malloc(sizeof(int) * 1001); //�����Ҵ� 
    for (int i = 0; i < 1001; i++) //�ʱ�ȭ (������ ���� ������ �ʵ���) 
        counter[i] = 0; //���� 0���� �ʱ�ȭ ����  
    for (int i = 0; i < arr_len; i++) //�迭�� ���̸�ŭ ��ȯ
        counter[arr[i]]++; //�� �ڸ��� ���� ���� ������ 
    return counter;
}

int func_b(int arr[], int arr_len) { //�ִ�� ���� ����ִ� ���� ���� ���ϱ� 
    int ret = 0;
    for (int i = 0; i < arr_len; i++) { //�ݺ��� ��ȯ 
        if (ret < arr[i]) // ���� ret���� ���� �迭 ���� �� Ŭ�� 
            ret = arr[i]; // ���ϰ� ret�� ���� �迭 �� ���� 
    }
    return ret;
}

int func_c(int arr[], int arr_len) { //���� ���� ����ִ� �迭�� �� ���ϱ�
    const int INF = 1001;
    int ret = INF;
    for (int i = 0; i < arr_len; i++) { //�迭 ��ȯ
        if (arr[i] != 0 && ret > arr[i]) //���� ���� 0�� �ƴϰ� ret���� ���� ��  
            ret = arr[i]; //ret�� ���� �� ���� 
    }
    return ret;
}

int solution(int arr[], int arr_len) { //solution �Լ�
    int* counter = func_a(arr, arr_len); //�迭 �ȿ� ����ִ� �� ���� ���� ���� ����
    int max_cnt = func_b(counter, arr_len); // ���� ���� ����ִ� ������ ���� ���ϱ�
    int min_cnt = func_c(counter, arr_len); // ���� ���� ����ִ� ������ ���� ���ϱ� 
    return max_cnt / min_cnt;
}

int main() { //main�Լ�
    int arr[10] = { 1, 2, 3, 3, 1, 3, 3, 2, 3, 2 }; 
    int arr_len = 10;
    int ret = solution(arr, arr_len);

    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret);
}