#include "Client.h"

using namespace std;

/**
 * Unique id auxiliar (autoincrement)
 */
unsigned int Client::id_aux = 0;

/**
 * Client constructor without capital
 *
 * @param name the name of the client
 * @param user_name the user name of the client they all have to be unique
 * @param date the birthday date of the client
 * @param address the address of the client (graph vertex)
 */
Client::Client(const std::string& name, const std::string& user_name, Position *address){
    this->name = name;
    this->user_name = user_name;
    this->address = address;
}

/**
 * Gets the client unique id
 *
 * @return the client id
 */
unsigned int Client::getId() const {
    return id;
}

/**
 * Sets id of client
 */
void Client::setId(unsigned int id) {
    this->id = id;
}

/**
 * Sets the client name
 *
 * @param name the client name
 */
void Client::setName(const string& name) {
    this->name = name;
}

/**
 * Gets the client name
 *
 * @return the client name
 */
std::string Client::getName() const {
    return name;
}

/**
 * Sets the user_name of the client
 *
 * @param user_name the client user name
 */
void Client::setUserName(const string& user_name) {
    this->user_name = user_name;
}

/**
 * Gets the client user name
 *
 * @return the client user name
 */
std::string Client::getUserName() const {
    return user_name;
}

/**
 * Sets the address of the client
 *
 * @param position the address of the client
 */
void Client::setAddress(Position *position) {
    this->address = position;
}

/**
 * Gets the address of the client
 *
 * @return the address of the client
 */
Position *Client::getAddress() const {
    return address;
}

/**
 * Overload to << operator of Client
 *
 * @param os the output stream to be outputted
 * @param client the client object
 * @return the output stream
 */
ostream &operator<<(ostream &os, const Client &client) {
    os << client.id << DELIMITER << client.name << DELIMITER;
    os << client.user_name << DELIMITER;
    os << *client.address << endl;
    return os;
}

/**
 * Overload to >> operator of Client
 *
 * @param os the input stream to be outputted
 * @param client the client object
 * @return the output stream
 */
istream &operator>>(istream &is, Client &client) {
    is >> client.id >> client.name >> client.user_name >> *client.address;
    return is;
}
