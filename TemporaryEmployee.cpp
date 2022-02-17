//
// Created by zubey on 30.11.2021.
//

#include "TemporaryEmployee.h"

TemporaryEmployee::TemporaryEmployee(int employeeNumber, char *name, char *surname, char *title,
                                     double salary, const Date &birthDate, const Date &appointmentDate,
                                     int otherInstitutions) : Employee(employeeNumber, 0, name, surname,
                                                                       title, salary, birthDate, appointmentDate,
                                                                       otherInstitutions) {}

bool TemporaryEmployee::operator<(const TemporaryEmployee &rhs) const {
    if (this->getEmployeeNumber() < rhs.getEmployeeNumber()) return true;
    return false;

}

bool TemporaryEmployee::operator>(const TemporaryEmployee &rhs) const {
    return rhs < *this;
}

bool TemporaryEmployee::operator<=(const TemporaryEmployee &rhs) const {
    return !(rhs < *this);
}

bool TemporaryEmployee::operator>=(const TemporaryEmployee &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const TemporaryEmployee &employee) {
    os << static_cast<const Employee &>(employee);
    return os;
}

bool TemporaryEmployee::operator==(const TemporaryEmployee &rhs) const {
    return static_cast<const Employee &>(*this) == static_cast<const Employee &>(rhs);
}

bool TemporaryEmployee::operator!=(const TemporaryEmployee &rhs) const {
    return !(rhs == *this);
}
