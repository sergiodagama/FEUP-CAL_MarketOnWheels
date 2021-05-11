#ifndef SRC_DATE_H
#define SRC_DATE_H

#include <Exceptions.h>

class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:

    /**
    * Date constructor
    *
    * @param day the day of the date
    * @param month the month of the date
    * @param year the year of the date
    */
    Date(unsigned int day, unsigned int month, unsigned int year);

    /**
    * Void date constructor
    */
    Date();

    /**
    * Gets the day of the date
    *
    * @return the date's day
    */
    unsigned int getDay() const;

    /**
    * Gets the month of the date
    *
    * @return the date's month
    */
    unsigned int getMonth() const;

    /**
    * Gets the month of the date
    *
    * @return the date's month
    */
    unsigned int getYear() const;

    /**
    * Overload of << operator for date printing
    *
    * @param os the output stream
    * @param date the date to be printed
    * @return the output stream with the date
    */
    friend std::ostream &operator<<(std::ostream &os, const Date &date);

    /**
    * Overload of >> operator
    *
    * @param is the input stream to be outputted
    * @param date the date object
    * @return the input stream
    */
    friend std::istream &operator>>(std::istream &is, Date &date);
};

#endif //SRC_DATE_H
