#include<stdio.h>
void QuickSort(int a[], int left, int right) {
	//i는 현재 left를 기준으로 오른쪽 숫자 중에서 left의 수보다 큰 수 
	//j는 현재 right를 기준으로 left 숫자 보다 작은 수 
	//pivot은 기준점으로 pivot보다 크면 i, pivot보다 작으면 j
	//temp는 i와 j의 위치를 변경할 시 넣어둘 빈 방 
	int i = left, j = right, pivot = a[left], temp;

	//right의 인덱스가 left보다 클 때
	if (left < right) {
		//j가 i보다 클 때, j의 인덱스가 i의 인덱스보다 큰 경우 
		while (i < j)
		{
			//right보다 i인덱스가 작으면서 현재 i의 값이 기준점보다 작을 때 i값을 증가
			while (i < right && a[i] <= pivot) i++;
			//left보다 j의 인덱스가 더 클 때, j의 값이 기준점보다 더 클 때 j의 값 감소
			while (j > left && a[j] >= pivot) j--;
			// 위의 조건들이 맞지 않을 때 즉, j가 i의 인덱스보다 클 때 
			// i의 값이 pivot보다 크고, j의 값이 pivot보다 작을 때 
			if (i < j) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

		//i가 j보다 클 때, j방과 pivot을 교환한 상태이므로 a[j]의 인덱스가 0임 
		//그래서 a[j]를 a[left]에 대입 
		a[left] = a[j];
		//pivot 기준점을 a[j]방에 대입 
		//원래 a[j]가 있던 인덱스 방에 a[left] 즉 pivot 값을 교환해준다. 
		a[j] = pivot;

		//재귀 호출 
		//a[j]방을 기준으로 반으로 쪼갠다고 생각하고 정렬
		//a정렬시킬 배열, left 시작 인덱스 0, j-1 a[j]인덱스-1
		QuickSort(a, left, j - 1);
		//a정렬시킬 배열, j+1 a[j]+1로 시작 인덱스, right 끝 인덱스 
		QuickSort(a, j + 1, right);
	}

}

int main(void) {
	int a[] = { 15,7,2,20,33,17,26,5,21,30,27,29,11,10,3 };
	int i, n = sizeof(a) / sizeof(int);

	//a는 정렬시킬 배열, 0은 시작 인덱스 left, n-1은 끝 인덱스 right
	QuickSort(a, 0, n - 1);
	printf("\n퀵 정렬 : ");
	for (int i = 0; i < n; i++) printf("%5d", a[i]);
	printf("\n");

	return 0; 
}