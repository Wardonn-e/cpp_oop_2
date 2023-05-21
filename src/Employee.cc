#include <class/workers.h>

#include <cassert>
#include <stdexcept>
#include <ctime>
#include <iostream>

using namespace std;
using namespace workers;


EmployeePtr Employee::create(Type type, Name name, int count_hours, int count_groups){
	return new Employee(type, name, count_hours, count_groups);
}

Employee::Employee(Type type, Name name, int count_hours, int count_groups) : _type(type), _name(name), _count_hours(count_hours), _count_groups(count_groups) {}

Type Employee::get_type() const {
	return _type;
}

void Employee::set_type(Type type) {
	_type = type;
}

Name Employee::get_name() const {
	return _name;
}

void Employee::set_name(Name worker_name) {
	_name = worker_name;
}

int Employee::get_count_hours() const {
	return _count_hours;
}

void Employee::set_count_hours(int count) {
	_count_hours = count;
}

int Employee::get_count_groups() const {
	return _count_groups;
}

void Employee::set_count_groups(int count) {
	_count_groups = count;
}


int Employee::calcul() const {
	switch (_type)
	{
		case(Type::Lecture):
			return _count_hours;
			break;
		case(Type::Practic):
			return _count_hours * _count_groups;
			break;
		case(Type::Laboratory):
			return _count_hours * _count_groups * 2;
			break;
		default:
			throw runtime_error("[Function::compute_derivative] Invalid function type.");
	}
}