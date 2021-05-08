#include "Client.h"

using namespace std;

unsigned int Client::id_aux = 0;

Client::Client(const std::string& name, const std::string& user_name, Position *address){
    this->name = name;
    this->user_name = user_name;
    this->address = address;
    id = id_aux;
    id_aux ++;
}

unsigned int Client::getId() const {
    return id;
}

void Client::setId(unsigned int id) {
    this->id = id;
}

void Client::setName(const string& name) {
    this->name = name;
}

std::string Client::getName() const {
    return name;
}

void Client::setUserName(const string& user_name) {
    this->user_name = user_name;
}

std::string Client::getUserName() const {
    return user_name;
}

void Client::setAddress(Position *position) {
    this->address = position;
}

Position *Client::getAddress() const {
    return address;
}

ostream &operator<<(ostream &os, const Client &client) {
    os << client.id << DELIMITER << client.name << DELIMITER;
    os << client.user_name << DELIMITER;
    os << (*client.address).getId() << endl;
    return os;
}


istream &operator>>(istream &is, Client &client) {
    is >> client.id >> client.name >> client.user_name >> *client.address;
    return is;
}
