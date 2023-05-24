#include <class/workers.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
using namespace workers;

void print(std::string x);
EmployeePtr creator();
std::string name_f();
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Employees _Worker;
	bool f_1 = 1;
	while (f_1) {
		print("����");
		print("1 - �������� �������");
		print("2 - ������� �������");
		print("3 - ������� ������");
		print("4 - ");
		print("5 - ");
		print("6 - �����");
		int c;
		cin >> c;
		switch (c)
		{
		case 1:
			print("1 - � �����");
			print("2 - �� �������");
			cin >> c;
			switch (c)
			{
			case 1:
				_Worker.add_worker(creator());
				break;
			case 2:
				print("������� ������");
				int index;
				cin >> index;
				_Worker.insert_person(creator(), index);
				break;
			}

			break;
		case 2:
			for (int i = 0; i < _Worker.get_size(); i++) {
				cout << _Worker[i];
			}
			print("������� ������ ��� ��������");
			cin >> c;
			_Worker.delete_person(c);
			for (int i = 0; i < _Worker.get_size(); i++) {
				cout << _Worker[i];
			}
			break;
		case 3:
			for (int i = 0; i < _Worker.get_size(); i++) {
				cout << _Worker[i];
			}
			break;
		case 6:
			return 0;
			break;
		}
	}
}

void print(std::string x) {
	cout << x << endl;
}
std::string name_f() {
	print("������� ���: ");
	std::string c;
	cin >> c;
	return c;
}
float balance_f() {
	print("������� ������: ");
	float c;
	cin >> c;
	return c;
}
float percent_f() {
	print("������� �������: ");
	float c;
	cin >> c;
	return c;
}
Type type_f() {
	print("1 - ���������");
	print("2 - ���������");
	print("3 - ���������");
	int c;
	cin >> c;
	switch (c)
	{
	case 1:
		return Type::���������;
		break;

	case 2:
		return Type::���������;
		break;

	case 3:
		return Type::���������;
		break;
	}
}
EmployeePtr creator() {
	float percent = 0;
	Type type = type_f();
	std::string name = name_f();
	int balance = balance_f();
	if (type != Type::���������){
		percent = percent_f();
	}
	return Employee::create(type, name, balance, percent);
}