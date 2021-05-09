#include "Order.h"

using namespace std;

/**
 * Id auxiliar to unique order id
 */
unsigned int Order::id_aux = 0;

/**
 * Order constructor
 *
 * @param products the map with the products and it's respective quantities to be ordered
 */
Order::Order(std::map<Product *, unsigned int> products) : ProductsWrapper(products) {
    id_aux++;
    this->id = id_aux;
}

Order::Order() : ProductsWrapper(){
    id_aux++;
    this->id = id_aux;
}

/**
 * Gets the order id
 *
 * @return the order id
 */
unsigned int Order::getId() const {
    return id;
}

/**
 * Gets the total size of the order (sum of the the size of all products)
 *
 * @return the size of the order, 0 in case there is none
 */

unsigned int Order::getSize() const {
    unsigned int size = 0;
    for (auto & product : getProducts()) {
        size += product.second * product.first->getSize();
    }
    return size;
}


/**
 * Gets the total price of an order (sum of all products prices)
 *
 * @return the order price, if none returns 0
 */

float Order::getPrice() const {
    float price = 0;
    for(auto & product : getProducts()){
        price += (product.second * product.first->getPrice());
    }
    return price;
}

/**
 * Overload to the << operator of Order
 *
 * @param os the output stream to be outputted
 * @param order the order object
 * @return the output stream
 */
std::ostream &operator<<(ostream &os, const Order &order) {
    os << order.id << endl;

    map<Product*, unsigned int> prods = order.getProducts();

    for(auto it = prods.begin(); it != prods.end(); it++){
        os << it->first << DELIMITER << it->second << endl;
    }
    return os;
}

/**
 * Overload of >> operator
 *
 * @param is the input stream to be outputted
 * @param order the order object
 * @return the input stream
 */
std::istream &operator>>(istream &is, Order &order) {
    is >> order.id;

    Product* product;
    unsigned int quantity;

    while(!is.eof()) {
        is >> *product >> quantity;
        order.addProduct(product, quantity);
    }
    return is;
}
