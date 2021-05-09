#include "Client.h"

using namespace std;

/**
 * Unique id auxiliar (autoincrement)
 */
unsigned int Client::id_aux = 0;

/**
 * Client constructor with capital
 *
 * @param name the name of the client
 * @param user_name the user name of the client they all have to be unique
 * @param date the birthday date of the client
 * @param address the address of the client (graph vertex)
 * @param capital the capital of the client
 */
Client::Client(const std::string& name, const std::string& user_name, Date date, Position *address, unsigned int capital) {
    id_aux++;
    this->id = id_aux;
    this->name = name;
    this->user_name = user_name;
    this->birthday_date = date;
    this->address = address;
    this->capital = capital;
}

/**
 * Client constructor without capital
 *
 * @param name the name of the client
 * @param user_name the user name of the client they all have to be unique
 * @param date the birthday date of the client
 * @param address the address of the client (graph vertex)
 */
Client::Client(const std::string& name, const std::string& user_name, Date date, Position *address){
    id_aux++;
    this->id = id_aux;
    this->name = name;
    this->user_name = user_name;
    this->birthday_date = date;
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
 * Sets the client birthday date
 *
 * @param date the birthday date of the client
 */
void Client::setDate(Date date) {
}

/**
 * Gets the birthday date of the client
 *
 * @return the birthday date of the client
 */
Date Client::getDate() const {
    return birthday_date;
}

/**
 * Sets the capital of the client
 *
 * @param capital the capital of the client
 */
void Client::setCapital(int capital) {
    this->capital = capital;
}

/**
 * Gets the capital of the client
 *
 * @return the client capital
 */
unsigned int Client::getCapital() const {
    return capital;
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
    os << client.user_name << DELIMITER << client.birthday_date << DELIMITER;
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
    is >> client.id >> client.name >> client.user_name >> client.birthday_date >> *client.address >> client.capital;
    return is;
}
