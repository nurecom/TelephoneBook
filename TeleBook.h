#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <iomanip>

class TeleBook
{

private:

	int number;
	char* FIO;
	char* mobilPhone;
	char* homePhone;

public:
	TeleBook();
	TeleBook(int _number, const char* _fio, const char* _mobilPhone,
		const char* _homePhone);
	// конструктор копирования
	TeleBook(const TeleBook& obj);
	// поиск абонента
	void SearchAbon(TeleBook* p, char const* charsearch, int const countabon);
	// добавление абонента
	void AddAbon(TeleBook*& p, int* countabon, int* _number);
	// удаление абонента
	void DelAbon(TeleBook*& p, int* countabon, int* _number);
	// деструктор
	~TeleBook();
	// печать книги абонентов
	void ShowPhoneBook();
	int Getnumber();
	char GetFIO();
	char GetmobilPhone();
	char GethomePhone();
};


