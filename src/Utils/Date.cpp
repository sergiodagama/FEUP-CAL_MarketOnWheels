//
// Created by sergi on 26/04/2021.
//

#include "Date.h"

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::setDay(unsigned int day) {
    this->day = day;
}

unsigned int Date::getDay() const {
    return day;
}

void Date::setMonth(unsigned int month) {
    this->month = month;
}

unsigned int Date::getMonth() const {
    return month;
}

void Date::setYear(unsigned int year) {
    this->year = year;
}

unsigned int Date::getYear() const {
    return year;
}

ostream &operator<<(ostream &os, const Date &date) {
    os << date.day << '/' << date.month << '/' << date.year;
    return os;
}
