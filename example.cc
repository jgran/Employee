#include "Employee.h"
#include <fstream>

int main(){

    //create an instance of EmployeeCollection to store info about all employees
    EmployeeCollection myEmployees;

    //read employee info from txt file and add to EmployeeCollection object
    std::ifstream infile("employees.txt");
    std::string first, last, title, phone;
    while (infile >> first >> last >> title >> phone){
        myEmployees.Add(Employee(first, last, title, phone));
    }

    //print employee info, sorted alphabetically by last name
    myEmployees.Print();

    return 0;
}
