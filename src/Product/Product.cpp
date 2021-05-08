#include "Product.h"

using namespace std;

/**
 * Id auxiliar to unique product id
 */
unsigned int Product::id_aux = 0;

/**
 * Product constructor
 *
 * @param name the name of the product
 * @param price the price of the product
 * @param size the size of the product
 */
Product::Product(const std::string& name, float price, unsigned size){
    if(price < 0) throw NegativeValue("price");
    id_aux++;
    this->id = id_aux;
    this->name = name;
    this->size = size;
    this->price = price;
}

/**
 * Gets the name of the product
 *
 * @return the name of the product
 */
std::string Product::getName() const {
    return name;
}

/**
 * Sets the name of the product
 *
 * @param name the products name
 */
void Product::setName(const std::string& name) {
    this->name = name;
}

/**
 * Gets the price of the product
 *
 * @return the products price
 */
float Product::getPrice() const {
    return price;
}

/**
 * Sets the price of the product
 *
 * @param price the products price
 */
void Product::setPrice(float price) {
    if(price < 0) throw NegativeValue("price");
    this->price = price;
}

/**
 * Gets the size of the product
 *
 * @return the products size
 */
unsigned int Product::getSize() const {
    return size;
}

/**
 * Sets the size of the product
 *
 * @param size the products size
 */
void Product::setSize(unsigned int size) {
    this->size = size;
}

/**
 * Gets the product id
 *
 * @return the product unique id
 */
unsigned int Product::getId() const {
    return id;
}

/**
 * Sets the product id
 */
void Product::setId(unsigned int id) {
    this->id = id;
}

/**
 * Overload of the == operator
 * @param product the product to be compared with
 * @return true if product ids are equal, false otherwise
 */
bool Product::operator==(Product product) {
    return id == product.getId();
}

/**
 * Overload of the << operator
 *
 * @param os the output stream to be outputted
 * @param product the product object
 * @return the output stream
 */
std::ostream &operator<<(ostream &os, const Product &product) {
    os << product.id << DELIMITER << product.name << DELIMITER;
    os << product.price << DELIMITER << product.size;
    return os;
}

/**
 * Overload of the >> operator
 *
 * @param is the input stream to be outputted
 * @param product the product object
 * @return the input stream
 */
std::istream &operator>>(istream &is, Product &product) {
    is >> product.id >> product.name >> product.price >> product.size;
    return is;
}
