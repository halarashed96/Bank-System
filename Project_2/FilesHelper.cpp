#pragma once
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class FilesHelper {
public:
    static void saveLast(const std::string& fileName, int id) {
        std::ofstream file(fileName, std::ios::trunc);
        file << id;
    }

    static int getLast(const std::string& fileName) {
        std::ifstream file(fileName);
        int id;
        file >> id;
        return id;
    }

    static void saveClient(const Client& c) {
        FileManager fm;
        fm.addClient(c);
    }

    static void saveEmployee(const Employee& e) {
        FileManager fm;
        fm.addEmployee(e);
    }

    static void saveAdmin(const Admin& a) {
        FileManager fm;
        fm.addAdmin(a);
    }

    static void clearFile(const std::string& fileName) {
        std::ofstream file(fileName, std::ios::trunc);
    }
};
