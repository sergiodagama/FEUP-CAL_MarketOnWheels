//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_PROVIDER_H
#define SRC_PROVIDER_H

#include <map>
#include "../Product/Product.h"

class Provider {
private:
    unsigned int id;
    static unsigned int id_aux;

    //stock
    std::map<Product*, unsigned > products;
public:
    Provider();
    Provider(std::map<Product*, unsigned > products);

    bool removeProduct(Product* product, unsigned number);
    bool addProduct(Product* product, unsigned number);

    int getNumProduct(Product* product);
    std::map<Product*, unsigned>getProducts();
    int getSizeProducts();
};


#endif //SRC_PROVIDER_H
