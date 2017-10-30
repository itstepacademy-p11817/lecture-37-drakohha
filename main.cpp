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
		printf("\n Создан файл с логинами и пассвордами \n");
	}
	else {
		printf("\n Ошибка открытия файла \n");
	}

	fopen_s(&fp, "file1.txt", "rb");
	if (fp != NULL) {
		fseek(fp, 0, SEEK_SET);
		fread(etalon.login, 20, 1, fp);
		fread(etalon.pass, 20, 1, fp);
		fclose(fp);
	}
	else {
		printf("\n Ошибка открытия файла \n");
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
	
	printf("\n (1)Введите логин и пароль или (2)введите создание новго пользователя  \n");
	int flag;
	//while (getchar() != '\n');
	scanf_s("%d", &flag);
	if (flag == 1) {
		printf("\n Введите логин \n");
		while (getchar() != '\n');
		gets_s(human[0].login, 20);
		printf("\n Введите пассворд \n");
		//while (getchar() != '\n');
		gets_s(human[0].pass, 20);

		printf("\n Сверка логина и пароля \n");
		if (strcmp(etalon.login,human[0].login)==0 && strcmp(etalon.pass, human[0].pass)==0) {
			printf("ВВод верный, вы вошли под администратором!!");
			system("Pause");
		}
		else {
			printf("Неверный ввод, проверте правильность ввода либо создайте нового пользователя");
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

создать систему библиотека. Все данные хранить в файлах или сохранять при выходе из программы.
Вход в систему только по логину и паролю
Создать регистрацию нового пользователя
Создать аккаунт администратора
администратор может добавлять книги в каталог
пользователь может просматривать список доступных книг помечать книги которые он взял (они становять недоступными для других) а также возращать книги
пользователь может просаотреть список книг которые у него
Админимстратор может видеть какой пользователь взял какую книгу. Возможность просмотреть полный списко книг с указанием статуса ( свободная или взята с указанием ника человека)
а также релизовать фильтр по людям чтобы админ видел у кого сколько книг
реализовать лимит в 5 книг для одного пользователя


второе зд:
дан текст файл. Необход созлать новый убрав или зацензурив в нем все неприемлемые слова. список неприеилемых слов находиться в другом файле.


*/