#include "Date.h"

using namespace std;

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    this->day = day;
    this->month = month;
    this->year = year;

    //checking months that doesn't have more than 30 days
    if (day < 1 || day > 31 || ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31))
        throw InvalidDate(day, month);

    //checking bissests years, february month can't have more than 28, and 29 if isn't bissest
    if (((month == 2) && (year % 4 == 0) && day > 29) || ((month == 2) && (year % 4 != 0) && day > 28))
        throw InvalidDate(day, month);
}

Date::Date() {}

unsigned int Date::getDay() const {
    return day;
}

unsigned int Date::getMonth() const {
    return month;
}

unsigned int Date::getYear() const {
    return year;
}

ostream &operator<<(ostream &os, const Date &date) {
    os << date.day << '/' << date.month << '/' << date.year;
    return os;
}

std::istream &operator>>(istream &is, Date &date) {
    char delim;
    is >> date.day >> delim >> date.month >> delim >> date.year;
    return is;
}
