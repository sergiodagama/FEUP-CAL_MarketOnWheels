#ifndef MARKETONWHEELS_POSITION_H
#define MARKETONWHEELS_POSITION_H

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
};

#endif //MARKETONWHEELS_POSITION_H
