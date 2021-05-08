#ifndef MARKETONWHEELS_POSITION_H
#define MARKETONWHEELS_POSITION_H

#include <iostream>
#include <string>

#define DELIMITER " "

class Position {
private:
    double id;
    long double latitude;
    long double longitude;
public:
    Position(double id, long double latitude, long double longitude);
    double getId() const;
    long double getLatitude() const;
    long double getLongitude() const;
    bool operator==(Position position);
    friend std::ostream& operator<<(std::ostream& os, const Position& position);
    friend std::istream& operator>>(std::istream& is, Position& position);
};

#endif //MARKETONWHEELS_POSITION_H
