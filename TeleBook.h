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
	// ����������� �����������
	TeleBook(const TeleBook& obj);
	// ����� ��������
	void SearchAbon(TeleBook* p, char const* charsearch, int const countabon);
	// ���������� ��������
	void AddAbon(TeleBook*& p, int* countabon, int* _number);
	// �������� ��������
	void DelAbon(TeleBook*& p, int* countabon, int* _number);
	// ����������
	~TeleBook();
	// ������ ����� ���������
	void ShowPhoneBook();
	int Getnumber();
	char GetFIO();
	char GetmobilPhone();
	char GethomePhone();
};


