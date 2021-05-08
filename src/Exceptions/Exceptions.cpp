#include <Exceptions.h>

using namespace std;

/**
 * Exception constructor
 *
 * @param parameter the negative value
 */
NegativeValue::NegativeValue(const string& parameter) : parameter(parameter) {}

/**
 * Gets the negative value passed
 *
 * @return the parameter (negative value)
 */
string NegativeValue::getParameter() const {
    return parameter;
}

/**
 * Overload to the << operator to display the error
 *
 * @param o output stream
 * @param nv the negative value passed
 * @return the output stream with the designated error
 */
std::ostream &operator<<(ostream &o, const NegativeValue nv) {
    o << "This value can't be negative: " << nv.getParameter() << endl;
    return o;
}
