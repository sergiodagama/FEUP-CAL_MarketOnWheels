#ifndef SRC_EXCEPTIONS_H
#define SRC_EXCEPTIONS_H

#include <exception>
#include <string>
#include <iostream>

class NegativeValue : std::exception {
public:
    NegativeValue(const std::string& parameter);
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

class ProductNotFound : std::exception{};

class ProductAlreadyExists : std::exception{};

class InvalidQuantity : std::exception{};

class NameAlreadyExists : std::exception{};

class NameDosNotExist : std::exception{};

class NotAvailableSpace : std::exception{};

#endif //SRC_EXCEPTIONS_H
