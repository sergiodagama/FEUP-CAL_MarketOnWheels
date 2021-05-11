#include <Menu.h>

using namespace std;

Menu::Menu(const std::string& title){
    this->title = title;
}

Menu::Menu(std::string title, std::vector<std::string>& option_names){
    this->title = title;
    this->option_names  = option_names;
}

void Menu::changeTitle(std::string new_title){
    this->title = new_title;
}

void Menu::addOption(std::string option_name){
    for(auto it = option_names.begin(); it != option_names.end(); it++){
        if(*it == option_name) throw NameAlreadyExists();
    }
    option_names.push_back(option_name);
}

void Menu::deleteOption(std::string option_name) {
    auto it = option_names.begin();

    for(; it != option_names.end(); it++){
        if(*it == option_name) break;
    }
    if(it == option_names.end()) throw NameDosNotExist();
    else option_names.erase(it);
}

void Menu::show() {
    cout << "### " << title << " ###" << endl;
    unsigned int n = 1;
    for(auto it = option_names.begin(); it != option_names.end(); it++){
        cout << n << ": " << *it << endl;
        n++;
    }
}

unsigned int Menu::getInput() {
    unsigned int input = 0;
    do {
        cout << "->";
        cin >> input;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(cin.fail() || input > option_names.size());
    return input;
}
