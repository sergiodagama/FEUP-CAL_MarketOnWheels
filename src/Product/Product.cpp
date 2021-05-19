#include "Product.h"

using namespace std;

unsigned int Product::id_aux = 0;

Product::Product(const std::string &name, float price, unsigned size) {
    if (price < 0) throw NegativeValue("price");
    id_aux++;
    this->id = id_aux;
    this->name = name;
    this->size = size;
    this->price = price;
}

std::string Product::getName() const {
    return name;
}

void Product::setName(const std::string &name) {
    this->name = name;
}

float Product::getPrice() const {
    return price;
}

void Product::setPrice(float price) {
    if (price < 0) throw NegativeValue("price");
    this->price = price;
}

unsigned int Product::getSize() const {
    return size;
}

void Product::setSize(unsigned int size) {
    this->size = size;
}

unsigned int Product::getId() const {
    return id;
}

void Product::setId(unsigned int id) {
    this->id = id;
}

bool Product::operator==(Product product) {
    return id == product.getId();
}

std::ostream &operator<<(ostream &os, const Product &product) {
    os << product.id << DELIMITER << product.name << DELIMITER;
    os << product.price << DELIMITER << product.size << endl;
    return os;
}

std::istream &operator>>(istream &is, Product &product) {
    is >> product.id >> product.name >> product.price >> product.size;
    return is;
}
