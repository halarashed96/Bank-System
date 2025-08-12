#pragma once
#include<iostream>
#include <string>
#include "Validation.h"
#include"Person.h"
using namespace std;
class Client: public Person
{
protected:
    //Att:
    double balance;
public:
    //Def cons:
    Client() {
        balance = 1500;
    }
    //Para cons:
    Client(double balance, int id, string name, string password) 
    :Person(id, name, password) {
        this->balance = balance;
    }
    //Des:
    ~Client() {

    }
    //Getters:
    double getBalance() const {
        return this->balance;
    }
    //Setters:
    void setBalance(double balance) {
        if (Validation::ValidBalance(balance))
            this->balance = balance;
        else 
            cout << "Invalid balance must be at least 1500" << endl;
    }
    //Methods
    // Deposit money
    void deposit(double amount) {
        if (amount > 0) { 
            balance += amount;         
            cout << "Deposit successful! New balance: " << balance << endl;
        }
        else
            cout << "Deposit amount must be positive." << endl;
    }
    // Withdraw money while keeping minimum balance
    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= 1500) { 
            balance -= amount;             
            cout << "Withdraw successful! New balance: " << balance << endl;            
        }
        else
            cout << "Withdrawal failed. Check amount or minimum balance limit." << endl;
    }
    // Transfer money to another client
    void transferTo(double amount, Client& recipient) {
        if (amount > 0 && balance - amount >= 1500) {
            balance -= amount;        
            recipient.balance += amount;             
            cout << "Transfer successful!\n";
        }
        else
            cout << "Transfer failed. Check amount or minimum balance limit." << endl;
    }

    // Show current balance
    void checkBalance() const {
        cout << "Current Balance: " << balance << endl;
    }

    // Show all client info
    void displayInfo() const {
        Person::displayInfo(); 
        cout << "Balance: " << balance << endl; 
    }
};

