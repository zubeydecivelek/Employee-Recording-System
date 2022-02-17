//
// Created by zubey on 30.11.2021.
//

#ifndef ASSIGNMENT2_6_TEMPORARYEMPLOYEE_H
#define ASSIGNMENT2_6_TEMPORARYEMPLOYEE_H


#include <ostream>
#include "Employee.h"

class TemporaryEmployee : public Employee{
private:
    int employeeType = 0;

public:
    TemporaryEmployee(int employeeNumber, char *name, char *surname, char *title, double salary,
                      const Date &birthDate, const Date &appointmentDate, int otherInstitutions);

    bool operator<(const TemporaryEmployee &rhs) const;

    bool operator>(const TemporaryEmployee &rhs) const;

    bool operator==(const TemporaryEmployee &rhs) const;

    bool operator!=(const TemporaryEmployee &rhs) const;

    bool operator<=(const TemporaryEmployee &rhs) const;

    bool operator>=(const TemporaryEmployee &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const TemporaryEmployee &employee);
};


#endif //ASSIGNMENT2_6_TEMPORARYEMPLOYEE_H
