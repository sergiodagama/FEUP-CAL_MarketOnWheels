#include <Provider.h>

using namespace std;

unsigned int Provider::id_aux = 0;

Provider::Provider(string name, string user_name, map<Product *, unsigned int> products) : ProductsWrapper(products) {
    id_aux++;
    this->id = id_aux;
    this->name = name;
    this->user_name = user_name;
}

unsigned int Provider::getId() const {
    return id;
}

void Provider::setName(const string &name) {
    this->name = name;
}

std::string Provider::getName() const {
    return this->name;
}

void Provider::setUserName(const string &user_name) {
    this->user_name = user_name;
}

std::string Provider::getUserName() const {
    return user_name;
}

std::ostream &operator<<(ostream &os, const Provider &provider) {
    os << provider.id << DELIMITER << provider.name << DELIMITER;
    os << provider.user_name << endl;

    map<Product *, unsigned int> prods = provider.getProducts();

    for (auto it = prods.begin(); it != prods.end(); it++) {
        os << it->first->getId() << DELIMITER << it->second << endl;
    }
    os << "_" << endl;
    return os;
}

std::istream &operator>>(istream &is, Provider &provider) {
    is >> provider.id >> provider.name >> provider.user_name;
    return is;
}

Provider::Provider() : ProductsWrapper() {
    id_aux++;
    this->id = id_aux;

}

Provider::Provider(std::string name, std::string user_name) {
    id_aux++;
    this->id = id_aux;
    this->name = name;
    this->user_name = user_name;
}
