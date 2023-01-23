#include "Employee.h"
Employee::Employee(int employeeNumber, int employeeType, std::string name, std::string surname, std::string title, double salary,
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

std::string Employee::getName() const {
    return name;
}

std::string Employee::getTitle() const {
    return title;
}

void Employee::setTitle(std::string title) {
    Employee::title = title;
}

void Employee::setSalary(double salary) {
    Employee::salary = salary;
}

const Date &Employee::getBirthDate() const {
    return birthDate;
}

const Date &Employee::getAppointmentDate() const {
    return appointmentDate;
}

std::ostream &operator<<(std::ostream &os, const Employee &employee) {
    os << "employeeNumber: " << employee.employeeNumber << " employeeType: " << employee.employeeType << " name: "
       << employee.name << " surname: " << employee.surname << " title: " << employee.title << " salary: "
       << employee.salary << " birthDate: " << employee.birthDate << " appointmentDate: "
       << employee.appointmentDate
       << " otherInstitutions: " << employee.otherInstitutions;
    return os;
}

bool Employee::operator==(const Employee &rhs) const {
    return employeeNumber == rhs.employeeNumber;
}

bool Employee::operator!=(const Employee &rhs) const {
    return !(rhs == *this);
}

Employee::~Employee()
{
}

