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
    std::map<Product*, unsigned int> products;
public:

    /**
     * Order constructor
     *
     * @param products the map with the products and it's respective quantities to be ordered
     */
    Order(std::map<Product *, unsigned int> products);

    /**
     * Gets the order id
     *
     * @return the order id
     */
    unsigned int getId() const;

    /**
     * Gets the total size of the order (sum of the the size of all products)
     *
     * @return the size of the order, 0 in case there is none
     */
    unsigned int getSize() const;

    /**
     * Gets the total price of an order (sum of all products prices)
     *
     * @return the order price, if none returns 0
     */
    float getPrice() const;


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
};

#endif //SRC_ORDER_H
