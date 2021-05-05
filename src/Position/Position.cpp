//
// Created by sergi on 05/05/2021.
//

#include "Position.h"

Position::Position(double id, long double latitude, long double longitude) {
    this->id = id;
    this->latitude = latitude;
    this->longitude = longitude;
}

double Position::getId() const {
    return id;
}

long double Position::getLatitude() const {
    return latitude;
}

long double Position::getLongitude() const {
    return longitude;
}

bool Position::operator==(Position p) {
    return id == p.getId();
}
