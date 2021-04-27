//
// Created by sergi on 24/04/2021.
//

#ifndef MARKETONWHEELS_INTERFACE_H
#define MARKETONWHEELS_INTERFACE_H

#include <string>
#include <vector>
#include "Menu.h"

class Interface {
private:
    unsigned int capacity;  //users capacity (both clients and providers together)
    std::vector<Menu*> menus;  //interface menus
public:
    void makeMenu(std::vector<std::string> option_names);
    unsigned int showMenu(unsigned int menu_id);
    void deleteMenu(unsigned int menu_id);
    void showInterface();
};


#endif //MARKETONWHEELS_INTERFACE_H
