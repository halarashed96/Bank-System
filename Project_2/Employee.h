#pragma once
#include<iostream>
#include <string>
#include "Validation.h"
#include"Person.h"
using namespace std;
class Employee:public Person
{
protected:
    //Att:
    double salary;
public:
    //Def cons:
    Employee() {
        salary = 5000;
    }
    //Para cons:
    Employee(double salary, int id, string name, string password)
        :Person(id, name, password) {
        this->salary = salary;
    }
    //Des:
    ~Employee() {

    }
    //Getters:
    double getSalary() const {
        return this->salary;
    }
    //Setters:
    void setSalary(double salary) {
        if (Validation::ValidSalary(salary))
            this->salary = salary;
        else
            cout << "Invalid salary must be at least 5000" << endl;
    }
    // Show all client info
    void displayInfo() const {
        Person::displayInfo();
        cout << "Salary: " << salary << endl;
    }
};

