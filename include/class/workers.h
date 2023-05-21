#pragma once
#include <string>
#include <iostream>
#include <windows.h>

namespace workers {
	enum class Type {
		Lecture = 0,
		Practic = 1,
		Laboratory = 2
	};
	enum class Name {
		ООП = 0,
		МатАн = 1,
		АлГем = 2,
		История = 3,
		Физра = 4
	};

	class Employee;
	using EmployeePtr = Employee*;

	class Employee {
	private:
		Type _type;
		Name _name;
		int _count_hours;
		int _count_groups;
		Employee(Type type, Name name, int count_hours, int count_groups);
	public:
		static EmployeePtr create(Type type, Name name, int count_hours, int count_groups);

		void set_type(Type type);
		Type get_type() const;

		void set_name(Name name);
		Name get_name() const;

		void set_count_groups(int count);
		int get_count_groups() const;

		void set_count_hours(int count);
		int get_count_hours() const;
		
		int calcul() const;
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

	int search_max_by_name(const Employees& _Worker, Name name);
	std::string search_max_hours(const Employees& _Worker);
}