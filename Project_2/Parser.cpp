#pragma once
#include <sstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class Parser {
public:
    static std::vector<std::string> split(const std::string& line) {
        std::vector<std::string> tokens;
        std::stringstream ss(line);
        std::string item;
        while (std::getline(ss, item, ',')) {
            tokens.push_back(item);
        }
        return tokens;
    }

    static Client parseToClient(const std::string& line) {
        auto tokens = split(line);
        return Client(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }

    static Employee parseToEmployee(const std::string& line) {
        auto tokens = split(line);
        return Employee(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }

    static Admin parseToAdmin(const std::string& line) {
        auto tokens = split(line);
        return Admin(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }
};
