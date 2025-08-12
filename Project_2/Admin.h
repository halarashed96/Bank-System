#pragma once
#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
#include "Person.h"
#include "Employee.h"
using namespace std;
class Admin : public Employee
{
public:
    // Def cons:
    Admin()  {}

    // Para cons:
    Admin(double salary, int id, string name, string password)
        : Employee(salary, id, name, password) {
    }
    //Des:
    ~Admin() {

    }
    // Methods
    void displayInfo() const {
        Employee::displayInfo();
    }
};

