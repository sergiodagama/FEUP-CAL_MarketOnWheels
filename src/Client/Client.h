#ifndef SRC_CLIENT_H
#define SRC_CLIENT_H

#include "../Utils/Graph.h"
#include "../Utils/Date.h"
#include "../Position/Position.h"

class Client {
private:
    unsigned int id{};
    static unsigned int id_aux;
    std::string name;
    std::string user_name;  //TODO IN HEADQUARTER UNIQUE
    Position* address;
public:
    Client(const std::string& name, const std::string& user_name, Date date, Position *address);
    unsigned int getId() const;
    void setId(unsigned int id);
    void setName(const std::string& name);
    std::string getName() const;
    void setUserName(const std::string& user_name);
    std::string getUserName() const;
    void setAddress(Position *position);
    Position* getAddress() const;
    friend std::ostream& operator<<(std::ostream& os, const Client& client);
    friend std::istream& operator>>(std::istream& is, Client& client);
};

#endif //SRC_CLIENT_H
