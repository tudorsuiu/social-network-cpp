//
// Created by Tudor on 5/4/2022.
//

#ifndef PROIECT_SDA_CONSOLE_H
#define PROIECT_SDA_CONSOLE_H


#include "../../Service/UserService/UserService.h"
#include "../../Service/MessageService/MessageService.h"
#include "../../Service/EventService/EventService.h"
#include "../../Service/FriendshipService/FriendshipService.h"
#include "../../Domain/Entities/Network/Network.h"

class Console {
private:
    Network network;
public:
    Console(Network &network);

    void uiAddUser();
    void uiShowUsers();
    void uiUpdateUser();
    void uiDeleteUser();
    void uiAddEvent();
    void uiShowEvents();
    void uiUpdateEvent();
    void uiDeleteEvent();
    void uiAddFriendship();
    void uiShowFriendships();
    void uiUpdateFriendship();
    void uiDeleteFriendship();
    void uiAddMessage();
    void uiShowMessages();
    void uiUpdateMessage();
    void uiDeleteMessage();

    void showMenu();

    void showUserMenu();
    void showFriendshipMenu();
    void showEventMenu();
    void showMessageMenu();
    void runAdminMenu();

    void showLoggedUserMenu(User loggedUser);
    void runUserMenu(User loggedUser);

    void showFirstMenu();
    void runLogInPage();

    void showRunMenu();
    void run();
};


#endif //PROIECT_SDA_CONSOLE_H
