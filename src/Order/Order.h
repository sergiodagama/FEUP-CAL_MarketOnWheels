#ifndef SRC_ORDER_H
#define SRC_ORDER_H

#include <map>
#include "../ProductsWrapper/ProductsWrapper.h"

class Order : public ProductsWrapper {
private:
    unsigned int id;
    static unsigned int id_aux;
    unsigned int client_id;
public:
    Order(std::map<Product *, unsigned int> products, unsigned int client_id);
    Order();
    Order(unsigned int client_id);
    unsigned int getId() const;
    unsigned int getClientId() const;
    void setClientId(unsigned int client_id);

    friend std::ostream& operator<<(std::ostream& os, const Order& order);
    friend std::istream& operator>>(std::istream& is, Order& order);
};

#endif //SRC_ORDER_H
