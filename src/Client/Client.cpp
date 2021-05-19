#include "Client.h"

using namespace std;

unsigned int Client::id_aux = 0;

Client::Client(const std::string &name, const std::string &user_name, Date date, unsigned int address) {
    id_aux++;
    this->id = id_aux;
    this->name = name;
    this->user_name = user_name;
    this->birthday_date = date;
    this->position_id = address;
}

unsigned int Client::getId() const {
    return id;
}

void Client::setId(unsigned int id) {
    this->id = id;
}

void Client::setName(const string &name) {
    this->name = name;
}

std::string Client::getName() const {
    return name;
}

void Client::setUserName(const string &user_name) {
    this->user_name = user_name;
}

std::string Client::getUserName() const {
    return user_name;
}

void Client::setDate(Date date) {
}

Date Client::getDate() const {
    return birthday_date;
}

void Client::setAddress(unsigned int position) {
    this->position_id = position;
}

unsigned int Client::getAddress() const {
    return position_id;
}

ostream &operator<<(ostream &os, const Client &client) {
    os << client.id << DELIMITER << client.name << DELIMITER;
    os << client.user_name << DELIMITER << client.birthday_date << DELIMITER;
    os << client.position_id << endl;
    return os;
}

istream &operator>>(istream &is, Client &client) {
    is >> client.id >> client.name >> client.user_name >> client.birthday_date >> client.position_id;
    return is;
}
