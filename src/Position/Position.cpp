#include "Position.h"

/**
 * Position constructor
 *
 * @param id the id of the position
 * @param latitude the latitude of the position
 * @param longitude the longitude of the position
 */
Position::Position(double id, long double latitude, long double longitude) {
    this->id = id;
    this->latitude = latitude;
    this->longitude = longitude;
}

/**
 * Gets the position id
 *
 * @return the position id
 */
double Position::getId() const {
    return id;
}

/**
 * Gets the position latitude
 *
 * @return the position latitude
 */
long double Position::getLatitude() const {
    return latitude;
}

/**
 * Gets the position longitude
 *
 * @return the position longitude
 */
long double Position::getLongitude() const {
    return longitude;
}

/**
 * Overload of the == operator
 * @param position the position to be compared with
 * @return true if position ids are equal, false otherwise
 */
bool Position::operator==(Position position) {
    return id == position.getId();
}
