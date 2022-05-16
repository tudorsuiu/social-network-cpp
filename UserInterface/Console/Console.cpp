//
// Created by Tudor on 5/4/2022.
//

#include "Console.h"

Console::Console(UserService &userService, MessageService &messageService,
                 EventService &eventService,
                 FriendshipService &friendshipService) : userService(userService),
                                                         messageService(messageService),
                                                         eventService(eventService),
                                                         friendshipService(friendshipService) {}

void Console::showMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. User menu." << '\n';
    std::cout << "2. Message menu." << '\n';
    std::cout << "3. Event menu." << '\n';
    std::cout << "4. Friendship menu." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::showFirstMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Log in." << '\n';
    std::cout << "2. Register." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::showLoggedUserMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Add friend." << '\n';
    std::cout << "2. Check friends list." << '\n';
    std::cout << "3. Check pending friend requests." << '\n';
    std::cout << "4. Send message." << '\n';
    std::cout << "5. Check sent messages." << '\n';
    std::cout << "6. Check received messages." << '\n';
    std::cout << "7. Create event." << '\n';
    std::cout << "8. Participate to event." << '\n';
    std::cout << "9. Check events you are going to." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::showUserMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Add users." << '\n';
    std::cout << "2. Check users." << '\n';
    std::cout << "3. Update users." << '\n';
    std::cout << "4. Delete users." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::showFriendshipMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Add friendship relation." << '\n';
    std::cout << "2. Check friendship relations." << '\n';
    std::cout << "3. Update friendship relations." << '\n';
    std::cout << "4. Delete friendship relations." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::showEventMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Add events." << '\n';
    std::cout << "2. Check events." << '\n';
    std::cout << "3. Update events." << '\n';
    std::cout << "4. Delete events." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::showMessageMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Add messages." << '\n';
    std::cout << "2. Check messages." << '\n';
    std::cout << "3. Update messages." << '\n';
    std::cout << "4. Delete messages." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::uiLogIn() {
    try {
        User loggedUser;

        std::string userEmail;
        std::cout << "Please insert your mail:";
        std::cin >> userEmail;

        std::string userPassword;
        std::cout << "Please insert your password:";
        std::cin >> userPassword;

        if(userService.getUserByEmailAndPassword(userEmail, userPassword) == User(0, "Default", "Default", 19, "default@default.com", "default", "40712345678")) {
            std::cout << "Log in credentials are not valid." << '\n';
        }
        else {
            char loggedUserOption;
            loggedUser = userService.getUserByEmailAndPassword(userEmail, userPassword);
            std::cout << "You are signed in." << '\n';
            do {
                showLoggedUserMenu();
                std::cin >> loggedUserOption;
                std::cout << '\n';
                switch(loggedUserOption) {
                    case '1': {
                        break;
                    }
                    case 'x': {
                        break;
                    }
                    default: {
                        std::cout << "Invalid option! Please try again!" << '\n';
                    }
                }
            }while(loggedUserOption != 'x');
        }
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiRegister() {
    try {
        User newUser;
        std::cin >> newUser;
        userService.create(newUser);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiAddUser() {
    try {
        User user;
        std::cin >> user;
        userService.create(user);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiCheckUser() {
    try {
        for (int i = 0; i < userService.read().size(); i++) {
            std::cout << userService.read()[i] << '\n';
        }
    }
    catch(std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Console::uiUpdateUser() {
    try {
        unsigned int id;
        std::cout << "Update user with this id:";
        std::cin >> id;
        User newUser;
        std::cin >> newUser;
        userService.update(id, newUser);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiDeleteUser() {
    try {
        unsigned int id;
        std::cout << "Delete user with this id:";
        std::cin >> id;
        userService.del(id);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiAddFriendship() {
    try {
        unsigned int id;
        std::cout << "Enter friendship id:";
        std::cin >> id;

        std::string firstUserEmail;
        std::cout << "Enter first user email:";
        std::cin >> firstUserEmail;

        std::string secondUserEmail;
        std::cout << "Enter second user email:";
        std::cin >> secondUserEmail;

        std::string status;
        std::cout << "Enter friendship status:";
        std::cin >> status;

        friendshipService.create(id, firstUserEmail, secondUserEmail, status);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiCheckFriendship() {
    try {
        for(int i = 0; i < friendshipService.read().size(); i++) {
            std::cout << friendshipService.read()[i] << '\n';
        }
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiUpdateFriendship() {
    try {
        unsigned int id;
        std::cout << "Enter friendship id:";
        std::cin >> id;

        std::string newFirstUserEmail;
        std::cout << "Enter new first user email:";
        std::cin >> newFirstUserEmail;

        std::string newSecondUserEmail;
        std::cout << "Enter new second user email:";
        std::cin >> newSecondUserEmail;

        std::string newStatus;
        std::cout << "Enter new friendship status:";
        std::cin >> newStatus;

        friendshipService.update(id, newFirstUserEmail, newSecondUserEmail, newStatus);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiDeleteFriendship() {
    try {
        unsigned int id;
        std::cout << "Delete friendship relation with this id:";
        std::cin >> id;
        friendshipService.del(id);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiAddEvent() {
    try {
        unsigned int id;
        std::cout << "Enter event id:";
        std::cin >> id;

        std::string creatorEmail;
        std::cout << "Enter creator email:";
        std::cin >> creatorEmail;

        std::string name;
        std::cout << "Enter event name:";
        std::cin >> name;

        std::string date;
        std::cout << "Enter event date:";
        std::cin >> date;

        std::string description;
        std::cout << "Enter event description:";
        std::cin >> description;

        eventService.create(id, creatorEmail, name, date, description);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiCheckEvent() {
    try {
        for(int i = 0; i < eventService.read().size(); i++) {
            std::cout << eventService.read()[i] << '\n';
        }
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiUpdateEvent() {
    try {
        unsigned int id;
        std::cout << "Enter event id:";
        std::cin >> id;

        std::string newCreatorEmail;
        std::cout << "Enter new creator email:";
        std::cin >> newCreatorEmail;

        std::string newName;
        std::cout << "Enter new event name:";
        std::cin >> newName;

        std::string newDate;
        std::cout << "Enter new event date:";
        std::cin >> newDate;

        std::string newDescription;
        std::cout << "Enter new event description:";
        std::cin >> newDescription;
        eventService.update(id, newCreatorEmail, newName, newDate, newDescription);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiDeleteEvent() {
    try {
        unsigned int id;
        std::cout << "Delete event with this id:";
        std::cin >> id;
        eventService.del(id);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiAddMessage() {
    try {
        unsigned int id;
        std::cout << "Enter message id:";
        std::cin >> id;

        std::string senderEmail;
        std::cout << "Enter sender email:";
        std::cin >> senderEmail;

        std::string receiverEmail;
        std::cout << "Enter receiver email:";
        std::cin >> receiverEmail;

        std::string data;
        std::cout << "Enter message:";
        std::cin >> data;

        messageService.create(id, senderEmail, receiverEmail, data);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiCheckMessage() {
    try {
        for(int i = 0; i < messageService.read().size(); i++) {
            std::cout << messageService.read()[i] << '\n';
        }
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiUpdateMessage() {
    try {
        unsigned int id;
        std::cout << "Enter message id:";
        std::cin >> id;

        std::string senderEmail;
        std::cout << "Enter new sender email:";
        std::cin >> senderEmail;

        std::string receiverEmail;
        std::cout << "Enter new receiver email:";
        std::cin >> receiverEmail;

        std::string data;
        std::cout << "Enter new message:";
        std::cin >> data;
        messageService.update(id, senderEmail, receiverEmail, data);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiDeleteMessage() {
    try {
        unsigned int id;
        std::cout << "Delete message with this id:";
        std::cin >> id;
        messageService.del(id);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::runLogInPage() {
    char firstMenuOption;
    do {
        showFirstMenu();
        std::cin >> firstMenuOption;
        std::cout << '\n';
        switch(firstMenuOption) {
            case '1': {
                uiLogIn();
                break;
            }
            case '2': {
                uiRegister();
                break;
            }
            case 'x': {
                break;
            }
            default: {
                std::cout << "Invalid option! Please try again!" << '\n';
            }
        }
    }while(firstMenuOption != 'x');
}

void Console::runMenu() {
    char option;
    do {
        showMenu();
        std::cin >> option;
        std::cout << '\n';
        switch(option) {
            case '1': {
                char userOption;
                do {
                    showUserMenu();
                    std::cin >> userOption;
                    std::cout << '\n';
                    switch(userOption) {
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
                }while(userOption != 'x');
                break;
            }
            case '2': {
                char messageOption;
                do {
                    showMessageMenu();
                    std::cin >> messageOption;
                    std::cout << '\n';
                    switch(messageOption) {
                        case '1': {
                            uiAddMessage();
                            break;
                        }
                        case '2': {
                            uiCheckMessage();
                            break;
                        }
                        case '3': {
                            uiUpdateMessage();
                            break;
                        }
                        case '4': {
                            uiDeleteMessage();
                            break;
                        }
                        case 'x': {
                            break;
                        }
                        default: {
                            std::cout << "Invalid option! Please try again!" << '\n';
                        }
                    }
                }while(messageOption != 'x');
                break;
            }
            case '3': {
                char eventOption;
                do {
                    showEventMenu();
                    std::cin >> eventOption;
                    std::cout << '\n';
                    switch(eventOption) {
                        case '1': {
                            uiAddEvent();
                            break;
                        }
                        case '2': {
                            uiCheckEvent();
                            break;
                        }
                        case '3': {
                            uiUpdateEvent();
                            break;
                        }
                        case '4': {
                            uiDeleteEvent();
                            break;
                        }
                        case 'x': {
                            break;
                        }
                        default: {
                            std::cout << "Invalid option! Please try again!" << '\n';
                        }
                    }
                }while(eventOption != 'x');
                break;
            }
            case '4': {
                char friendshipOption;
                do {
                    showFriendshipMenu();
                    std::cin >> friendshipOption;
                    std::cout << '\n';
                    switch(friendshipOption) {
                        case '1': {
                            uiAddFriendship();
                            break;
                        }
                        case '2': {
                            uiCheckFriendship();
                            break;
                        }
                        case '3': {
                            uiUpdateFriendship();
                            break;
                        }
                        case '4': {
                            uiDeleteFriendship();
                            break;
                        }
                        case 'x': {
                            break;
                        }
                        default: {
                            std::cout << "Invalid option! Please try again!" << '\n';
                        }
                    }
                }while(friendshipOption != 'x');
                break;
            }
            case 'x': {
                break;
            }
            default: {
                std::cout << "Invalid option! Please try again!" << '\n';
            }
        }
    }while(option != 'x');
}
