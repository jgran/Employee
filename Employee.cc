#include "Employee.h"

//////////////////////////////////////////////
// Implementation of Employee class methods //
//////////////////////////////////////////////
Employee::Employee(std::string first, std::string last, std::string title, std::string phone){
    first_name_ = first;
    last_name_ = last;
    title_ = title;
    phone_number_ = phone;
}

std::string Employee::GetFirstName() const{
    return first_name_;
}

std::string Employee::GetLastName() const{
    return last_name_;
}

std::string Employee::GetTitle() const{
    return title_;
}

//get phone number in format (xxx)xxx-xxxx
std::string Employee::GetPhoneNumber() const{
    std::string formatted_phone; 
    formatted_phone.append("(");
    formatted_phone.append(phone_number_.substr(0,3));
    formatted_phone.append(")");
    formatted_phone.append(phone_number_.substr(3,3));
    formatted_phone.append("-");
    formatted_phone.append(phone_number_.substr(6,4));
    return formatted_phone;
}

bool Employee::operator < (Employee emp) const{
    return last_name_ < emp.GetLastName();
}


////////////////////////////////////////////////////////
// Implementation of EmployeeCollection class methods //
////////////////////////////////////////////////////////
EmployeeCollection::EmployeeCollection(std::vector<Employee> input_vec){
    emp_vec_ = input_vec;
}

void EmployeeCollection::Add(Employee emp){
    emp_vec_.push_back(emp); 
}

void EmployeeCollection::Sort(){
    std::sort(emp_vec_.begin(), emp_vec_.end());
}

void EmployeeCollection::Print(){
    
    Sort();

    //get maximum size of fields for print formatting
    size_t min_length = 5;
    size_t max_length_first = min_length;
    size_t max_length_last = min_length;
    size_t max_length_title = min_length;
    size_t max_length_phone = min_length;
    for(std::vector<Employee>::const_iterator iter = emp_vec_.begin(); iter != emp_vec_.end(); iter++){
        max_length_first = std::max(iter->GetFirstName().length(), max_length_first); 
        max_length_last = std::max(iter->GetLastName().length(), max_length_last); 
        max_length_title = std::max(iter->GetTitle().length(), max_length_title); 
        max_length_phone = std::max(iter->GetPhoneNumber().length(), max_length_phone); 
    }

    //print employee attributes with columns lined up
    int offset = 1;
    std::cout << std::setw(max_length_last+offset) << "Last" << "," 
              << std::setw(max_length_first+offset) << "First"
              << std::setw(max_length_title+offset) << "Title"
              << std::setw(max_length_phone+offset) << "Phone" << std::endl;
    for(std::vector<Employee>::const_iterator iter = emp_vec_.begin(); iter != emp_vec_.end(); iter++){
        std::cout << std::setw(max_length_last+offset) << iter->GetLastName() << "," 
                  << std::setw(max_length_first+offset) << iter->GetFirstName()
                  << std::setw(max_length_title+offset) << iter->GetTitle()
                  << std::setw(max_length_phone+offset) << iter->GetPhoneNumber() << std::endl;
    }
}
