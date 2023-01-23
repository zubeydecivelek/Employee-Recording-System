//
// Created by zubey on 29.11.2021.
//

#include "PermanentEmployee.h"
PermanentEmployee::PermanentEmployee(int employeeNumber, std::string name, std::string surname, std::string title,
                                     double salary, const Date &birthDate, const Date &appointmentDate,
                                     int otherInstitutions) : Employee(employeeNumber, 1,
                                                                       name, surname, title, salary,
                                                                       birthDate, appointmentDate,
                                                                       otherInstitutions) {}

bool PermanentEmployee::operator<(const PermanentEmployee &rhs) const {
    if (this->getAppointmentDate()<rhs.getAppointmentDate()) return true;
    return false;
}

bool PermanentEmployee::operator>(const PermanentEmployee &rhs) const {
    return rhs < *this;
}

bool PermanentEmployee::operator<=(const PermanentEmployee &rhs) const {
    return !(rhs < *this);
}

bool PermanentEmployee::operator>=(const PermanentEmployee &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const PermanentEmployee &employee) {
    os << static_cast<const Employee &>(employee);
    return os;
}

bool PermanentEmployee::operator==(const PermanentEmployee &rhs) const {
    return static_cast<const Employee &>(*this) == static_cast<const Employee &>(rhs);
}

bool PermanentEmployee::operator!=(const PermanentEmployee &rhs) const {
    return !(rhs == *this);
}




