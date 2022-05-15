//
// Created by Tudor on 5/4/2022.
//

#ifndef PROIECT_SDA_CONSOLE_H
#define PROIECT_SDA_CONSOLE_H


#include "../../Service/UserService/UserService.h"
#include "../../Service/MessageService/MessageService.h"
#include "../../Service/EventService/EventService.h"
#include "../../Service/FriendshipService/FriendshipService.h"

class Console {
private:
    UserService userService;
    MessageService messageService;
    EventService eventService;
    FriendshipService friendshipService;
public:
    Console(UserService &userService, MessageService &messageService, EventService &eventService, FriendshipService &friendshipService);

    void showFirstMenu();

    void uiLogIn();
    void uiRegister();
    void showLoggedUserMenu();
    void runLogInPage();

    void showMenu();

    void showUserMenu();
    void uiAddUser();
    void uiCheckUser();
    void uiUpdateUser();
    void uiDeleteUser();

    void showFriendshipMenu();
    void uiAddFriendship();
    void uiCheckFriendship();
    void uiUpdateFriendship();
    void uiDeleteFriendship();

    void showEventMenu();
    void uiAddEvent();
    void uiCheckEvent();
    void uiUpdateEvent();
    void uiDeleteEvent();

    void showMessageMenu();
    void uiAddMessage();
    void uiCheckMessage();
    void uiUpdateMessage();
    void uiDeleteMessage();

    void runMenu();
};


#endif //PROIECT_SDA_CONSOLE_H
