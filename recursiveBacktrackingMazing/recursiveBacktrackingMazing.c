#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�̷� ũ��, row(>=3)�� ��, col(>=3)�� �� ũ��
int row, col;

//�̷θ� ����� �ͷ� ȣ�� ������� ����� ����
void mazeCreating(char** mazeMark, int i, int j) {
	int view_i, view_j, dir;
	int move[4][2] = { {-2,0},{2,0},{0,-2},{0,2} };//�����¿�

	while (mazeMark[i][j] < 15) { //�����¿� ��� ���� �� ������ �ݺ�
		do {
			dir = rand() % 4; //4���� �� ������ ����
		} while ((mazeMark[i][j] & (1 << dir)) == 1); //dir�� ���캻 �����̸� dir �ٽ� ����

		//�̵� ������ ǥ����. dir�� 3�̸� �����ʿ��� �� ��°�� 1�� �ǰ� ��. 00000100
		//4���� ��� ���캸�Ҵٸ� 00001111 => 15
		mazeMark[i][j] |= (1 << dir);

		//�̵��� ���� ��ǥ�� ����
		view_i = i + move[dir][0];
		view_j = j + move[dir][1];

		//�̵��� ���� ��ǥ�� �̷� �࿭ �������� �ְ�
		if (view_i >= 1 && view_i <= row - 2 && view_j >= 1 && view_j <= col - 2) {
			//Ž���� ���� �ʾҴٸ�
			if (mazeMark[view_i][view_j] == 0) {
				//�̵� ������ ���� ����
				switch (dir) {
				case 0:mazeMark[i - 1][j] = 1; break;
				case 1:mazeMark[i + 1][j] = 1; break;
				case 2:mazeMark[i][j - 1] = 1; break;
				case 3:mazeMark[i][j + 1] = 1;
				}
				//�̵��� �濡�� ���� ������ ��Ǯ����
				mazeCreating(mazeMark, view_i, view_j);
			}
		}

	}

}

int main(void) {
	int i, j;
	char** mazeMark;

	do {
		printf("�̷��� �� ũ��(3 �̻��� Ȧ��): ");
		scanf_s("%d", &row);
		if (row % 2 == 1)break;
		printf("\n�ٽ� �Է��ϼ���.");
	} while (1);

	do {
		printf("\n�̷��� �� ũ��(3 �̻��� Ȧ��): ");
		scanf_s("%d", &col);
		if (col % 2 == 1)break;
		printf("\n�ٽ� �Է��ϼ���.");
	} while (1);

	//2���� �迭ó�� ����� mazeMark �غ�
	mazeMark = (char**)malloc(sizeof(char*) * row);
	for (i = 0; i < row; i++) mazeMark[i] = (char*)malloc(sizeof(char) * col);

	//��� ����� 0(��)���� ä��
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			mazeMark[i][j] = 0;
		}
	}

	srand((unsigned int)time(NULL));

	//������� ���Ƿ� ����
	i = (int)rand() % (row - 1);
	j = (int)rand() % (col - 1);

	//����� �࿭�� ¦���̸� Ȧ���� ���� 
	if (i % 2 == 0)i++;
	if (j % 2 == 0)j++;

	//����� �ͷ� ��� ȣ��
	mazeCreating(mazeMark, i, j);

	//�̷θ� ����� 
	printf("\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (mazeMark[i][j] == 0) printf("��");
			else printf("��");
		}
		printf("\n");
	}
	printf("\n");

	//�Ա� ��, ���� �Է¹���
	do {

		printf("\n���Ա� ��(0 ~ %d): ", row - 1);
		scanf_s("%d", &i);
		printf("\n���Ա� ��(0 ~ %d): ", col - 1);
		scanf_s("%d", &j);

		if (i == 0 && j > 0 && j < col - 1 && mazeMark[1][j] != 0) break;
		if (i == row - 1 && j > 0 && j < col - 1 && mazeMark[row - 2][j] != 0) break;

		if (i > 0 && i < row - 1 && j == 0 && mazeMark[i][1] != 0) break;
		if (i > 0 && i < row - 1 && j == col - 1 && mazeMark[i][col - 2] != 0) break;

		else printf("\n���ٽ� �Է��ϼ���.\n");

	} while (1);

	mazeMark[i][j] = 1; //�Ա����� ǥ��

	//�ⱸ ��, ���� �Է¹���
	do {

		printf("\n���ⱸ ��(0 ~ %d): ", row - 1);
		scanf_s("%d", &i);
		printf("\n���ⱸ ��(0 ~ %d): ", col - 1);
		scanf_s("%d", &j);

		if (i == 0 && j > 0 && j < col - 1 && mazeMark[1][j] != 0) break;
		if (i == row - 1 && j > 0 && j < col - 1 && mazeMark[row - 2][j] != 0) break;

		if (i > 0 && i < row - 1 && j == 0 && mazeMark[i][1] != 0) break;
		if (i > 0 && i < row - 1 && j == col - 1 && mazeMark[i][col - 2] != 0) break;

		else printf("\n���ٽ� �Է��ϼ���.\n");

	} while (1);

	mazeMark[i][j] = 1; //�ⱸ���� ǥ��

	//�Ա�, �ⱸ�� ������ �̷� ���
	printf("\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (mazeMark[i][j] == 0) printf("��");
			else printf("��");
		}
		printf("\n");
	}

	return 0;

}