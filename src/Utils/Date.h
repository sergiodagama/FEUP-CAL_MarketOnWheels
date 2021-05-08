//
// Created by sergi on 26/04/2021.
//

#ifndef SRC_DATE_H
#define SRC_DATE_H

#include "../Exceptions/Exceptions.h"
#include <iostream>

class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date(unsigned int day,unsigned int month,unsigned int year);
    Date(std::string dateString);
    Date();

    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
    friend std::ostream& operator<<(std::ostream& os, const Date& dt);
    bool validDate;
};


#endif //SRC_DATE_H
