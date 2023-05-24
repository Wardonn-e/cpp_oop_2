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
		print("Меню");
		print("1 - Вставить элемент");
		print("2 - Удалить элемент");
		print("3 - Вывести список");
		print("4 - ");
		print("5 - ");
		print("6 - Выход");
		int c;
		cin >> c;
		switch (c)
		{
		case 1:
			print("1 - В конец");
			print("2 - По индексу");
			cin >> c;
			switch (c)
			{
			case 1:
				_Worker.add_worker(creator());
				break;
			case 2:
				print("Введите индекс");
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
			print("Введите индекс для удаления");
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
	print("Введите имя: ");
	std::string c;
	cin >> c;
	return c;
}
float balance_f() {
	print("Введите баланс: ");
	float c;
	cin >> c;
	return c;
}
float percent_f() {
	print("Введите процент: ");
	float c;
	cin >> c;
	return c;
}
Type type_f() {
	print("1 - Расчетный");
	print("2 - Вкладовый");
	print("3 - Кредитный");
	int c;
	cin >> c;
	switch (c)
	{
	case 1:
		return Type::Расчетный;
		break;

	case 2:
		return Type::Вкладовый;
		break;

	case 3:
		return Type::Кредитный;
		break;
	}
}
EmployeePtr creator() {
	float percent = 0;
	Type type = type_f();
	std::string name = name_f();
	int balance = balance_f();
	if (type != Type::Расчетный){
		percent = percent_f();
	}
	return Employee::create(type, name, balance, percent);
}