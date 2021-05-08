#include "Order.h"

using namespace std;


unsigned int Order::id_aux = 0;


Order::Order(std::map<Product *, unsigned int> products) : ProductsWrapper(products) {
    id_aux++;
    this->id = id_aux;
}

unsigned int Order::getId() const {
    return id;
}

unsigned int Order::getSize() const {
    unsigned int size = 0;
    for (auto & product : products) {
        size += product.second * product.first->getSize();
    }
    return size;
}

float Order::getPrice() const {
    float price = 0;
    for(auto & product : products){
        price += (product.second * product.first->getPrice());
    }
    return price;
}


std::ostream &operator<<(ostream &os, const Order &order) {
    os << order.id << endl;

    map<Product*, unsigned int> prods = order.getProducts();

    for(auto it = prods.begin(); it != prods.end(); it++){
        os << it->first << DELIMITER << it->second << endl;
    }
    return os;
}


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
