#include <Exceptions.h>

using namespace std;

NegativeValue::NegativeValue(const string &parameter) : parameter(parameter) {}

string NegativeValue::getParameter() const {
    return parameter;
}

std::ostream &operator<<(ostream &o, const NegativeValue nv) {
    o << "This value can't be negative: " << nv.getParameter() << endl;
    return o;
}
