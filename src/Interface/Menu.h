#ifndef MARKETONWHEELS_MENU_H
#define MARKETONWHEELS_MENU_H

#include <string>
#include <vector>
#include <iostream>
#include <Exceptions.h>

class Menu {
private:
    std::string title;
    std::vector<std::string> option_names; //all options are unique
public:
    Menu(const std::string& title);
    Menu(std::string title, std::vector<std::string>& option_names);
    void changeTitle(std::string new_title);
    void addOption(std::string option_name);
    void deleteOption(std::string option_name);
    unsigned int getInput();
    void show();
};

#endif //MARKETONWHEELS_MENU_H
