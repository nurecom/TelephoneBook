#include "TeleBook.h"
/**
* Конструктор без параметров
*/
TeleBook::TeleBook()
{
	number = 0;
	FIO = new char[3]{ "No" };
	mobilPhone = new char[3]{ "No" };
	homePhone = new char[3]{"No"};
}
/**
* Конструктор с параметрами
*/
TeleBook::TeleBook(int _number, const char* _fio, const char* _mobilPhone, const char* _homePhone)
{
	int count_fio, count_mobilPhone, count_homePhone;
	count_fio = strlen(_fio);
	count_mobilPhone = strlen(_mobilPhone);
	count_homePhone = strlen(_homePhone);
	FIO = new char[count_fio + 1];
	mobilPhone = new char[count_mobilPhone + 1];
	homePhone = new char[count_homePhone + 1];
	number = _number;
	strcpy(FIO, _fio);
	strcpy(mobilPhone, _mobilPhone);
	strcpy(homePhone, _homePhone);
}
/**
* Конструктор копирования
*/
TeleBook::TeleBook(const TeleBook& obj)
{
	FIO = new char[strlen(obj.FIO) + 1];
	mobilPhone = new char[strlen(obj.mobilPhone) + 1];
	homePhone = new char[strlen(obj.homePhone) + 1];
	number = obj.number;
	strcpy (FIO, obj.FIO);
	strcpy(mobilPhone, obj.mobilPhone);
	strcpy(homePhone, obj.homePhone);
}
/**
* Функция поиска абонента в телефонной книге
*/
void TeleBook::SearchAbon(TeleBook* p, char const* charsearch, int const countabon)
{
	int countsearch = 0;
	for (int i = 0; i < countabon; i++)
	{
		char* temp = strstr(p[i].FIO, charsearch);
		if (temp)
		{
			countsearch++;
			if (countsearch == 1)
			{
				std::cout << "П/№ " << " | " << " Абонент " << std::endl;
			}
			std::cout << p[i].number << " . " << p[i].FIO << " . "
				<< p[i].mobilPhone << " . " << p[i].homePhone << std::endl;
		}
	}
	if (countsearch < 1)
	{
		std::cout << " Абонент не найден" << std::endl;
	}
}
/**
* Функция добавления абонента в телефонную книгу
*/
void TeleBook::AddAbon(TeleBook*& p, int* countabon, int* _number)
{
	TeleBook* temp = new TeleBook[*countabon + 1];
	char _fio, _mobilPhone, _homePhone;

	int numbertmp = *_number;
	for (int i = 0; i < *countabon; i++)
	{
		temp[i].number = p[i].number;
		_fio = strlen(p[i].FIO);
		_mobilPhone = strlen(p[i].mobilPhone);
		_homePhone = strlen(p[i].homePhone);
		temp[i].FIO = new char[_fio + 1];
		temp[i].mobilPhone = new char[_mobilPhone+1];
		temp[i].homePhone = new char[_homePhone + 1];
		strcpy(temp[i].FIO, p[i].FIO);
		strcpy(temp[i].mobilPhone, p[i].mobilPhone);
		strcpy(temp[i].homePhone, p[i].homePhone);
	}

	temp[*countabon].number = numbertmp;
	
	char buff[80];
	std::cin.ignore();
	std::cout << "\tВведите ФИО: ";
	std::cin.getline(buff,80);
	_fio = strlen(buff);
	temp[*countabon].FIO = new char[_fio + 1];
	strcpy(temp[* countabon].FIO, buff);
	std::cout << std::endl;

	std::cout << "\tВведите мобильный номер телефона : ";
	std::cin.getline(buff, 80);
	_mobilPhone = strlen(buff);
	temp[*countabon].mobilPhone = new char[_mobilPhone + 1];
	strcpy(temp[*countabon].mobilPhone, buff);
	std::cout << std::endl;

	std::cout << "\tВведите домашний номер телефона : ";
	std::cin.getline(buff, 80);
	_homePhone = strlen(buff);
	temp[*countabon].homePhone = new char[_homePhone + 1];
	strcpy(temp[*countabon].homePhone, buff);
	std::cout << std::endl;
	(*countabon)++;
	(*_number)++;
	delete[] p;
	p = temp;
	std::cout << "\tИзмененения внесены...\n";
}
/**
* Функция удаления абонента из телефонной книги
*/
void TeleBook::DelAbon(TeleBook*& p, int* countabon, int* _number)
{
	char _fio, _mobilPhone, _homePhone;
	int numbertmp = *_number;
	int p_count = 0;
	// Порядковый номер для удаления
	int delnumber;
	// Счетчик был ли удален абонент
	int countdel = 0;
	std::cout << "\tВведите порядковый номер абонента для удаления: ";
	std::cin >> delnumber;
	std::cin.ignore();
	for (int i = 0; i < *countabon; i++)
	{
		if (p[i].number == delnumber)
		{
			(*countabon)--;
			countdel++;
		}
	}
	TeleBook* temp = new TeleBook[*countabon];
	for (size_t i = 0; i < *countabon; i++)
	{
		if (p[p_count].number == delnumber)
		{
			p_count++;
			i--;
		}
		else if (p[p_count].number != delnumber)
		{
			temp[i].number = p[p_count].number;
			_fio = strlen(p[p_count].FIO);
			_mobilPhone = strlen(p[p_count].mobilPhone);
			_homePhone = strlen(p[p_count].homePhone);
			temp[i].FIO = new char[_fio + 1];
			temp[i].mobilPhone = new char[_mobilPhone + 1];
			temp[i].homePhone = new char[_homePhone + 1];
			strcpy(temp[i].FIO,p[p_count].FIO);
			strcpy(temp[i].mobilPhone,p[p_count].mobilPhone);
			strcpy(temp[i].homePhone,p[p_count].homePhone);
			p_count++;
		}
	}
	if (countdel)
	{
		std::cout << "\tИзменения внесены... \n";
	}
	delete[]p;
	p = temp;
	if (!countdel)
	{
		std::cout << "\tАбонент не найден \n";
	}
}
/**
* Деструктор класса 
*/
TeleBook::~TeleBook()
{
	delete[]FIO;
	delete[]mobilPhone;
	delete[]homePhone;
}
/**
* Вывод на экран абонентов телефонной книги
*/
void TeleBook::ShowPhoneBook()
{
	std::cout << number << " . ";
	std::cout << " ФИО : " << FIO << " Моб. телефон : " << mobilPhone << " Дом. телефон : " << homePhone;
	std::cout << std::endl;
}
/**
* Геттеры типов классса
*/
int TeleBook::Getnumber()
{
	return 0;
}

char TeleBook::GetFIO()
{
	return 0;
}

char TeleBook::GetmobilPhone()
{
	return 0;
}

char TeleBook::GethomePhone()
{
	return 0;
}
