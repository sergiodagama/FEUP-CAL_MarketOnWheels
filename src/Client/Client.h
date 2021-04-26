//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_CLIENT_H
#define SRC_CLIENT_H

#include <string>
#include "../Utils/Graph.h"
#include "../Utils/Date.h"


class Client {
private:
    unsigned int id;
    std::string name;
    std::string user_name;
    Date birthday_date;
    //Vertex<T>* address;
    unsigned int capital;
public:
    //Client(std::string name, std::string user_name, Date date, Vertex<T>* address, unsigned int capital);
    //Client(std::string name, std::string user_name, Date date, Vertex<T>* address);
    void setName(std::string name);
    std::string getName() const;
    void setUserName(std::string user_name);
    std::string getUserName() const;
    void setDate(Date date);
    Date getDate() const;
    void setCapital(int capital);
    unsigned int getCapital() const;
};


#endif //SRC_CLIENT_H
