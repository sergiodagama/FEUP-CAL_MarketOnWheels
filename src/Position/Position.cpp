#include "Position.h"

using namespace std;

Position::Position(int id, long double latitude, long double longitude) {
    this->id = id;
    this->latitude = latitude;
    this->longitude = longitude;
}

int Position::getId() const {
    return id;
}

long double Position::getLatitude() const {
    return latitude;
}

long double Position::getLongitude() const {
    return longitude;
}

bool Position::operator==(Position position) {
    return id == position.getId();
}

ostream &operator<<(ostream &os, const Position &position) {
    os << to_string(position.id);
    return os;
}

std::istream &operator>>(istream &is, Position &position) {
    is >> position.id >> position.latitude >> position.longitude;
    return is;
}
