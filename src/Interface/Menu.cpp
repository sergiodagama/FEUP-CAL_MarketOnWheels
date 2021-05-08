#include <Menu.h>

using namespace std;

/**
 * Simple Menu constructor
 *
 * @param title the menu title
 */
Menu::Menu(const std::string& title){
    this->title = title;
}

/**
 * Complex Menu constructor
 *
 * @param title the menu title
 * @param option_names the option names vector
 */
Menu::Menu(std::string title, std::vector<std::string>& option_names){
    this->title = title;
    this->option_names  = option_names;
}

/**
 * Changes the menu title
 *
 * @param new_title the menu new title
 */
void Menu::changeTitle(std::string new_title){
    this->title = new_title;
}

/**
 * Add an option to the menu
 *
 * @param option_name the name of the option
 */
void Menu::addOption(std::string option_name){
    for(auto it = option_names.begin(); it != option_names.end(); it++){
        if(*it == option_name) throw NameAlreadyExists();
    }
    option_names.push_back(option_name);
}

/**
 * Deletes an option from the menu
 *
 * @param option_name the option name to be deleted
 */
void Menu::deleteOption(std::string option_name) {
    auto it = option_names.begin();

    for(; it != option_names.end(); it++){
        if(*it == option_name) break;
    }
    if(it == option_names.end()) throw NameDosNotExist();
    else option_names.erase(it);
}

/**
 * Prints the menu to user
 */
void Menu::show() {
    cout << "--> " << title << " <--" << endl;
    unsigned int n = 1;
    for(auto it = option_names.begin(); it != option_names.end(); it++){
        cout << n << ": " << *it << endl;
    }
}

/**
 * Gets input from user
 *
 * @return the input from the user, or zero in case of error (or none)
 */
unsigned int Menu::getInput() {
    unsigned int input = 0;
    cin >> input;
    return input;
}
