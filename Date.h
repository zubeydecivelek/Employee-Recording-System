//
// Created by zubey on 30.11.2021.
//

#ifndef ASSIGNMENT2_6_DATE_H
#define ASSIGNMENT2_6_DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year);

    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    bool operator<(const Date &rhs) const;

    bool operator>(const Date &rhs) const;

    bool operator<=(const Date &rhs) const;

    bool operator>=(const Date &rhs) const;

    bool operator==(const Date &rhs) const;

    bool operator!=(const Date &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Date &date);
};


#endif //ASSIGNMENT2_6_DATE_H
