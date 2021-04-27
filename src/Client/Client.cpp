//
// Created by eunic on 24/04/2021.
//

#include "Client.h"

using namespace std;

Client::Client(std::string name, std::string user_name, Date date, Vertex<T> *address, unsigned int capital) {
    this->name = name;
    this->user_name = user_name;
    this->birthday_date = date;
    this->address = address;
    this->capital = capital;
}

Client::Client(std::string name, std::string user_name, Date date, Vertex<T> *address){
    this->name = name;
    this->user_name = user_name;
    this->birthday_date = date;
    this->address = address;
}

void Client::setName(string name) {
    this->name = name;
}

std::string Client::getName() const {
    return name;
}

void Client::setUserName(string user_name) {
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

void Client::setCapital(int capital) {
    this->capital = capital;
}

unsigned int Client::getCapital() const {
    return capital;
}
