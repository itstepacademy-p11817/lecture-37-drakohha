#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int main() {
	struct person_t {
		char login[20];
		char pass[20];
	};

	person_t human[5];
	person_t etalon;



	setlocale(LC_ALL, "Rus");
	FILE *fp;
	fopen_s(&fp, "file1.txt", "w+b");
	if (fp != NULL) {
		fseek(fp, 0, SEEK_SET);
		char login[20] = "drakohha";
		char pass[20]="drakonlol4";
		fwrite(login, 20, 1, fp);
		fwrite(pass, 20, 1, fp);
		fclose(fp);
		printf("\n ������ ���� � �������� � ����������� \n");
	}
	else {
		printf("\n ������ �������� ����� \n");
	}

	fopen_s(&fp, "file1.txt", "rb");
	if (fp != NULL) {
		fseek(fp, 0, SEEK_SET);
		fread(etalon.login, 20, 1, fp);
		fread(etalon.pass, 20, 1, fp);
		fclose(fp);
	}
	else {
		printf("\n ������ �������� ����� \n");
	}

	for (int i = 0; i < 20; i++) {
		if (etalon.login[i] == ' ') {
			etalon.login[i] = '\0';
			break;
		}
	}
	for (int i = 0; i < 20; i++) {
		if (etalon.pass[i] == ' ') {
			etalon.pass[i] = '\0';
			break;
		}
	}
	
	printf("\n (1)������� ����� � ������ ��� (2)������� �������� ����� ������������  \n");
	int flag;
	//while (getchar() != '\n');
	scanf_s("%d", &flag);
	if (flag == 1) {
		printf("\n ������� ����� \n");
		while (getchar() != '\n');
		gets_s(human[0].login, 20);
		printf("\n ������� �������� \n");
		//while (getchar() != '\n');
		gets_s(human[0].pass, 20);

		printf("\n ������ ������ � ������ \n");
		if (strcmp(etalon.login,human[0].login)==0 && strcmp(etalon.pass, human[0].pass)==0) {
			printf("���� ������, �� ����� ��� ���������������!!");
			system("Pause");
		}
		else {
			printf("�������� ����, �������� ������������ ����� ���� �������� ������ ������������");
			system("Pause");
		}
	
	}
	else if (flag == 2) {

	}
	else {
		return 0;
	}
	system("Pause");
	return 0;
}






/*

������� ������� ����������. ��� ������ ������� � ������ ��� ��������� ��� ������ �� ���������.
���� � ������� ������ �� ������ � ������
������� ����������� ������ ������������
������� ������� ��������������
������������� ����� ��������� ����� � �������
������������ ����� ������������� ������ ��������� ���� �������� ����� ������� �� ���� (��� ��������� ������������ ��� ������) � ����� ��������� �����
������������ ����� ����������� ������ ���� ������� � ����
�������������� ����� ������ ����� ������������ ���� ����� �����. ����������� ����������� ������ ������ ���� � ��������� ������� ( ��������� ��� ����� � ��������� ���� ��������)
� ����� ���������� ������ �� ����� ����� ����� ����� � ���� ������� ����
����������� ����� � 5 ���� ��� ������ ������������


������ ��:
��� ����� ����. ������� ������� ����� ����� ��� ���������� � ��� ��� ������������ �����. ������ ������������ ���� ���������� � ������ �����.


*/