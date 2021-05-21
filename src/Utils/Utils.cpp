#include "Utils.h"

long double convertToRadians(const long double degree) {
    return (degree * M_PI / 180);
}

long double distanceBetweenTwoPos(Position position1, Position position2) {
    long double latitude1 = position1.getLatitude();
    long double longitude1 = position1.getLongitude();
    long double latitude2 = position2.getLatitude();
    long double longitude2 = position2.getLongitude();

    long double diffLong = convertToRadians(longitude2 - longitude1);
    long double diffLat = convertToRadians(latitude2 - latitude1);

    latitude1 = convertToRadians(latitude1);
    latitude2 = convertToRadians(latitude2);

    // Haversine Formula
    long double res = pow(sin(diffLat / 2), 2) + pow(sin(diffLong / 2), 2) * cos(latitude1) * cos(latitude2);

    res = 2 * asin(sqrt(res));

    return res * EARTH_RADIUS;
}

template<typename T>
void printElem(T t, const int& width){
    std::cout << std::left << std::setw(width) << std::setfill(' ') << t;
}
