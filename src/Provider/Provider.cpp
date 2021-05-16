#include <Provider.h>

using namespace std;

unsigned int Provider::id_aux = 0;

Provider::Provider(string name, string user_name, map<Product *, unsigned int> products, unsigned int position_id) : ProductsWrapper(products) {
    id_aux++;
    this->id = id_aux;
    this->name = name;
    this->user_name = user_name;
    this->position_id = position_id;
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
    os << provider.user_name << DELIMITER << provider.position_id << endl;

    map<Product *, unsigned int> prods = provider.getProducts();

    for (auto it = prods.begin(); it != prods.end(); it++) {
        os << it->first->getId() << DELIMITER << it->second << endl;
    }
    os << "_" << endl;
    return os;
}

std::istream &operator>>(istream &is, Provider &provider) {
    is >> provider.id >> provider.name >> provider.user_name >> provider.position_id;
    return is;
}

Provider::Provider() : ProductsWrapper() {
    id_aux++;
    this->id = id_aux;

}

Provider::Provider(std::string name, std::string user_name, unsigned int position_id) {
    id_aux++;
    this->id = id_aux;
    this->name = name;
    this->user_name = user_name;
    this->position_id = position_id;
}

void Provider::setAddress(unsigned int position_id) {
    this->position_id = position_id;
}

unsigned int Provider::getAddress() const {
    return position_id;
}
