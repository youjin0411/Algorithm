#include<stdio.h>
#include<stdlib.h>

int solution(int down[], int up[], int N) {
	//240 + 100 => 340 40 * 6 = 240 
	//6개의 열차 차량에 각 좌석 수는 40좌석 
	int answer = 0;
	int stand; //입석
	int passenger = 0; //현재 타고 있는 사람의 수 
	for (int i = 0; i < N; i++) {
		passenger += up[i] - down[i];
		stand = passenger - (40 * 6);
		if (stand > 0 && stand > answer) {
			answer = stand;
		}
	}
	return answer;
}
int main() {
	int down[] = {0, 0, 140, 80};
	int up[] = { 240, 100, 0, 160 };
	int N = 4;
	printf("%d", solution(down, up, N));
}