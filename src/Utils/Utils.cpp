#include "Utils.h"

long double convertToRadians(const long double degree) {
    return ((M_PI / 180) * degree);
}

long double distanceBetweenTwoPos(Position position1, Position position2) {
    long double latitude1 = convertToRadians(position1.getLatitude());
    long double longitude1 = convertToRadians(position1.getLongitude());
    long double latitude2 = convertToRadians(position2.getLatitude());
    long double longitude2 = convertToRadians(position2.getLongitude());

    // Haversine Formula
    long double diffLong = longitude2 - longitude1;
    long double diffLat = latitude2 - latitude1;

    long double res = pow(sin(diffLat / 2), 2) + cos(latitude1) * cos(latitude1) * pow(sin(diffLong / 2), 2);

    res = 2 * asin(sqrt(res));

    return res * EARTH_RADIUS;
}
