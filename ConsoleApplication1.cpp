/*.Вариант 13
Объект для разработки структуры – самолет.
Объявить поля:
– Фамилия, имя отчество пассажира
– Тип самолета
– Номер рейса
– Пункт назначения
– Время отправления (структура с полями часы, минуты)..*/
#include<iostream>
#include <string>
#include <windows.h>
using namespace std;
struct Time {
	short hour;
	short minutes;
};
struct fio {
	string name, lastname, patronymic;//fio
};
struct plane {
	fio namefp;
	char typeofpln;
	int flight;//max 65535
	string city;
	Time tm;


};

int main() {
	short var = 2;//for result
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Вас приветствует компания S-7 Airlines в нашей системе учета данных клентов.\n";
	cout << "Выберете дальнейшее действие: \n 1. Ввод в систему данных о клиенте.\n 2. Вывод данных о всех клиентах." << endl;
	/*COORD cd;
	cd.X = 5;
	cd.Y = 5;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);*/
	cin >> var;
	int lenghtar;//array lenght
	int count = 0;
	bool flag = false;//удача.неудач
	if (var > 1) {
		return 0;
	}
	cout << "Сколько человек будем регистрировать : ";
	cin >> lenghtar;
	plane* info = new plane[lenghtar];

	if (var > 2 && var < 1) {
		return 0;
	}
	else {
		switch (var) {
		case 1:
			system("cls");
			system("color 2");
			for (int i = 0; i < lenghtar; i++) {
				count++;
				flag = true;
				cout << "  Пассажир № " << count << endl;
				cout << "    Имя пассажира :";
				cin >> info[i].namefp.name;
				cout << "    Фамилия пассажира: ";
				cin >> info[i].namefp.lastname;
				cout << "    Отчество пассажира: ";
				cin >> info[i].namefp.patronymic;
				cout << "    Выберите тип самолета и введите его название: " << endl;
				cout << "      -1. Very Light Jets" << endl;
				cout << "      -2. Light Jets" << endl;
				cout << "      -3. Mid-Size Jets" << endl;
				cout << "      -4. Heavy Jets" << endl;
				cout << "      -5. Ultra-Long Range Heavy Jets" << endl;
				cout << "      -6. Business Liner" << endl;
				cout << "      Выбор борта: ";
				cin >> info[i].typeofpln;
				cout << "    Номер рейса(4 цифры): ";
				cin >> info[i].flight;
				cout << "    Пункт назначения: ";
				cin >> info[i].city;
				cout << "    Время отправления: " << endl;
				cout << "      часов: ";
				cin >> info[i].tm.hour;
				cout << "      минут: ";
				cin >> info[i].tm.minutes;
				cout << endl;

			}
		case 2:
			if (!flag) {
				system("cls");
				system("color 4");
				cout << "Нельзя выводить несуществующую информация !)";
				cout << endl << "Выход...." << endl;
				Sleep(800);
				cout << "L   o   l";

				return 0;
			}
		}
		cout << endl << endl << "---------------------------------------------------------------------------------------------------------------------------";
		cout << endl << " ВЫВОД ИЗ БАЗЫ ДАННЫХ " << endl;
		count = 0;
		for (int i = 0; i < lenghtar; i++) {
			count++;
			cout << "  Пассажир № " << count << endl;
			cout << "    Имя пассажира :";
			cout << info[i].namefp.name;
			cout << endl << "    Фамилия пассажира: ";
			cout << info[i].namefp.lastname;
			cout << endl << "    Отчество пассажира: ";
			cout << info[i].namefp.patronymic;
			cout << endl << "    Тип самолета: ";
			switch (info[i].typeofpln) {
			case '1':
				cout << "      -1. Very Light Jets" << endl;
				break;
			case '2':
				cout << "      -2. Light Jets" << endl;
				break;
			case '3':
				cout << "      -3. Mid-Size Jets" << endl;
				break;
			case '4':
				cout << "      -4. Heavy Jets" << endl;
				break;
			case '5':
				cout << "      -5. Ultra-Long Range Heavy Jets" << endl;
				break;
			case '6':
				cout << "      -6. Business Liner" << endl;
				break;
			}

			cout << "    Номер рейса: ";
			cout << info[i].flight;
			cout << endl << "    Пункт назначения: ";
			cout << info[i].city;
			cout << endl << "    Время отправления: " << endl;
			cout << "      часов: ";
			cout << info[i].tm.hour;
			cout << endl << "      минут: ";
			cout << info[i].tm.minutes;
			cout << endl;
		}

	}

	delete[] info;
}