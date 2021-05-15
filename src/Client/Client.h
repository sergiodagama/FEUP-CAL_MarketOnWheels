#ifndef SRC_CLIENT_H
#define SRC_CLIENT_H

#include "../Utils/Graph.h"
#include "../Utils/Date.h"
#include "../Position/Position.h"

class Client {
private:
     /**
     * Unique id auxiliar (autoincrement)
     */
    unsigned int id{};
    static unsigned int id_aux;
    std::string name;
    std::string user_name;
    Date birthday_date{};
    unsigned int position_id;
public:
    /**
    * Client constructor
    *
    * @param name the name of the client
    * @param user_name the user name of the client they all have to be unique
    * @param date the birthday date of the client
    * @param address the address of the client (graph vertex)
    */
    Client(const std::string &name, const std::string &user_name, Date date, unsigned int address);

    /**
    * Gets the client unique id
    *
    * @return the client id
    */
    unsigned int getId() const;

    /**
    * Sets id of client
    */
    void setId(unsigned int id);

    /**
    * Sets the client name
    *
    * @param name the client name
    */
    void setName(const std::string &name);

    /**
    * Gets the client name
    *
    * @return the client name
    */
    std::string getName() const;

    /**
    * Sets the user_name of the client
    *
    * @param user_name the client user name
    */
    void setUserName(const std::string &user_name);

    /**
    * Gets the client user name
    *
    * @return the client user name
    */
    std::string getUserName() const;

    /**
    * Sets the client birthday date
    *
    * @param date the birthday date of the client
    */
    void setDate(Date date);

    /**
    * Gets the birthday date of the client
    *
    * @return the birthday date of the client
    */
    Date getDate() const;

    /**
    * Sets the address of the client
    *
    * @param position the address of the client
    */
    void setAddress(unsigned int position_id);

    /**
    * Gets the address of the client
    *
    * @return the address of the client
    */
    unsigned int getAddress() const;

    /**
    * Overload to << operator of Client
    *
    * @param os the output stream to be outputted
    * @param client the client object
    * @return the output stream
    */
    friend std::ostream &operator<<(std::ostream &os, const Client &client);

    /**
    * Overload to >> operator of Client
    *
    * @param os the input stream to be outputted
    * @param client the client object
    * @return the output stream
    */
    friend std::istream &operator>>(std::istream &is, Client &client);
};

#endif //SRC_CLIENT_H
