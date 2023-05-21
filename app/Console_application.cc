#include <class/workers.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
using namespace workers;

void print(std::string x);
EmployeePtr creator();
Name name_f();
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
		print("4 - Найти кол-во оплачиваемых часов для заданной дисциплины");
		print("5 - Определение названия первой дисциплины с максимальным количеством оплачиваемых часов");
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
		case 4:
			cout << search_max_by_name(_Worker, name_f()) << endl;
			break;
		case 5:
			print(search_max_hours(_Worker));
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
Name name_f() {
	print("1 - ООП");
	print("2 - МатАн");
	print("3 - АлГем");
	print("4 - История");
	print("5 - Физра");
	int c;
	cin >> c;
	switch (c)
	{
		case 1:
			return Name::ООП;
			break;

		case 2:
			return Name::МатАн;
			break;

		case 3:
			return Name::АлГем;
			break;
		case 4:
			return Name::История;
			break;

		case 5:
			return Name::Физра;
			break;
	}
}
int hours_f() {
	print("Введите количество часов");
	int c;
	cin >> c;
	return c;
}
int count_f() {
	print("Введите количество групп");
	int c;
	cin >> c;
	return c;
}
Type type_f() {
	print("1 - Лекция");
	print("2 - Практика");
	print("3 - Лабораторная работа");
	int c;
	cin >> c;
	switch (c)
	{
	case 1:
		return Type::Lecture;
		break;

	case 2:
		return Type::Practic;
		break;

	case 3:
		return Type::Laboratory;
		break;
	}
}
EmployeePtr creator() {
	Type type = type_f();
	Name name = name_f();
	int hours = hours_f();
	int count = count_f();
	return Employee::create(type, name, hours, count);
}