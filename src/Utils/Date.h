//
// Created by sergi on 26/04/2021.
//

#ifndef SRC_DATE_H
#define SRC_DATE_H

#include <exception>
#include <iostream>

class InvalidDate : std::exception {
private:
    unsigned int day;
    unsigned int month;
public:
    InvalidDate(unsigned int day, unsigned int month){
        this->day = day;
        this->month = month;

    std::cout << "Date Error: Month: " << month << " Day: " << day << std::endl;
    };
};

class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date(unsigned int day,unsigned int month,unsigned int year);
    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
    friend std::ostream& operator<<(std::ostream& os, const Date& dt);
    bool validDate
};


#endif //SRC_DATE_H
