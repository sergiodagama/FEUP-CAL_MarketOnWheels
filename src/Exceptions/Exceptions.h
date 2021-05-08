#ifndef SRC_EXCEPTIONS_H
#define SRC_EXCEPTIONS_H

#include <exception>
#include <string>
#include <iostream>

class NegativeValue : std::exception {
public:
    /**
     * Exception constructor
     *
     * @param parameter the negative value
     */
    NegativeValue(const std::string& parameter);

    /**
     * Gets the negative value passed
     *
     * @return the parameter (negative value)
     */
    std::string getParameter() const;
private:
    std::string parameter;
};

/**
 * Overload to the << operator to display the error
 *
 * @param o output stream
 * @param nv the negative value passed
 * @return the output stream with the designated error
 */
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
