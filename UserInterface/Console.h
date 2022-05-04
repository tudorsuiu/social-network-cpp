//
// Created by Tudor on 5/4/2022.
//

#ifndef PROIECT_SDA_CONSOLE_H
#define PROIECT_SDA_CONSOLE_H


#include "../Service/UserService/UserService.h"

class Console {
private:
    UserService userService;
public:
    Console(UserService &userService);

    void showMenu();

    void uiAddUser();
    void uiCheckUser();
    void uiUpdateUser();
    void uiDeleteUser();

    void runMenu();
};


#endif //PROIECT_SDA_CONSOLE_H
