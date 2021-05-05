//
// Created by sergi on 27/04/2021.
//

#include "Menu.h"

using namespace std;

Menu::Menu(std::string title){
    this->title = title;
}

Menu::Menu(std::string title, std::vector<std::string> option_names){
    this->title = title;
    this->option_names  = option_names;
}

void changeTitle(std::string new_title){
  //  this->title = new_title;
}

void Menu::addOption(std::string option_name){
    option_names.push_back(option_name);
}

void Menu::changeStyle(unsigned int style_id){
    this->style_id = style_id;
}

void Menu::setExit(unsigned int option_number){
    this->exit_option = option_number;
}

unsigned int Menu::getExit() const{
    return this->exit_option;
}

unsigned int Menu::getInput(){
    unsigned int user_input;
    cout << "-> ";
    cin >> user_input;
    if(user_input <= 0 || user_input > option_names.size()){
        user_input = 0;
        cout << "Please input a valid number!" << endl;
    }
    return user_input;
}

void Menu::show(){
    switch (style_id) {
        case 0: {
            cout << "---------- " << title << " ----------" << endl;
            cout << "please input the correspondent number";
            for(int i = 1; i <= option_names.size(); i++){
                cout << i << " -> " << option_names.at(i - 1) << endl;
            }
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            break;
        }
        default:
          //  throw InvalidStyle();
            break;
    }
}