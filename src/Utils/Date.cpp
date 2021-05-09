#include <Date.h>

using namespace std;

/**
 * Date constructor
 *
 * @param day the day of the date
 * @param month the month of the date
 * @param year the year of the date
 */
Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    this->day = day;
    this->month = month;
    this->year = year;

    //checking months that doesn't have more than 30 days
    if(day < 1 || day > 31 || ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31))
        throw InvalidDate(day, month);

    //checking bissests years, february month can't have more than 28, and 29 if isn't bissest
    if(((month == 2) && (year % 4 == 0) && day > 29) ||  ((month == 2) && (year % 4 != 0) && day > 28))
        throw InvalidDate(day, month);
}

/**
 * Void date constructor
 */
Date::Date() {}

/**
 * Gets the day of the date
 *
 * @return the date's day
 */
unsigned int Date::getDay() const {
    return day;
}

/**
 * Gets the month of the date
 *
 * @return the date's month
 */
unsigned int Date::getMonth() const {
    return month;
}

/**
 * Gets the month of the date
 *
 * @return the date's month
 */
unsigned int Date::getYear() const {
    return year;
}

/**
 * Overload of << operator for date printing
 *
 * @param os the output stream
 * @param date the date to be printed
 * @return the output stream with the date
 */
ostream &operator<<(ostream &os, const Date &date) {
    os << date.day << '/' << date.month << '/' << date.year;
    return os;
}

/**
 * Overload of >> operator
 *
 * @param is the input stream to be outputted
 * @param date the date object
 * @return the input stream
 */
std::istream &operator>>(istream &is, Date &date) {
    char delim;
    is >> date.day >> delim >> date.month >> delim >> date.year;
    return is;
}
