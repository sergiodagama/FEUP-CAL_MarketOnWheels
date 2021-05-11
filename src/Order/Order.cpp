#include <Order.h>

using namespace std;

unsigned int Order::id_aux = 0;

Order::Order(std::map<Product *, unsigned int> products, unsigned int client_id) : ProductsWrapper(products) {
    id_aux++;
    this->id = id_aux;
    this->client_id = client_id;
}

Order::Order() : ProductsWrapper() {
    id_aux++;
    this->id = id_aux;
    this->client_id = 0;
}

Order::Order(unsigned int client_id) {
    id_aux++;
    this->id = id_aux;
    this->client_id = client_id;
}

unsigned int Order::getId() const {
    return id;
}

std::ostream &operator<<(ostream &os, const Order &order) {
    os << order.id << DELIMITER << order.client_id << endl;

    map<Product *, unsigned int> prods = order.getProducts();

    for (auto it = prods.begin(); it != prods.end(); it++) {
        os << (*it).first->getId() << DELIMITER << it->second << endl;
    }
    os << "_" << endl;
    return os;
}

std::istream &operator>>(istream &is, Order &order) {
    is >> order.id >> order.client_id;
    return is;
}

unsigned int Order::getClientId() const {
    return client_id;
}

void Order::setClientId(unsigned int client_id) {
    this->client_id = client_id;
}
