//
// Created by sergi on 24/04/2021.
//

#include "Interface.h"

unsigned int Interface::showMenu(unsigned int menu_id){
    unsigned int input = 0;
    while(!input){
        menus.at(menu_id)->show();
        input = menus.at(menu_id)->getInput();
    }
    if(input == menus.at(menu_id)->getExit()) exit(0);  // user press exit
    else {
        return input;  //for all the other options
    }
}

void Interface::showInterface(){
    unsigned int input = 0;
    input = showMenu(0);
    switch (input) {
        case 0:{
            break;
        }
        //...
        default: {
            break;
        }
    }
    //... do this for all the menus created and needed
}