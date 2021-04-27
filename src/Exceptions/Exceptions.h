//
// Created by eunic on 26/04/2021.
//

#ifndef SRC_EXCEPTIONS_H
#define SRC_EXCEPTIONS_H

#include <exception>
#include <string>
#include <iostream>


class NegativeValue :std::exception {
public:
    NegativeValue(std::string parameter);
    std::string getParameter() const;

private:
    std::string parameter;


};
std::ostream & operator<<(std::ostream &o, NegativeValue nv);

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

class InvalidStyle : std::exception{};

#endif //SRC_EXCEPTIONS_H
