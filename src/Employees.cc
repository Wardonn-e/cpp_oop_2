#include <class/workers.h>
#include <stdexcept>

using namespace workers;
using namespace std;

Employees::Employees() : _Worker(nullptr), _size(0) {}

Employees::Employees(const Employees& other) :
	_Worker(new EmployeePtr[other._size]),
	_size(other._size)
{
	for (int i = 0; i < _size; i++) {
		_Worker[i] = new Employee(*other._Worker[i]);
	}
}
int Employees::get_size() const {
	return _size;
}
EmployeePtr Employees :: operator[](const int index) const {
	if (index < 0 || _size <= index) {
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	return _Worker[index];
}
Employees& Employees::operator=(const Employees& other) {
	Employees copy(other);
	copy.swap(*this);
	return *this;
}
void Employees::add_worker(const EmployeePtr f) {
	auto new_Employee = new EmployeePtr[_size + 1];
	for (int i = 0; i < _size; i++) {
		new_Employee[i] = _Worker[i];
	}
	delete[] _Worker;

	new_Employee[_size] = f;

	_Worker = new_Employee;

	++_size;
}
void Employees::delete_person(int index) {
	if (index < 0 || _size < index) {
		throw out_of_range("[Employees::operator[]] Index is out of range.");
	}
	auto new_Employee = new EmployeePtr[_size - 1];
	for (int i = 0; i < index; i++) {
		new_Employee[i] = _Worker[i];
	}
	for (int i = index; i <= _size - 2; i++) {
		new_Employee[i] = _Worker[i + 1];
	}
	delete[] _Worker;
	_Worker = new_Employee;
	_size--;
}
void Employees::insert_person(EmployeePtr people, int index) {
	if (index < 0 || _size < index) {
		throw out_of_range("[Employees::operator[]] Index is out of range.");
	}
	auto new_Employee = new EmployeePtr[_size + 1];
	for (int i = 0; i < index; i++) {
		new_Employee[i] = _Worker[i];
	}
	new_Employee[index] = people;
	for (int i = (index + 1); i < (_size + 1); i++) {
		new_Employee[i] = _Worker[i - 1];
	}
	delete[] _Worker;
	_Worker = new_Employee;
	_size++;
}
void Employees::change_data(const EmployeePtr f, int index) {
	if (index < 0 || _size < index) {
		throw out_of_range("[Employees::operator[]] Index is out of range.");
	}
	_Worker[index] = f;
}
void Employees::swap(Employees& other) {
	std::swap(this->_Worker, other._Worker);
	std::swap(this->_size, other._size);
}
Employees::~Employees() {
	for (int i = 0; i < _size; ++i) {
		delete _Worker[i];
		cout << "ÐÀÁÎÒÍÈÊ ÈÇ ÑÏÈÑÊÀ ÏÎÄ ÍÎÌÅÐÎÌ " << i + 1 << " ÑÒ¨ÐÒ" << endl;
	}
	delete[] _Worker;
	cout << "ÑÏÈÑÎÊ ÓÄÀËÅÍ";
}


std::string workers::search_max_hours(const Employees& _Worker) {
	int max = -1;
	int max_index = -1;
	std::string name[] = { "ÎÎÏ", "ÌàòÀí", "ÀëÃåì", "Èñòîðèÿ", "Ôèçðà" };
	int count [] = { 0, 0, 0, 0, 0 };
	for (int i = 0; i < _Worker.get_size(); i++) {
		count[static_cast<int>(_Worker[i]->get_name())] += _Worker[i]->calcul();
	}
	for (int i = 0; i < 5; i++) {
		if (count[i] > max) {
			max = count[i];
			max_index = i;
		}

	}
	return name[max_index];
}


int workers::search_max_by_name(const Employees& _Worker, Name name) {
	int value = 0;
	for (int i = 0; i < _Worker.get_size(); i++) {
		if (_Worker[i]->get_name() == name) {
			value += _Worker[i]->calcul();
		}
	}
	return value;
}


ostream& workers::operator<< (std::ostream& out, const EmployeePtr& other) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string name[] = { "ÎÎÏ", "ÌàòÀí", "ÀëÃåì", "Èñòîðèÿ", "Ôèçðà"};
	std::string type[] = { "Ëåêöèÿ", "Ïðàêòèêà", "Ëàáîðàòîðíàÿ ðàáîòà"};
	out << type[static_cast<int>(other->get_type())] << "\t" << name[static_cast<int>(other->get_name())] << "\n" << "Ãðóïï - " << other->get_count_groups() << " | ×àñîâ - " << other->get_count_hours() << " | Îïëà÷èâàåìûõ ÷àñîâ - " << other->calcul() << endl << endl;
	return out;
}