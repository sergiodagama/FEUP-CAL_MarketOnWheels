//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_ORDER_H
#define SRC_ORDER_H

#include <map>
#include "../Product/Product.h"
#include "../Utils/Date.h"
#include "../Utils/Utils.h"


class Order {
private:
    std::map<Product*, unsigned int> products;

    unsigned int id;
    unsigned int idClient;
    unsigned int idProvider;
    unsigned int idTruck;
    Date date;
    ::state state;
    double finalPrice;

public:

    Order(std::map<Product*, unsigned int> products);
    Order(unsigned int id, ::state state, Date date, unsigned int idClient,unsigned int idProvider,unsigned int idTruck, double finalPrice);

    void addProduct(Product* product, unsigned int quantity);
    void removeProduct(Product *product);
    void removeQuantityOfProduct(Product *product, unsigned int quantity);
    unsigned int getNumOfProducts();
    unsigned int getNumOfDifProducts();
    unsigned int getSize();
    float calculatePrice();

    Date getDate();
    unsigned int getId();
    unsigned int getIdClient();
    unsigned int getIdProvider();
    unsigned int getIdTruck();
    double getFinalPrice();
    ::state getState();

};


#endif //SRC_ORDER_H
