#include "Provider.h"

using namespace std;

unsigned int Provider::id_aux = 0;

Provider::Provider() : ProductsWrapper(){

}

Provider::Provider(string name, string user_name, map<Product *, unsigned int> products) : ProductsWrapper(products) {
     id_aux++;
     this->id = id_aux;
    this->name = name;
    this->user_name = user_name;
}

unsigned int Provider::getId() const {
    return id;
}


std::string Provider::getName() const {
    return this->name;
}

std::string Provider::getUserName() const {
    return user_name;
}

void Provider::setName(const string& name) {
    this->name = name;
}

void Provider::setUserName(const string& user_name) {
    this->user_name = user_name;
}


std::ostream &operator<<(ostream &os, const Provider &provider) {
    os << provider.id << DELIMITER << provider.name << DELIMITER;
    os << provider.user_name << endl;

    map<Product*, unsigned int> prods = provider.getProducts();
    cout << provider.getProducts().size() << endl;

    for(auto it = prods.begin(); it != prods.end(); it++){
        os << *it->first << DELIMITER << it->second << endl;
    }
    os << "_" << endl;
    return os;
}


std::istream &operator>>(istream &is, Provider &provider) {
    is >> provider.id >> provider.name >> provider.user_name;

    unsigned int quantity;
    int acc = 5;
    Product product;
   // ) {
    /*while(is.peek() != '_' ) {
        cout << (is.peek() == '_') << endl;
        provider.addProduct(product, quantity);
        is >> * product >> quantity;
        acc--;
    }*/

    is >> product >> quantity;
    cout << product.getId() << endl;

    return is;
}



