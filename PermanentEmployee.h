//
// Created by zubey on 30.11.2021.
//

#ifndef ASSIGNMENT2_6_PERMANENTEMPLOYEE_H
#define ASSIGNMENT2_6_PERMANENTEMPLOYEE_H

#include <ostream>
#include "Employee.h"

class PermanentEmployee : public Employee{
private:
    int employeeType = 1;

public:
    PermanentEmployee(int employeeNumber, char *name, char *surname, char *title, double salary,
                      const Date &birthDate, const Date &appointmentDate, int otherInstitutions);

    bool operator<(const PermanentEmployee &rhs) const;

    bool operator>(const PermanentEmployee &rhs) const;

    bool operator<=(const PermanentEmployee &rhs) const;

    bool operator>=(const PermanentEmployee &rhs) const;

    bool operator==(const PermanentEmployee &rhs) const;

    bool operator!=(const PermanentEmployee &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const PermanentEmployee &employee);
};

#endif //ASSIGNMENT2_6_PERMANENTEMPLOYEE_H
