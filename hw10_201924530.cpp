#include <iostream>
#include <vector>
using namespace std;

enum EmployeeLevel { 사원, 대리, 과장, 차장, 부장 };
class Employee {
	string name;
	const EmployeeLevel level;
public:
	Employee(const string& _name, EmployeeLevel _level) : level(_level) {
		name = _name;
	}
	string getName() const {
		return name;
	}
	EmployeeLevel getLevel() const {
		return level;
	}
	friend ostream& operator << (ostream& os, const Employee& e);
};
ostream& operator << (ostream& os, const Employee& e) {
	os << static_cast<int>(e.level) << "\t" << e.name << endl;
	return os;
}
class Manager : public Employee {
	vector<Employee*> group;
public:
	Manager(const string& _name, EmployeeLevel _level = 차장) : Employee(_name, _level) {}
	void addEmployee(Employee* const emp) {
		group.push_back(emp);
	}
	friend ostream& operator << (ostream& os, const Manager& m);
};
ostream& operator << (ostream& os, const Manager& m) {
	os << static_cast<int>(m.getLevel()) << "\t" << m.getName() << endl;
	os << "List of employees managed by me" << endl;
	for (int i = 0; i < m.group.size(); i++) {
		cout << m.group[i]->getLevel() << "\t" << m.group[i]->getName()  << endl;
	}
	return os;
}
int main() {
	Employee e1("홍", 사원), e2("김", 대리), e3("차", 사원);
	cout << e1 << e2 << e3;

	Manager m1("Tom", 차장);
	m1.addEmployee(&e1);
	m1.addEmployee(&e2);
	m1.addEmployee(&e3);
	cout << endl << "Information for Manager" << endl;
	cout << m1;
}

