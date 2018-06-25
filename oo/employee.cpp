/*
 * employee.cpp
 *
 *  Created on: 2 May 2018
 *      Author: elvis
 */

#include <iostream>


const int kMaxNameSize = 20;

class Employee {

private:

	char name[kMaxNameSize];
	long id;
	float salary;

public:
	Employee(char *name, long id, float salary);
	~Employee();
	void printEmployee();
};

Employee::Employee(char *name, long id, float salary) {
	this->name = name;
	this->id = id;
	this->salary = salary;
}

Employee::~Employee() {

}

void Employee::printEmployee() {
	std::cout << "fuck" << std::endl;
};


int main() {
	Employee e;
	Employee *e1 = new Employee;
	e1->printEmployee();
	delete e1;
}
