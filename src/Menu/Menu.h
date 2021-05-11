#ifndef MARKETONWHEELS_MENU_H
#define MARKETONWHEELS_MENU_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <Exceptions.h>

class Menu {
private:
    std::string title;
    std::vector<std::string> option_names; //all options are unique
public:

    /**
    * Simple Menu constructor
    *
    * @param title the menu title
    */
    Menu(const std::string& title);

    /**
    * Complex Menu constructor
    *
    * @param title the menu title
    * @param option_names the option names vector
    */
    Menu(std::string title, std::vector<std::string>& option_names);

    /**
    * Changes the menu title
    *
    * @param new_title the menu new title
    */
    void changeTitle(std::string new_title);

    /**
    * Add an option to the menu
    *
    * @param option_name the name of the option
    */
    void addOption(std::string option_name);

    /**
    * Deletes an option from the menu
    *
    * @param option_name the option name to be deleted
    */
    void deleteOption(std::string option_name);

    /**
    * Gets input from user
    *
    * @return the input from the user, or zero in case of error (or none)
    */
    unsigned int getInput();

    /**
    * Prints the menu to user
    */
    void show();
};

#endif //MARKETONWHEELS_MENU_H
