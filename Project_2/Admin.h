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
    
 void addEmployee(Employee& employee) {
        FileManager fm;
        fm.addEmployee(employee);
    }

    Employee* searchEmployee(int id) {
        FileManager fm;
        std::vector<Employee> employees = fm.getAllEmployees();
        for (auto& e : employees) {
            if (e.get_id() == id) {
                return new Employee(e);
            }
        }
        return nullptr;
    }

    void editEmployee(int id, std::string name, std::string password, double salary) {
        FileManager fm;
        std::vector<Employee> employees = fm.getAllEmployees();

        fm.removeAllEmployees(); // clear

        for (auto& e : employees) {
            if (e.get_id() == id) {
                e.set_name(name);
                e.set_password(password);
                e.set_salary(salary);
            }
            fm.addEmployee(e);
        }
    }

    void listEmployee() {
        FileManager fm;
        std::vector<Employee> employees = fm.getAllEmployees();
        for (auto& e : employees) {
            e.displayInfo();
        }
    }
};

