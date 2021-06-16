#include "Telebook.h"
/*
Задание.
Создайте приложение "Телефонная книга". Необходимо
хранить данные об абоненте (ФИО, домашний телефон,
рабочий телефон, мобильный телефон, дополнительная
информация о контакте) внутри соответствующего класса. Наполните класс переменными-членами,
функциями-членами, конструкторами, inline-функциями-членами,
используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память
под ФИО. Предоставьте пользователю возможность добавлять новых абонентов, удалять абонентов,
искать абонентов по ФИО, показывать всех абонентов, сохранять
информацию в файл и загружать из файла
*/

/**
* 
* Функция рисует в консоли "counter" символов "*" 
*/
void draw(int counter);  

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\tВстреча №2 Тема: Конструкторы, деструкторы"
		<< std::endl << std::endl;
	draw(70);
	// Количество абонентов в книге
	int countabon = 3;
	// Порядковый номер в книге
	int number = 1;
	// Номер меню
	int number_menu = 0;
	// Первоначальное заполнение книги
	TeleBook* p = new TeleBook[countabon]
	{
		{number++," Нуриманов Руслан Фаритович","+79177738764","+73472309331"},
		{number++," Иванов Иван Иванович","+79324718273","+73472348313"},
		{number++," Федоров Илья Максимович","+79324718271", "+73472341625"}
	};

	do {
		std::cout << "\tВыберите действие \n";
		std::cout << "\t1: Телефонная книга" << std::endl;
		std::cout << "\t2: Добавление абонента" << std::endl;
		std::cout << "\t3: Удаление абонента " << std::endl;
		std::cout << "\t4: Поиск абонента " << std::endl;
		std::cout << "\t5: Выход из программы " << std::endl;
		std::cout << "\t ==>";
		std::cin >> number_menu;
		switch (number_menu)
		{
		case 1:
			for (size_t i = 0; i < countabon; i++)
			{
				p[i].ShowPhoneBook();
			}
			draw(70);
			_getch;
			break;
		case 2:
			p->AddAbon(p, &countabon, &number);
			_getch;
			break;
		case 3:
			p->DelAbon(p, &countabon, &number);
			_getch;
			break;
		case 4: {
			char charsearch[30] = "";
			std::cout << "\tПоиск учитывает регистр, если не нашли \"петров\" попробуйте ввести \"Петров\" или \"етр\")" <<
				std::endl << std::endl;
			std::cout << "\tВведите Фамилию, имя или отчество абонента: ";
			std::cin.ignore();
			std::cin.getline(charsearch, 30);
			p->SearchAbon(p, charsearch, countabon);
			_getch;
			break;
		}
		case 5:
			delete[]p;
			std::cout << "\tВыходим из программы" << std::endl;
			_getch;
			break;
		default:
			std::cout << "\tВыберите правильно!!!" << std::endl;
			}
		} while (number_menu != 5);
	return 0;
	}
	

void draw(int counter) {
	for (int i = 0; i < counter; i++) {
		std::cout << "*";
	}
	std::cout << '\n';
}