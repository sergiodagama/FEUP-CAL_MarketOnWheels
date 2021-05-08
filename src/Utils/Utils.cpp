#include <Utils.h>

/**
 * Util function that converts angle in degrees to radians
 * @param degree the degree to be converted
 * @return the angle converted in radians
 */
long double convertToRadians(const long double degree) {
    return ((M_PI / 180) * degree);
}

/**
 * Calculates the distance between two Positions, both representing different latitudes and longitudes in a map
 * @param position1 the first position to compare with
 * @param position2 the second position to compare with
 * @return the distance between the two positions, using haversine formula
 */
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
