#include "Telebook.h"
/*
�������.
�������� ���������� "���������� �����". ����������
������� ������ �� �������� (���, �������� �������,
������� �������, ��������� �������, ��������������
���������� � ��������) ������ ���������������� ������. ��������� ����� �����������-�������,
���������-�������, ��������������, inline-���������-�������,
����������� ��������������, ���������� ����������.
����������� ���������� �������� ����������� ������
��� ���. ������������ ������������ ����������� ��������� ����� ���������, ������� ���������,
������ ��������� �� ���, ���������� ���� ���������, ���������
���������� � ���� � ��������� �� �����
*/

/**
* 
* ������� ������ � ������� "counter" �������� "*" 
*/
void draw(int counter);  

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\t������� �2 ����: ������������, �����������"
		<< std::endl << std::endl;
	draw(70);
	// ���������� ��������� � �����
	int countabon = 3;
	// ���������� ����� � �����
	int number = 1;
	// ����� ����
	int number_menu = 0;
	// �������������� ���������� �����
	TeleBook* p = new TeleBook[countabon]
	{
		{number++," ��������� ������ ���������","+79177738764","+73472309331"},
		{number++," ������ ���� ��������","+79324718273","+73472348313"},
		{number++," ������� ���� ����������","+79324718271", "+73472341625"}
	};

	do {
		std::cout << "\t�������� �������� \n";
		std::cout << "\t1: ���������� �����" << std::endl;
		std::cout << "\t2: ���������� ��������" << std::endl;
		std::cout << "\t3: �������� �������� " << std::endl;
		std::cout << "\t4: ����� �������� " << std::endl;
		std::cout << "\t5: ����� �� ��������� " << std::endl;
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
			std::cout << "\t����� ��������� �������, ���� �� ����� \"������\" ���������� ������ \"������\" ��� \"���\")" <<
				std::endl << std::endl;
			std::cout << "\t������� �������, ��� ��� �������� ��������: ";
			std::cin.ignore();
			std::cin.getline(charsearch, 30);
			p->SearchAbon(p, charsearch, countabon);
			_getch;
			break;
		}
		case 5:
			delete[]p;
			std::cout << "\t������� �� ���������" << std::endl;
			_getch;
			break;
		default:
			std::cout << "\t�������� ���������!!!" << std::endl;
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