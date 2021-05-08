#include "Provider.h"

using namespace std;

/**
 * Id auxiliar to unique provider id
 */
unsigned int Provider::id_aux = 0;

 /**
  * Provider constructor
  *
  * @param name the name of the distributor (company)
  * @param user_name the user name of the provider (user to use than name)
  * @param products the stock of the provider products
  */
 Provider::Provider(string name, string user_name, map<Product *, unsigned int> products) : ProductsWrapper(products) {
    this->id = id_aux;
    id_aux++;
    this->name = name;
    this->user_name = user_name;
}

/**
 * Gets provider id
 *
 * @return the provider id
 */
unsigned int Provider::getId() const {
    return id;
}

/**
 * Sets the provider name
 *
 * @param name the provider name
 */
void Provider::setName(const string& name) {
    this->name = name;
}

/**
 * Gets the name of the provider
 *
 * @return the provider's name
 */
std::string Provider::getName() const {
    return name;
}

/**
 * Sets the provider user name
 *
 * @param user_name the user name of the provider
 */
void Provider::setUserName(const string& user_name) {
    this->user_name = user_name;
}

/**
 * Gets the provider user name
 *
 * @return the user name of the provider
 */
std::string Provider::getUserName() const {
    return user_name;
}

/**
 * Overload to << operator of Provider
 *
 * @param os the output stream to be outputted
 * @param provider the provider object
 * @return the output stream
 */
std::ostream &operator<<(ostream &os, const Provider &provider) {
    os << provider.id << DELIMITER << provider.name << DELIMITER;
    os << provider.user_name << endl;

    map<Product*, unsigned int> prods = provider.getProducts();

    for(auto it = prods.begin(); it != prods.end(); it++){
        os << it->first << DELIMITER << it->second << endl;
    }
    return os;
}
