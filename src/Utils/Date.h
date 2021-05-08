#ifndef SRC_DATE_H
#define SRC_DATE_H

#include <Exceptions.h>

class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date(unsigned int day,unsigned int month,unsigned int year);
    Date();
    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);
};

#endif //SRC_DATE_H
