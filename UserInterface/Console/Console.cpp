//
// Created by Tudor on 5/4/2022.
//

#include "Console.h"

Console::Console(Network &network) : network(network) {}


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

void Console::showLoggedUserMenu(User loggedUser) {
    std::cout << '\n';
    std::cout << "PROFILE: " << loggedUser.getFirstName() << " " << loggedUser.getLastName() << "." << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Account info." << '\n';
    std::cout << "2. Add friend." << '\n';
    std::cout << "3. Check friends list." << '\n';
    std::cout << "4. Send message." << '\n';
    std::cout << "5. Check the conversation with an user." << '\n';
    std::cout << "6. Create event." << '\n';
    std::cout << "7. Participate to event." << '\n';
    std::cout << "8. Check events you are going to." << '\n';
    std::cout << "x. Sign out." << '\n';
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

void Console::showRunMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. User menu." << '\n';
    std::cout << "2. Admin menu." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::uiAddUser() {
    try {
        std::string firstName;
        std::cout << "Enter first name:";
        std::cin >> firstName;

        std::string lastName;
        std::cout << "Enter last name:";
        std::cin >> lastName;

        unsigned int age;
        std::cout << "Enter age:";
        std::cin >> age;

        std::string email;
        std::cout << "Enter email:";
        std::cin >> email;

        std::string password;
        std::cout << "Enter password:";
        std::cin >> password;

        std::string phoneNumber;
        std::cout << "Enter phone number:";
        std::cin >> phoneNumber;

        network.addUser(firstName, lastName, age, email, password, phoneNumber);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiShowUsers() {
    try {
        for(int i = 0; i < network.checkUser().size(); i++) {
            std::cout << network.checkUser()[i];
        }
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiUpdateUser() {
    try {
        std::string oldEmail;
        std::cout << "Enter old user email:";
        std::cin >> oldEmail;

        std::cout << "Enter new user details:" << '\n';

        std::string firstName;
        std::cout << "Enter first name:";
        std::cin >> firstName;

        std::string lastName;
        std::cout << "Enter last name:";
        std::cin >> lastName;

        unsigned int age;
        std::cout << "Enter age:";
        std::cin >> age;

        std::string email;
        std::cout << "Enter email:";
        std::cin >> email;

        std::string password;
        std::cout << "Enter password:";
        std::cin >> password;

        std::string phoneNumber;
        std::cout << "Enter phone number:";
        std::cin >> phoneNumber;

        network.updateUser(oldEmail, firstName, lastName, age, email, password, phoneNumber);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiDeleteUser() {
    try {
        std::string email;
        std::cout << "Delete user with this email:";
        std::cin >> email;

        network.deleteUser(email);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiAddEvent() {
    try {
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

        network.addEvent(creatorEmail, name, date, description);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiShowEvents() {
    try {
        network.checkEvent().show();
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiUpdateEvent() {
    try {
        unsigned int id;
        std::cout << "Enter old event id:" << '\n';
        std::cin >> id;

        std::cout << "Enter new event details:" << '\n';

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

        network.updateEvent(id, newCreatorEmail, newName, newDate, newDescription);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiDeleteEvent() {
    try {
        unsigned int id;
        std::cout << "Enter event id:";
        std::cin >> id;

        network.deleteEvent(id);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiAddFriendship() {
    try {
        std::string firstUserEmail;
        std::cout << "Enter first user email:";
        std::cin >> firstUserEmail;

        std::string secondUserEmail;
        std::cout << "Enter second user email:";
        std::cin >> secondUserEmail;

        network.addFriendship(firstUserEmail, secondUserEmail);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiShowFriendships() {
    try {
        for(int i = 0; i < network.checkFriendship().size(); i++) {
            std::cout << network.checkFriendship()[i];
        }
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiUpdateFriendship() {
    try {
        unsigned int id;
        std::cout << "Enter old friendship id:";
        std::cin >> id;

        std::cout << "Enter new friendship details:";

        std::string firstUserEmail;
        std::cout << "Enter new first user email:";
        std::cin >> firstUserEmail;

        std::string secondUserEmail;
        std::cout << "Enter new second user email:";
        std::cin >> secondUserEmail;

        network.updateFriendship(id, firstUserEmail, secondUserEmail);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiDeleteFriendship() {
    try {
        std::string firstUserEmail;
        std::cout << "Enter first user email:";
        std::cin >> firstUserEmail;

        std::string secondUserEmail;
        std::cout << "Enter secondu ser email:";
        std::cin >> secondUserEmail;

        network.deleteFriendship(firstUserEmail, secondUserEmail);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiAddMessage() {
    try {
        std::string senderEmail;
        std::cout << "Enter sender email:";
        std::cin >> senderEmail;

        std::string receiverEmail;
        std::cout << "Enter receiver email:";
        std::cin >> receiverEmail;

        std::string data;
        std::cout << "Enter message:";
        std::cin >> data;

        network.addMessage(senderEmail, receiverEmail, data);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiShowMessages() {
    try {
        for(int i = 0; i < network.checkMessage().size(); i++) {
            std::cout << network.checkMessage()[i];
        }
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiUpdateMessage() {
    try {
        unsigned int id;
        std::cout << "Enter old message id:";
        std::cin >> id;

        std::cout << "Enter new message details:" << '\n';

        std::string newSenderEmail;
        std::cout << "Enter sender email:";
        std::cin >> newSenderEmail;

        std::string newReceiverEmail;
        std::cout << "Enter receiver email:";
        std::cin >> newReceiverEmail;

        std::string newData;
        std::cout << "Enter new message:";
        std::cin >> newData;

        network.updateMessage(id, newSenderEmail, newReceiverEmail, newData);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::uiDeleteMessage() {
    try {
        std::string senderEmail;
        std::cout << "Enter sender email:";
        std::cin >> senderEmail;

        std::string receiverEmail;
        std::cout << "Enter receiver email:";
        std::cin >>receiverEmail;

        std::string data;
        std::cout << "Enter message data:";
        std::cin >> data;

        network.deleteMessage(senderEmail, receiverEmail, data);
    }
    catch(std::exception &e) {
        std::cout << '\n' << e.what() << '\n';
    }
}

void Console::runUserMenu(User loggedUser) {
    char loggedUserOption;
    do {
        showLoggedUserMenu(loggedUser);
        std::cin >> loggedUserOption;
        std::cout << '\n';
        switch(loggedUserOption) {
            case '1': {
                try {
                    std::cout << loggedUser << '\n';
                }
                catch(std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '2': {
                try {
                    std::string email;
                    std::cout << "Insert user email:";
                    std::cin >> email;
                    network.addFriendship(loggedUser.getEmail(), email);
                }
                catch(std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '3': {
                try {
                    List<User> friends = network.CheckFriends(loggedUser);
                    for(int i = 0; i < friends.size(); i++) {
                        std::cout << friends[i].getFirstName() << " " << friends[i].getLastName() << '\n';
                    }
                }
                catch(std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '4': {
                try {
                    std::string receiverEmail, data;
                    std::cout << "Insert receiver email:";
                    std::cin >> receiverEmail;
                    std::cout << "Insert message:";
                    std::cin >> data;
                    network.addMessage(loggedUser.getEmail(), receiverEmail, data);
                }
                catch(std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '5': {
                try {
                    std::string userEmail;
                    std::cout << "Insert user email:";
                    std::cin >> userEmail;
                    List<Message> conversation = network.getConversation(loggedUser, userEmail);
                    for(int i = 0; i < conversation.size(); i++) {
                        std::cout << conversation[i] << '\n';
                    }
                }
                catch(std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '6': {
                try {
                    std::string name, date, description;
                    std::cout << "Event name:";
                    std::cin >> name;

                    std::cout << "Event date:";
                    std::cin >> date;

                    std::cout << "Event description:";
                    std::cin >> description;

                    network.addEvent(loggedUser.getEmail(), name, date, description);
                }
                catch(std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '7': {

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

void Console::runLogInPage() {
    char firstMenuOption;
    do {
        showFirstMenu();
        std::cin >> firstMenuOption;
        std::cout << '\n';
        switch(firstMenuOption) {
            case '1': {
                try {
                    User user;

                    std::string email;
                    std::cout << "Enter email:";
                    std::cin >> email;

                    std::string password;
                    std::cout << "Enter password:";
                    std::cin >> password;

                    user = network.logIn(email, password);
                    runUserMenu(user);
                }
                catch(std::exception &e) {
                        std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '2': {
                uiAddUser();
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

void Console::runAdminMenu() {
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
                            uiShowUsers();
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
                            uiShowMessages();
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
                            uiShowEvents();
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
                            uiShowFriendships();
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

void Console::run() {
    char option;
    do {
        showRunMenu();
        std::cin >> option;
        std::cout << '\n';
        switch(option) {
            case '1': {
                runLogInPage();
                break;
            }
            case '2': {
                runAdminMenu();
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
