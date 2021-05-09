#ifndef SRC_ORDER_H
#define SRC_ORDER_H

#include <map>
#include "../ProductsWrapper/ProductsWrapper.h"

class Order : public ProductsWrapper {
private:
    unsigned int id;
    static unsigned int id_aux;
public:
    Order(std::map<Product *, unsigned int> products);
    Order();
    unsigned int getId() const;

    unsigned int getSize() const;
    float getPrice() const;
    friend std::ostream& operator<<(std::ostream& os, const Order& order);
    friend std::istream& operator>>(std::istream& is, Order& order);
};

#endif //SRC_ORDER_H
