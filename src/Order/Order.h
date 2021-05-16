#ifndef SRC_ORDER_H
#define SRC_ORDER_H

#include <map>
#include "../ProductsWrapper/ProductsWrapper.h"

class Order : public ProductsWrapper {
private:
    unsigned int id;

    /**
    * Id auxiliar to unique order id
    */
    static unsigned int id_aux;
    unsigned int client_id;
public:

    /**
    * Order constructor
    *
    * @param products the map with the products and it's respective quantities to be ordered
    */
    Order(std::map<Product *, unsigned int> products, unsigned int client_id);

    /**
     * Void order constructor
     */
    Order();

    /**
     * Simple constructor for order
     *
     * @param client_id the client id
     */
    Order(unsigned int client_id);

    /**
    * Gets the order id
    *
    * @return the order id
    */
    unsigned int getId() const;

    /**
     * Gets the client associated with that order
     *
     * @return the client id
     */
    unsigned int getClientId() const;

    /**
     * Sets the client id
     *
     * @param client_id the client id associated
     */
    void setClientId(unsigned int client_id);

    /**
    * Overload to the << operator of Order
    *
    * @param os the output stream to be outputted
    * @param order the order object
    * @return the output stream
    */
    friend std::ostream& operator<<(std::ostream& os, const Order& order);

    /**
    * Overload of >> operator
    *
    * @param is the input stream to be outputted
    * @param order the order object
    * @return the input stream
    */
    friend std::istream& operator>>(std::istream& is, Order& order);

    /**
     * Overload of < operator for sorting
     * @param order1 the first order to compare
     * @param order2 the second order to compare with
     * @return true if smaller, false otherwise
     */
    friend bool operator<(const Order& order1, const Order& order2);
};

#endif //SRC_ORDER_H
