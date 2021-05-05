//
// Created by sergi on 05/05/2021.
//

#ifndef MARKETONWHEELS_UTILS_H
#define MARKETONWHEELS_UTILS_H

#include <cmath>
#include "../Position/Position.h"

#define EARTH_RADIUS 6371  //radius of Earth in km

long double convertToRadians(const long double degree);

long double distanceBetweenTwoPos(Position position1, Position position2);

#endif //MARKETONWHEELS_UTILS_H
