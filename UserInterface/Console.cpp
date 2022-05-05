//
// Created by Tudor on 5/4/2022.
//

#include "Console.h"

Console::Console(UserService &userService) : userService(userService) {}

void Console::showMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Add user." << '\n';
    std::cout << "2. Check users." << '\n';
    std::cout << "3. Update user." << '\n';
    std::cout << "4. Delete user." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::uiAddUser() {
    User user;
    std::cin >> user;

    userService.create(user);
}

void Console::uiCheckUser() {
    if(userService.read().empty()) {
        std::cout << "No users created." << '\n';
    }
    else {
        for (int i = 0; i < userService.read().size(); i++) {
            std::cout << userService.read()[i] << '\n';
        }
    }
}

void Console::uiUpdateUser() {
    unsigned int id;
    std::cout << "Update user with this id:";
    std::cin >> id;

    User newUser;
    std::cin >> newUser;

    userService.update(id, newUser);
}

void Console::uiDeleteUser() {
    unsigned int id;
    std::cout << "Delete user with this id:";
    std::cin >> id;

    userService.del(id);
}

void Console::runMenu() {
    char menuOption;
    do {
        showMenu();
        std::cin >> menuOption;
        std::cout << '\n';
        switch(menuOption) {
            case '1': {
                uiAddUser();
                break;
            }
            case '2': {
                uiCheckUser();
                break;
            }
            case '3': {
                uiUpdateUser();
                break;
            }
            case '4': {
                uiDeleteUser();
                break;
            }
            case 'x': {
                break;
            }
            default: {
                std::cout << "Invalid option! Please try again!" << '\n';
            }
        }
    }while(menuOption != 'x');
}
