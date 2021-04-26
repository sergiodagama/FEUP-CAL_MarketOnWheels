//
// Created by sergi on 26/04/2021.
//

#ifndef SRC_DATE_H
#define SRC_DATE_H

class InvalidDay extends Exception{
}

class InvalidMonth extends Exception{
}

class InvalidYear extends Exception{
}

};
class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date(unsigned int day,unsigned int month,unsigned int year);
    void setDay(unsigned int day);
    unsigned int getDay() const;
    void setMonth(unsigned int month);
    unsigned int getMonth() const;
    void setYear(unsigned int year);
    unsigned int getYear() const;
    friend ostream& operator<<(ostream& os, const Date& dt);
};


#endif //SRC_DATE_H
