#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
���� : �迭�� ���� ������
�־��� �迭�� ������ ���������� �Ѵ�.
���� ��� �־��� �迭�� [1,4,2,3]�̸�, ������ ������ �迭��[3,2,4,1]�̴�. 
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

    printf("solution �Լ��� ��ȯ ���� {");
    for (int i = 0; i < 4; i++) {
        if (i != 0) printf(", ");
        printf("%d", ret[i]);
    }
    printf("} �Դϴ�.\n");
}
