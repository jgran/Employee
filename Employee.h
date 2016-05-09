#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

//This class will hold information about individual employees
class Employee{

    private:

        //employee attributes
        std::string first_name_;        
        std::string last_name_;        
        std::string title_;        
        std::string phone_number_;        

    public:
        
        //constructor takes first name, last name, title, and phone number
        Employee(std::string first, std::string last, std::string title, std::string phone);
        ~Employee(){}

        //getters
        std::string GetFirstName() const;
        std::string GetLastName() const;
        std::string GetTitle() const;
        std::string GetPhoneNumber() const;

        //override the "<" operator to enable alphabetical sorting by last name
        bool operator < (Employee emp) const;

};

//This class is a container of Employee objects
class EmployeeCollection{

    private:    

        //container to hold Employee objects
        std::vector<Employee> emp_vec_;
    
    public:    

        //constructor can take a vector of Employee objects
        EmployeeCollection(std::vector<Employee> input_vec);

        //constructor can also take no arguments, and employees can be added through the Add method
        EmployeeCollection(){}
        ~EmployeeCollection(){}
        
        //Add an Employee object to the container
        void Add(Employee emp);

        //Sort container by last name
        void Sort();

        //print employee info to screen
        void Print();

};
