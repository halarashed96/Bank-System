#pragma once
#include<iostream>
#include <string>
using namespace std;

class Validation
{
public:
    //name must be between 5-20 letters
    static bool IsAlphaChar(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    static bool ValidName(const string& name) {
        if (!(name.size() >= 5 && name.size() <= 20)) 
            return false;
        for (char c : name) {
            if (!IsAlphaChar(c))
                return false;
        }
        return true;
    }
    //password must be between 8-20 characters
    static bool ValidPassword(const string& password) {
        return(password.size() >= 8 && password.size() <= 20);
    }
    //balance must be at least 1500
    static bool ValidBalance(double balance) {
        return balance >= 1500;
    }
    //salary must be at least 5000
    static bool ValidSalary(double salary) {
        return salary >= 5000;
    }
};

