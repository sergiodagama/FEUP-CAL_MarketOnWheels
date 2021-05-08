#ifndef MARKETONWHEELS_POSITION_H
#define MARKETONWHEELS_POSITION_H

#include <iostream>
#include <string>

#define DELIMITER " "

class Position {
private:
    double id;
    long double latitude;
    long double longitude;
public:
    /**
     * Position constructor
     *
     * @param id the id of the position
     * @param latitude the latitude of the position
     * @param longitude the longitude of the position
     */
    Position(double id, long double latitude, long double longitude);

    /**
     * Gets the position id
     *
     * @return the position id
     */
    double getId() const;

    /**
     * Gets the position latitude
     *
     * @return the position latitude
     */
    long double getLatitude() const;

    /**
     * Gets the position longitude
     *
     * @return the position longitude
     */
    long double getLongitude() const;


    /**
     * Overload of the == operator
     * @param position the position to be compared with
     * @return true if position ids are equal, false otherwise
     */
    bool operator==(Position position);

    /**
     * Operator << overload
     *
     * @param os the output stream to be outputted
     * @param position the position object
     * @return the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Position& position);

    /**
     * Operator >> overload
     *
     * @param is the input stream to be outputted
     * @param position the position object
     * @return the input stream
     */
    friend std::istream& operator>>(std::istream& is, Position& position);
};

#endif //MARKETONWHEELS_POSITION_H
