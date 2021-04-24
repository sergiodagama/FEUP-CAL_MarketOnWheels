//
// Created by eunic on 24/04/2021.
//

#ifndef SRC_PROVIDER_H
#define SRC_PROVIDER_H

#include <map>
#include "../Product/Product.h"

class Provider {
public:
    Provider();
private:
    std::map<Product*, int> products;
};


#endif //SRC_PROVIDER_H
