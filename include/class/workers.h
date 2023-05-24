#pragma once
#include <string>
#include <iostream>
#include <windows.h>

namespace workers {
	enum class Type {
		Расчетный,
		Вкладовый,
		Кредитный
	};

	class Employee;
	using EmployeePtr = Employee*;

	class Employee {
	private:
		Type _type;
		std::string _name;
		float _balance;
		float _percent;
		Employee(Type type, std::string name, int balance, float percent);
	public:
		static EmployeePtr create(Type type, std::string name, int balance, float percent);

		void set_type(Type type);
		Type get_type() const;

		void set_name(std::string name);
		std::string get_name() const;

		int get_balance() const;
		void set_balance(int balance);

		float get_percent() const;
		void set_percent(float percent);

		float calcul() const;
	};

	class Employees {
	private:
		EmployeePtr* _Worker;
		int _size;
	public:
		Employees();
		Employees(const Employees& other);
		int get_size() const;
		EmployeePtr operator[](int index) const;
		Employees& operator=(const Employees& other);
		void add_worker(EmployeePtr f);
		void change_data(EmployeePtr f, int index);
		void delete_person(int index);
		void insert_person(EmployeePtr people, int index);
		void swap(Employees& other);
		~Employees();
	};

	std::ostream& operator<< (std::ostream& out, const EmployeePtr& other);
}