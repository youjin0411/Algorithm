//���� �Լ� ���� �ڵ�. �浹 �ذ� ����� ������ ü��

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//�л� ������ ����ü
struct member{
	int student_No;
	char name[9];
	char phoneNo[12];
	char email[30];
	struct member *link;
};

int divider; //���� ��

//�ؽ� ���̺� �����ϴ� �Լ�
void storeMember(struct member *bucket, struct member *overflowArea, int m, int n){
	FILE *f;
	static int overflowAddr = 0;//���� ���� ����ϰ� �־�� �ϹǷ� static���� �غ�
	struct member someMem, *ptr;
	int addr, cnt = 0;

	//�ؽ� ���̺� ������ ������ �����͸� nameList.txt�� �غ��� ����
	fopen_s(&f, "../nameList.txt", "r");
	
	printf("\n�ؽ� ���̺� �� ��° �����ߴ����� ���\n");

	//nameList.txt�� �غ�� �����͸� �ϳ��� �о�ͼ� �ؽ� ���̺� ������
	do{

		//����ü �ϳ��� �о� ��
		fscanf_s(f, "%d\t%s\t%s\t%s\n", &someMem.student_No, someMem.name, 9, someMem.phoneNo, 12, someMem.email, 30);
		
		//�����Լ� �����Ͽ� ����� ���� ��ġ ����
		addr = (someMem.student_No % divider) * m / divider;
		
		//������ ���� ��ġ ����
		ptr = bucket + addr;
		
		//�浹�� �߻��Ͽ��ٸ�(���� ��ġ�� �̹� �����Ͱ� �ִٸ�)
		if(ptr -> name[0] != '\0'){

			printf("�й� %d, �ּ� %d���� �浹�� �߻��Ͽ� ���� ������ �����ϰ� ������!\n", someMem.student_No, addr);
			
			//���� �������� ������ ������ ������ �̵��� ����
			while(ptr->link != NULL) ptr = ptr->link;
			
			//���� ������ ���� ������ ���� ����Ʈ�� ���� ������
			ptr->link = overflowArea + overflowAddr;
			
			//���� ������ �ʰ��ϸ� �� �̻� ���� �Ұ�
			if(++overflowAddr > n){
				printf("\n���񿵿� �ʰ��� ���� �Ұ�!\n");
				return; //�Լ� ����
			}

			//���� ������ ���� ���� �������� �̵�
			ptr = ptr -> link;

		}
		else printf("�й� %d, %d��° ������!\n", someMem.student_No, addr);

		//nameList.txt���� �о� �� ����ü ����� �ؽ� ���̺� ������
		ptr->student_No = someMem.student_No;
		strcpy_s(ptr->name, 9, someMem.name);
		strcpy_s(ptr->phoneNo, 12, someMem.phoneNo);
		strcpy_s(ptr->email, 30, someMem.email);
		ptr->link = NULL;

		cnt++;

	}while(cnt < m);

}

//�˻� �Լ�
void searchMember(struct member *bucket, int m, int n){
	int addr, no, cnt = 0;
	char yn;
	struct member *ptr;

	do{
		printf("\nã�� �й�: ");
		scanf_s("%d", &no);
		getchar();

		addr = (no % divider) * m / divider;

		ptr = bucket + addr;

		while(ptr != NULL){

			if(ptr-> student_No == no){
				if(cnt == 0) printf("\n%d ��ġ���� ���� ã��!", addr);
				else printf("\n%d�� �����Ͽ� ã��!", cnt);

				printf("\nã�� �����ʹ� %d, %s, %s, %s\n", ptr->student_No, ptr->name, ptr->phoneNo, ptr->email);
				break;//�ݺ��� ��������
			}

			ptr=ptr->link;

			cnt++;
		}

		if(ptr == NULL) printf("���� ������!\n");

		printf("\n��� �˻�?(y/n) : ");
		scanf_s("%c", &yn, 1);
		getchar();

		cnt = 0;

	}while(yn == 'y');

}

int HashingFunctionDivider(int memberNo){
	int i;

	//�Ҽ� �Ǵ� �Ҽ��� ����� ����(20���� ���� �Ҽ��� ����� ���� �ʴ� ��) ����
	do{

		for(i = 2; i <= 19; i++)
			if(memberNo % i == 0) break;

		if(i == 20) return memberNo;

		memberNo++;

	}while(1);

}

int main(void){
	int m = 120; //m�� ������ ����
	int i, n;
	struct member *bucket, *overflowArea;

	printf("Hash Table ����, �ؽ� �Լ��� ���� �Լ�, �浹 �ذ� ����� ������ ü��\n\n");
	printf("������ ��: %d\n\n", m);
	printf("������: 70%%\n\n");

	n = (int)(m * 3 / 7 );//���� ������ ũ��

	divider = HashingFunctionDivider(m);

	printf("���� ��: %d\n", divider);

	bucket = (struct member *)calloc(m, sizeof(struct member));
	overflowArea = (struct member *)calloc(n, sizeof(struct member));

	//������ ���� �ʱ�ȭ
	for(i = 0; i < m; i++) bucket[i].name[0] = '\0';

	//���� ���� �ʱ�ȭ
	for(i = 0; i < n; i++) overflowArea[i].name[0] = '\0';

	//�غ�� ���� ���ʷ� �о�ͼ� �й��� key�� �Ͽ� �ؽ� ���̺� ����
	storeMember(bucket, overflowArea, m, n);

	//�й��� �Է� �޾� �ؽ� ���̺��� ã�� 
	searchMember(bucket, m, n);

	//������ ������ ���� ������ �޸� ������ ������
	free(bucket);
	free(overflowArea);

	return 0;
}