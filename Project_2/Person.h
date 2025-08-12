#pragma once
#include<iostream>
#include <string>
#include "Validation.h"
using namespace std;
class Person
{
protected:
	//Att:
	int id;
	string name;
	string password;
public:
	//Def Cons:
	Person() {
		this->id = 0;
		this->name = "";
		this->password = "";
	}
	//Para Cons:
	Person(int id, string name, string password) {
		this->id = id;
		this->name = name;
		this->password = password;
	}
	//Des:
	~Person() {

	}
	//Getters:
	int get_id() const {
		return this->id;
	}
	string get_name() const {
		return this->name;
	}
	string get_password() const {
		return this->password;
	}
	//Setters:
	void set_id(int id) {
		this->id = id;
	}
	void set_name(string name) {
		if (Validation::ValidName(name))
			this->name = name;
		else
			cout << "Invalid name. Must be 5-20 letters only." << endl;
	}
	void set_password(string password) {
		if (Validation::ValidPassword(password))
			this->password = password;
		else
			cout << "Invalid password. Must be 8-20 characters." << endl;
	}
	//Methods
	void displayInfo() const {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
	}
};

