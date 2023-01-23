#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year);
    virtual ~Date();
    int getMonth() const;
    int getYear() const;

    bool operator<(const Date &rhs) const;

    bool operator>(const Date &rhs) const;

    bool operator<=(const Date &rhs) const;

    bool operator>=(const Date &rhs) const;

    bool operator==(const Date &rhs) const;

    bool operator!=(const Date &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Date &date);
};


#endif //DATE_H
