#ifndef SRC_PROVIDER_H
#define SRC_PROVIDER_H

#include <map>
#include "../ProductsWrapper/ProductsWrapper.h"

class Provider : public ProductsWrapper {
private:
    unsigned int id;
    static unsigned int id_aux;
    std::string name;
    std::string user_name; // TODO IN HEADQUARTER UNIQUE
public:
    Provider();
    Provider(std::string name, std::string user_name);
    Provider(std::string name, std::string user_name, std::map<Product *, unsigned int> products);
    unsigned int getId() const;
    void setName(const std::string& name);
    std::string getName() const;
    void setUserName(const std::string& user_name);
    std::string getUserName() const;
    friend std::ostream& operator<<(std::ostream& os, const Provider& provider);
    friend std::istream& operator>>(std::istream& is, Provider& provider);
};

#endif //SRC_PROVIDER_H
