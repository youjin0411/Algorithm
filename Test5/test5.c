#include<stdio.h>
#include<stdlib.h>

int solution(int down[], int up[], int N) {
	//240 + 100 => 340 40 * 6 = 240 
	//6���� ���� ������ �� �¼� ���� 40�¼� 
	int answer = 0;
	int stand; //�Լ�
	int passenger = 0; //���� Ÿ�� �ִ� ����� �� 
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