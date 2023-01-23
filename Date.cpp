#include "Date.h"
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os <<  date.day << "-" << date.month << "-" << date.year;
    return os;
}

bool Date::operator==(const Date &rhs) const {
    return day == rhs.day &&
           month == rhs.month &&
           year == rhs.year;
}

bool Date::operator!=(const Date &rhs) const {
    return !(rhs == *this);
}

bool Date::operator<(const Date &rhs) const {
    if (year>rhs.year) return true;
    else if (year==rhs.year && month>rhs.month)return true;
    else if (year==rhs.year && month==rhs.month && day>rhs.day) return true;
    return false;
}

bool Date::operator>(const Date &rhs) const {
    return rhs < *this;
}

bool Date::operator<=(const Date &rhs) const {
    return !(rhs < *this);
}

bool Date::operator>=(const Date &rhs) const {
    return !(*this < rhs);
}

Date::~Date() {

}

