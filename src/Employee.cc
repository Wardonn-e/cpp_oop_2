#include <class/workers.h>
#include <cassert>
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace workers;


EmployeePtr Employee::create(Type type, std::string _name, int balance, float percent) {
	return new Employee(type, _name, balance, percent);
}

Employee::Employee(Type type, std::string name, int balance, float percent) : _type(type), _name(name), _balance(balance), _percent(percent) {}

Type Employee::get_type() const {
	return _type;
}

void Employee::set_type(Type type) {
	_type = type;
}

std::string Employee::get_name() const {
	return _name;
}

void Employee::set_name(std::string worker_name) {
	_name = worker_name;
}

int Employee::get_balance() const {
	return _balance;
}

void Employee::set_balance(int balance)  {
	_balance = balance;
}
void Employee::set_percent(float percent) {
	_percent = percent;
}
float Employee::get_percent() const {
	return _percent;
}


float Employee::calcul() const {
	switch (_type)
	{
		case(Type::Расчетный):
			return _balance;
			break;
		case(Type::Вкладовый):
			return _balance + (_balance * _percent / 12 / 100);
			break;
		case(Type::Кредитный):
			if (_balance < 0) {
				return	_balance + (_balance * _percent / 12 / 100);
			}
			else {
				return	_balance;
			}
			break;
		default:
			throw runtime_error("[Function::compute_derivative] Invalid function type.");
	}
}