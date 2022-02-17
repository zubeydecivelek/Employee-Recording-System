//
// Created by zubey on 30.11.2021.
//

#include "Employee.h"
Employee::Employee(int employeeNumber, int employeeType, char *name, char *surname, char *title, double salary,
                   const Date &birthDate, const Date &appointmentDate, int otherInstitutions) : employeeNumber(
        employeeNumber), employeeType(employeeType), name(name), surname(surname), title(title), salary(salary),
                                                                                                birthDate(birthDate),
                                                                                                appointmentDate(
                                                                                                        appointmentDate),
                                                                                                otherInstitutions(
                                                                                                        otherInstitutions) {}

int Employee::getEmployeeNumber() const {
    return employeeNumber;
}

void Employee::setEmployeeNumber(int employeeNumber) {
    Employee::employeeNumber = employeeNumber;
}

int Employee::getEmployeeType() const {
    return employeeType;
}

void Employee::setEmployeeType(int employeeType) {
    Employee::employeeType = employeeType;
}

char *Employee::getName() const {
    return name;
}

void Employee::setName(char *name) {
    Employee::name = name;
}

char *Employee::getSurname() const {
    return surname;
}

void Employee::setSurname(char *surname) {
    Employee::surname = surname;
}

char *Employee::getTitle() const {
    return title;
}

void Employee::setTitle(char *title) {
    Employee::title = title;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setSalary(double salary) {
    Employee::salary = salary;
}

const Date &Employee::getBirthDate() const {
    return birthDate;
}

void Employee::setBirthDate(const Date &birthDate) {
    Employee::birthDate = birthDate;
}

const Date &Employee::getAppointmentDate() const {
    return appointmentDate;
}

void Employee::setAppointmentDate(const Date &appointmentDate) {
    Employee::appointmentDate = appointmentDate;
}

int Employee::getOtherInstitutions() const {
    return otherInstitutions;
}

void Employee::setOtherInstitutions(int otherInstitutions) {
    Employee::otherInstitutions = otherInstitutions;


}

std::ostream &operator<<(std::ostream &os, const Employee &employee) {
    os << "employeeNumber: " << employee.employeeNumber << " employeeType: " << employee.employeeType << " name: "
       << employee.name << " surname: " << employee.surname << " title: " << employee.title << " salary: "
       << employee.salary << " birthDate: " << employee.birthDate << " appointmentDate: " << employee.appointmentDate
       << " otherInstitutions: " << employee.otherInstitutions;
    return os;
}

bool Employee::operator==(const Employee &rhs) const {
    return employeeNumber == rhs.employeeNumber;
}

bool Employee::operator!=(const Employee &rhs) const {
    return !(rhs == *this);
}