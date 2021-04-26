//
// Created by eunic on 26/04/2021.
//

#include "Exceptions.h"

using namespace std;

NegativeValue::NegativeValue(string &parameter) : parameter(parameter) {}

string NegativeValue::getParameter() const {
    return parameter;
}

std::ostream &operator<<(ostream &o, const NegativeValue nv) {
    o << "This value can't be negative: " << nv.getParameter() << '\n';
    return o;
}
