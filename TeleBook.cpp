#include "TeleBook.h"
/**
* ����������� ��� ����������
*/
TeleBook::TeleBook()
{
	number = 0;
	FIO = new char[3]{ "No" };
	mobilPhone = new char[3]{ "No" };
	homePhone = new char[3]{"No"};
}
/**
* ����������� � �����������
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
* ����������� �����������
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
* ������� ������ �������� � ���������� �����
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
				std::cout << "�/� " << " | " << " ������� " << std::endl;
			}
			std::cout << p[i].number << " . " << p[i].FIO << " . "
				<< p[i].mobilPhone << " . " << p[i].homePhone << std::endl;
		}
	}
	if (countsearch < 1)
	{
		std::cout << " ������� �� ������" << std::endl;
	}
}
/**
* ������� ���������� �������� � ���������� �����
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
	std::cout << "\t������� ���: ";
	std::cin.getline(buff,80);
	_fio = strlen(buff);
	temp[*countabon].FIO = new char[_fio + 1];
	strcpy(temp[* countabon].FIO, buff);
	std::cout << std::endl;

	std::cout << "\t������� ��������� ����� �������� : ";
	std::cin.getline(buff, 80);
	_mobilPhone = strlen(buff);
	temp[*countabon].mobilPhone = new char[_mobilPhone + 1];
	strcpy(temp[*countabon].mobilPhone, buff);
	std::cout << std::endl;

	std::cout << "\t������� �������� ����� �������� : ";
	std::cin.getline(buff, 80);
	_homePhone = strlen(buff);
	temp[*countabon].homePhone = new char[_homePhone + 1];
	strcpy(temp[*countabon].homePhone, buff);
	std::cout << std::endl;
	(*countabon)++;
	(*_number)++;
	delete[] p;
	p = temp;
	std::cout << "\t����������� �������...\n";
}
/**
* ������� �������� �������� �� ���������� �����
*/
void TeleBook::DelAbon(TeleBook*& p, int* countabon, int* _number)
{
	char _fio, _mobilPhone, _homePhone;
	int numbertmp = *_number;
	int p_count = 0;
	// ���������� ����� ��� ��������
	int delnumber;
	// ������� ��� �� ������ �������
	int countdel = 0;
	std::cout << "\t������� ���������� ����� �������� ��� ��������: ";
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
		std::cout << "\t��������� �������... \n";
	}
	delete[]p;
	p = temp;
	if (!countdel)
	{
		std::cout << "\t������� �� ������ \n";
	}
}
/**
* ���������� ������ 
*/
TeleBook::~TeleBook()
{
	delete[]FIO;
	delete[]mobilPhone;
	delete[]homePhone;
}
/**
* ����� �� ����� ��������� ���������� �����
*/
void TeleBook::ShowPhoneBook()
{
	std::cout << number << " . ";
	std::cout << " ��� : " << FIO << " ���. ������� : " << mobilPhone << " ���. ������� : " << homePhone;
	std::cout << std::endl;
}
/**
* ������� ����� �������
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
