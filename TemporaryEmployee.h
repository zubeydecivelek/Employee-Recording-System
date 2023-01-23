#ifndef TEMPORARYEMPLOYEE_H
#define TEMPORARYEMPLOYEE_H

#include <ostream>
#include "Employee.h"

class TemporaryEmployee : public Employee{
private:
    int employeeType = 0;
public:
    TemporaryEmployee(int employeeNumber, std::string name, std::string surname, std::string title, double salary,
                      const Date &birthDate, const Date &appointmentDate, int otherInstitutions);

    bool operator<(const TemporaryEmployee &rhs) const;
    bool operator>(const TemporaryEmployee &rhs) const;
    bool operator==(const TemporaryEmployee &rhs) const;
    bool operator!=(const TemporaryEmployee &rhs) const;
    bool operator<=(const TemporaryEmployee &rhs) const;
    bool operator>=(const TemporaryEmployee &rhs) const;
    friend std::ostream &operator<<(std::ostream &os, const TemporaryEmployee &employee);

};


#endif //TEMPORARYEMPLOYEE_H
