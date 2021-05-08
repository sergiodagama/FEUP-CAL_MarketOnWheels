#ifndef SRC_PRODUCT_H
#define SRC_PRODUCT_H

#include <string>
#include <Exceptions.h>

#define DELIMITER " "

class Product {
private:
    unsigned int id;
    static unsigned int id_aux;
    std::string name;
    float price;
    unsigned int size;
public:
    Product(const std::string& name, float price, unsigned int size);
    std::string getName() const;
    void setName(const std::string& name);
    float getPrice() const;
    void setPrice(float price);
    unsigned int getSize() const;
    void setSize(unsigned int size);
    unsigned int getId() const;
    bool operator==(Product product);
    friend std::ostream& operator<<(std::ostream& os, const Product& product);
};

#endif //SRC_PRODUCT_H
