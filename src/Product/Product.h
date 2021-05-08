#ifndef SRC_PRODUCT_H
#define SRC_PRODUCT_H

#include <string>
#include <Exceptions.h>

#define DELIMITER " "

class Product {
private:
    unsigned int id;
    /**
    * Id auxiliar to unique product id
    */
    static unsigned int id_aux;
    std::string name;
    float price;
    unsigned int size;

public:
    Product(){};

    /**
     * Product constructor
     *
     * @param name the name of the product
     * @param price the price of the product
     * @param size the size of the product
     */
    Product(const std::string& name, float price, unsigned int size);

    /**
     * Gets the name of the product
     *
     * @return the name of the product
     */
    std::string getName() const;

    /**
     * Gets the price of the product
     *
     * @return the products price
     */
    float getPrice() const;

    /**
     * Gets the size of the product
     *
     * @return the products size
     */
    unsigned int getSize() const;

    /**
     * Gets the product id
     *
     * @return the product unique id
     */
    unsigned int getId() const;



    /**
     * Sets the name of the product
     *
     * @param name the products name
     */
    void setName(const std::string& name);

    /**
     * Sets the price of the product
     *
     * @param price the products price
     */
    void setPrice(float price);

    /**
     * Sets the size of the product
     *
     * @param size the products size
     */
    void setSize(unsigned int size);

    /**
     * Sets the product id
     * @param id
     */
    void setId(unsigned int id);



    /**
     * Overload of the == operator
     * @param product the product to be compared with
     * @return true if product ids are equal, false otherwise
     */
    bool operator==(Product product);

    /**
     * Overload of the << operator
     *
     * @param is the output stream to be outputted
     * @param product the product object
     * @return the ostream stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Product& product);

    /**
     * Overload of the >> operator
     *
     * @param is the input stream to be outputted
     * @param product the product object
     * @return the input stream
     */
    friend std::istream& operator>>(std::istream& os, Product& product);
};

#endif //SRC_PRODUCT_H
