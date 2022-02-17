,//
// Created by zubey on 30.11.2021.
//

#ifndef ASSIGNMENT2_6_EMPLOYEE_H
#define ASSIGNMENT2_6_EMPLOYEE_H


#include <ostream>
#include "Date.h"

class Employee {
private:
    int employeeNumber;
    int employeeType;
    char * name;
    char * surname;
    char * title;
    double salary;
    Date birthDate;
    Date appointmentDate;
    int otherInstitutions;

public:
    Employee(int employeeNumber, int employeeType, char *name, char *surname, char *title, double salary,
             const Date &birthDate, const Date &appointmentDate, int otherInstitutions);

    bool operator==(const Employee &rhs) const;

    bool operator!=(const Employee &rhs) const;

    int getEmployeeNumber() const;

    void setEmployeeNumber(int employeeNumber);

    int getEmployeeType() const;

    void setEmployeeType(int employeeType);

    char *getName() const;

    void setName(char *name);

    char *getSurname() const;

    void setSurname(char *surname);

    char *getTitle() const;

    void setTitle(char *title);

    double getSalary() const;

    void setSalary(double salary);

    const Date &getBirthDate() const;

    void setBirthDate(const Date &birthDate);

    const Date &getAppointmentDate() const;

    void setAppointmentDate(const Date &appointmentDate);

    int getOtherInstitutions() const;

    void setOtherInstitutions(int otherInstitutions);

    friend std::ostream &operator<<(std::ostream &os, const Employee &employee);
};

#endif //ASSIGNMENT2_6_EMPLOYEE_H
