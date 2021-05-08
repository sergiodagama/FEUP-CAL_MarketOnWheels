//
// Created by sergi on 27/04/2021.
//

#ifndef MARKETONWHEELS_MENU_H
#define MARKETONWHEELS_MENU_H

#include <string>
#include <vector>
#include <iostream>

class Menu {
private:
    unsigned int style_id = 0;  //controls the style being showed, default 0
    std::string title;
    std::vector<std::string> option_names;

public:
    Menu(std::string title);
    Menu(std::string title, std::vector<std::string> option_names);
    void show();
    void changeTitle(std::string new_title);
    void addOption(std::string option_name);
    void deleteOption(std::string option_name);
    void changeStyle(unsigned int style_id);
    void setExit(unsigned int option_number);
    unsigned int getExit() const;
    unsigned int getInput();
};


#endif //MARKETONWHEELS_MENU_H
