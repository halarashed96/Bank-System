#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

int main() {
    Client c1(2000, 1, "Alice", "pass12345");

    c1.displayInfo();

    c1.deposit(500);
    c1.checkBalance();

    c1.withdraw(300);
    c1.checkBalance();

    Employee e1(4000, 101, "Bob", "bobpass123");
    e1.displayInfo();

    Admin a1;
    a1 = Admin(8000, 201, "Charlie", "adminpass");
    a1.displayInfo();

}
