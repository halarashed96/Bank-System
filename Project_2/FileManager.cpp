#pragma once
#include "DataSourceInterface.h"
#include <fstream>

class FileManager : public DataSourceInterface {
public:
    void addClient(const Client& client) override {
        std::ofstream file("Clients.txt", std::ios::app);
        file << client.get_id() << "," << client.get_name()
             << "," << client.get_password()
             << "," << client.get_balance() << "\n";
    }

    void addEmployee(const Employee& employee) override {
        std::ofstream file("Employees.txt", std::ios::app);
        file << employee.get_id() << "," << employee.get_name()
             << "," << employee.get_password()
             << "," << employee.get_salary() << "\n";
    }

    void addAdmin(const Admin& admin) override {
        std::ofstream file("Admins.txt", std::ios::app);
        file << admin.get_id() << "," << admin.get_name()
             << "," << admin.get_password()
             << "," << admin.get_salary() << "\n";
    }

    std::vector<Client> getAllClients() override {
        std::vector<Client> clients;
        std::ifstream file("Clients.txt");
        std::string line;
        while (std::getline(file, line)) {
            clients.push_back(Parser::parseToClient(line));
        }
        return clients;
    }

    std::vector<Employee> getAllEmployees() override {
        std::vector<Employee> employees;
        std::ifstream file("Employees.txt");
        std::string line;
        while (std::getline(file, line)) {
            employees.push_back(Parser::parseToEmployee(line));
        }
        return employees;
    }

    std::vector<Admin> getAllAdmins() override {
        std::vector<Admin> admins;
        std::ifstream file("Admins.txt");
        std::string line;
        while (std::getline(file, line)) {
            admins.push_back(Parser::parseToAdmin(line));
        }
        return admins;
    }

    void removeAllClients() override {
        std::ofstream file("Clients.txt", std::ios::trunc);
    }

    void removeAllEmployees() override {
        std::ofstream file("Employees.txt", std::ios::trunc);
    }

    void removeAllAdmins() override {
        std::ofstream file("Admins.txt", std::ios::trunc);
    }
};
