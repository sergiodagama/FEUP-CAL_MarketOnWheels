#ifndef MARKETONWHEELS_PRODUCTSWRAPPER_H
#define MARKETONWHEELS_PRODUCTSWRAPPER_H

#include <map>
#include <Product.h>

class ProductsWrapper {
private:
    std::map<Product*, unsigned int> products; //[product | quantity]
public:

    /**
     * ProductsWrapper constructor, a wrapper class to work with a map of products
     *
     * @param products the map with the products and it's respective quantities
     */
    ProductsWrapper(std::map<Product*, unsigned int> products);
    ProductsWrapper() {};

    /**
     * Gets the products map for further manipulation outside wrapper
     *
     * @return the products map
     */
    std::map<Product*, unsigned int> getProducts() const;

    /**
     * Gets total number of products
     *
     * @return total number of products, if none returns 0
     */
    unsigned int getNumOfProducts();

    /**
     * Gets the number of different products
     *
     * @return the different number of products
     */
    unsigned int getNumOfDifProducts();

    /**
     * Gets the quantity of a determined product
     *
     * @param product the product to search for
     * @return the quantity available of the product passed
     */
    unsigned int getQuantityOfProduct(Product* product);

    /**
     * Adds a product
     *
     * @param product the product to be added
     * @param quantity the quantity of product to be added
     */
    void addProduct(Product* product, unsigned int quantity);

    /**
     * Removes a product
     *
     * @param product the product to be removed
     */
    void removeProduct(Product* product);

    /**
     * Removes some quantity of a determined product
     *
     * @param product the product to remove quantity
     * @param quantity the quantity to be removed
     * @param quantity the quantity to be removed
     */
    void removeQuantityOfProduct(Product* product, unsigned int quantity);


    /**
     * Adds quantity to an existing product
     *
     * @param product the product to add quantity to
     * @param quantity the quantity to be added
     */
    void addQuantityOfProduct(Product* product, unsigned int quantity);
};

#endif //MARKETONWHEELS_PRODUCTSWRAPPER_H
