#ifndef PERMANENTEMPLOYEE_H
#define PERMANENTEMPLOYEE_H

#include <ostream>
#include "Employee.h"

class PermanentEmployee : public Employee{
private:
    int employeeType = 1;
public:
    PermanentEmployee(int employeeNumber, std::string name, std::string surname, std::string title, double salary,
                      const Date &birthDate, const Date &appointmentDate, int otherInstitutions);

    bool operator<(const PermanentEmployee &rhs) const;
    bool operator>(const PermanentEmployee &rhs) const;
    bool operator<=(const PermanentEmployee &rhs) const;
    bool operator>=(const PermanentEmployee &rhs) const;
    bool operator==(const PermanentEmployee &rhs) const;
    bool operator!=(const PermanentEmployee &rhs) const;
    friend std::ostream &operator<<(std::ostream &os, const PermanentEmployee &employee);
};

#endif //PERMANENTEMPLOYEE_H
