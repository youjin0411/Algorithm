#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 6
#define SIZE 21

//�Ʒ� �� �Լ��� ���������̸�, return ������ a, b �Ǵ� p1, p2�� �ٲٸ� ���������� ��

//���� ��������
int compareInt(const void* a, const void* b) {

	return *(int*)a - *(int*)b;

}

//���ڿ� ��������
int compareString(const void* a, const void* b) {

	return strcmp((char*)a, (char*)b);

}

struct student {
	char studentNo[6]; //�й�
	char name[11]; //����
	char telNo[15]; //��ȭ��ȣ
	int age; //����
};

//student ����ü ��������
int compareStruct(const void* a, const void* b) {
	struct student* p1 = (struct student*)a;
	struct student* p2 = (struct student*)b;

	//�й� ����
	return strcmp((char*)p1->studentNo, (char*)p2->studentNo);
	//���� ����
	//return strcmp((char*)p1->name, (char*)p2->name);
	//��ȭ��ȣ ����
	//return strcmp((char*)p1->telNo, (char*)p2->telNo);

}

int main(void) {
	int a[] = { 11, 8, 12, 23, 15, 36, 5, 10, 24 };
	int n1 = sizeof(a) / sizeof(int);

	char b[NUM][SIZE] = { "JAVA", "C/C++", "Python", "JavaScript", "HTML5/CSS3" };

	struct student c[NUM] = {
		{"2201", "����", "010-3355-7878", 17},
		{"2101", "����", "010-1234-5678", 18},
		{"2401", "���", "010-2345-1212", 18},
		{"2301", "���", "010-7638-2351", 18},
		{"2102", "����", "010-4581-6527", 18},
		{"2202", "����", "010-5148-7251", 18} };

	printf("������ ����: ");
	qsort(a, n1, sizeof(int), compareInt);

	for (int i = 0; i < n1; i++) printf("%5d", a[i]);
	printf("\n\n\n");

	printf("�幮�ڿ� ����\n");
	qsort(b, NUM, sizeof(b[0]), compareString);

	for (int i = 0; i < NUM; i++) printf("%s\n", b[i]);
	printf("\n\n");

	printf("�屸��ü ����(�й� ����)\n");
	qsort(c, NUM, sizeof(c[0]), compareStruct);

	for (int i = 0; i < NUM; i++) {
		printf("%s\t", c[i].studentNo);
		printf("%s\t", c[i].name);
		printf("%s\t", c[i].telNo);
		printf("%d\n", c[i].age);
	}
	printf("\n");

	return 0;
}