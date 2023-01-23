#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <ostream>
#include "Date.h"

class Employee {
private:
    int employeeNumber;
    int employeeType;
    std::string name;
    std::string surname;
    std::string title;
    double salary;
    Date birthDate;
    Date appointmentDate;
    int otherInstitutions;
public:
    Employee(int employeeNumber, int employeeType, std::string name, std::string surname, std::string title, double salary,
             const Date &birthDate, const Date &appointmentDate, int otherInstitutions);
    bool operator==(const Employee &rhs) const;
    bool operator!=(const Employee &rhs) const;
    int getEmployeeNumber() const;
    std::string getName() const;
    virtual ~Employee();
    std::string getTitle() const;
    void setTitle(std::string title);
    void setSalary(double salary);
    const Date &getBirthDate() const;
    const Date &getAppointmentDate() const;
    friend std::ostream &operator<<(std::ostream &os, const Employee &employee);
};


#endif //EMPLOYEE_H
