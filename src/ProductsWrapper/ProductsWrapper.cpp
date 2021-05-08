#include "ProductsWrapper.h"

using namespace std;

/**
 * ProductsWrapper constructor, a wrapper class to work with a map of products
 *
 * @param products the map with the products and it's respective quantities
 */
ProductsWrapper::ProductsWrapper(std::map<Product*, unsigned int> products) {
    this->products = move(products);
}

/**
 * Gets the products map for further manipulation outside wrapper
 *
 * @return the products map
 */
std::map<Product *, unsigned int> ProductsWrapper::getProducts() const {
    return this->products;
}

/**
 * Gets total number of products
 *
 * @return total number of products, if none returns 0
 */
unsigned int ProductsWrapper::getNumOfProducts() {
    unsigned int diff = 0;
    for(auto & product : products){
        diff += product.second;
    }
    return diff;
}

/**
 * Gets the number of different products
 *
 * @return the different number of products
 */
unsigned int ProductsWrapper::getNumOfDifProducts() {
    return products.size();
}

/**
 * Gets the quantity of a determined product
 *
 * @param product the product to search for
 * @return the quantity available of the product passed
 */
unsigned int ProductsWrapper::getQuantityOfProduct(Product* product) {
    if(products.find(product) == products.end()) throw ProductNotFound();
    return products.at(product);
}

/**
 * Adds a product
 *
 * @param product the product to be added
 * @param quantity the quantity of product to be added
 */
void ProductsWrapper::addProduct(Product* product, unsigned int quantity) {
    if(products.find(product) != products.end()) throw ProductAlreadyExists();
    else {
        products.insert(pair<Product*, unsigned int>(product, quantity));
    }
}

/**
 * Removes a product
 *
 * @param product the product to be removed
 */
void ProductsWrapper::removeProduct(Product* product) {
    if(products.find(product) == products.end()) throw ProductNotFound();
    else {
        products.erase(product);
    }
}

/**
 * Removes some quantity of a determined product
 *
 * @param product the product to remove quantity
 * @param quantity the quantity to be removed
 * @param quantity the quantity to be removed
 */
void ProductsWrapper::removeQuantityOfProduct(Product *product, unsigned int quantity) {
    if(products.find(product) == products.end()) throw ProductNotFound();

    int old_quantity = products.at(product);
    int new_quantity = old_quantity - quantity;

    products.erase(product);

    if (new_quantity > 0) products.insert(pair<Product *, unsigned int>(product, new_quantity));
    else throw InvalidQuantity();
}

/**
 * Adds quantity to an existing product
 *
 * @param product the product to add quantity to
 * @param quantity the quantity to be added
 */
void ProductsWrapper::addQuantityOfProduct(Product *product, unsigned int quantity) {
    if(products.find(product) == products.end()) throw ProductNotFound();

    int old_quantity = products.at(product);
    int new_quantity = old_quantity + quantity;

    products.erase(product);

    products.insert(pair<Product *, unsigned int>(product, new_quantity));
}
