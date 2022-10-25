#include <stdio.h>
#include <string.h>

#define SIZE 100

int stringSearch(char s[], char p[]) {
	int i, sl, pl;

	sl = strlen(s);
	pl = strlen(p);
	for (i = 0; i <= sl - pl; i++) {
		if (strncmp(s + i, p, pl) == 0) {
			return i;
		}
	}
	return -1;
}

int main(void) {
	char* s = "mirim meister newmedia interactive solution";
	char p[SIZE] = { '\0' }, * sp1;
	int sp2;

	printf("�־��� ���ڿ�: %s\n\n", s);
	printf("ã�� ���ڿ� �Է�: ");
	gets_s(p, SIZE); //�ִ� 99���ڱ��� �Է�

	//strncmp()�Լ� ����ϴ� ���
	printf("\nstrncmp()�Լ� ����Ͽ� ");
	if ((sp2 = stringSearch(s, p)) == -1)
		printf("ã�� ���ڿ��� �����ϴ�.\n");
	else
		printf("\"%s\"�� %d��ġ���� ã�ҽ��ϴ�.\n", p, sp2);

	//strstr()�Լ� ����ϴ� ���
	printf("\nstrstr()�Լ� ����Ͽ� ");
	if ((sp1 = strstr(s, p)) == NULL)
		printf("ã�� ���ڿ��� �����ϴ�.\n");
	else
		printf("\"%s\"�� %d��ġ���� ã�ҽ��ϴ�.\n", p, sp1 - s);

	return 0;

}