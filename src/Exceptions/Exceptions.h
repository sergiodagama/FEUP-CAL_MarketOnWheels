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


#endif //SRC_EXCEPTIONS_H
