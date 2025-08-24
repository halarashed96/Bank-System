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
    
void addClient(Client& client) {
        FileManager fm;
        fm.addClient(client);
    }

    Client* searchClient(int id) {
        FileManager fm;
        std::vector<Client> clients = fm.getAllClients();
        for (auto& c : clients) {
            if (c.get_id() == id) {
                return new Client(c); // return pointer copy
            }
        }
        return nullptr;
    }

    void listClient() {
        FileManager fm;
        std::vector<Client> clients = fm.getAllClients();
        for (auto& c : clients) {
            c.displayInfo();
        }
    }

    void editClient(int id, std::string name, std::string password, double balance) {
        FileManager fm;
        std::vector<Client> clients = fm.getAllClients();

        fm.removeAllClients(); // clear file first

        for (auto& c : clients) {
            if (c.get_id() == id) {
                c.set_name(name);
                c.set_password(password);
                c.set_balance(balance);
            }
            fm.addClient(c); // re-save all clients
        }
    }
};
