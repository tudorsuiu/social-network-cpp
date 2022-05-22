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
    std::cout << "PROFILE: " << loggedUser.getFirstName() << " "
              << loggedUser.getLastName() << "." << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Account info." << '\n';
    std::cout << "2. Add friend." << '\n';
    std::cout << "3. Delete friend." << '\n';
    std::cout << "4. Check friends list." << '\n';
    std::cout << "5. Send message." << '\n';
    std::cout << "6. Delete message." << '\n';
    std::cout << "7. Check the conversation with an user." << '\n';
    std::cout << "8. Create event." << '\n';
    std::cout << "9. Show created events." << '\n';
    std::cout << "0. Delete event." << '\n';
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
    std::string firstName;
    std::cout << "Enter first name:";
    std::cin >> firstName;

    std::string lastName;
    std::cout << "Enter last name:";
    std::cin >> lastName;

    unsigned int age;
    std::cout << "Enter age:";
    std::cin >> age;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        throw MyException("Age must be an unsigned int.");
    }

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

void Console::uiShowUsers() {
    for (int i = 0; i < network.checkUser().size(); i++) {
        std::cout << network.checkUser()[i];
    }
}

void Console::uiUpdateUser() {
    std::string oldEmail;
    std::cout << "Enter old user email:";
    std::cin >> oldEmail;

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

    network.updateUser(oldEmail, firstName, lastName, age, email, password,
                       phoneNumber);
}

void Console::uiDeleteUser() {

    std::string email;
    std::cout << "Delete user with this email:";
    std::cin >> email;

    network.deleteUser(email);

}

void Console::uiAddEvent() {
    std::string creatorEmail;
    std::cout << "Enter creator email:";
    std::cin >> creatorEmail;

    std::string name;
    std::cout << "Enter event name:";
    std::cin.get();
    std::getline(std::cin, name);

    std::string date;
    std::cout << "Enter event date:";
    std::cin >> date;

    std::string description;
    std::cout << "Enter event description:";
    std::cin.get();
    std::getline(std::cin, description);

    network.addEvent(creatorEmail, name, date, description);
}

void Console::uiShowEvents() {
    network.checkEvent().show();
}

void Console::uiUpdateEvent() {
    unsigned int id;
    std::cout << "Enter old event id:" << '\n';
    std::cin >> id;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        throw MyException("Event ID must an unsigned int.");
    }

    std::string newCreatorEmail;
    std::cout << "Enter new creator email:";
    std::cin >> newCreatorEmail;

    std::string newName;
    std::cout << "Enter new event name:";
    std::cin.get();
    std::getline(std::cin, newName);

    std::string newDate;
    std::cout << "Enter new event date:";
    std::cin >> newDate;

    std::string newDescription;
    std::cout << "Enter new event description:";
    std::cin.get();
    std::getline(std::cin, newDescription);

    network.updateEvent(id, newCreatorEmail, newName, newDate, newDescription);
}

void Console::uiDeleteEvent() {
    unsigned int id;
    std::cout << "Enter event id:";
    std::cin >> id;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        throw MyException("Id must be an unsigned int.");
    }

    network.deleteEvent(id);
}

void Console::uiAddFriendship() {
    std::string firstUserEmail;
    std::cout << "Enter first user email:";
    std::cin >> firstUserEmail;

    std::string secondUserEmail;
    std::cout << "Enter second user email:";
    std::cin >> secondUserEmail;

    network.addFriendship(firstUserEmail, secondUserEmail);
}

void Console::uiShowFriendships() {
    for (int i = 0; i < network.checkFriendship().size(); i++) {
        std::cout << network.checkFriendship()[i];
    }
}

void Console::uiUpdateFriendship() {
    unsigned int id;
    std::cout << "Enter old friendship id:";
    std::cin >> id;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        throw MyException("Id must be an unsigned int.");
    }


    std::string firstUserEmail;
    std::cout << "Enter new first user email:";
    std::cin >> firstUserEmail;

    std::string secondUserEmail;
    std::cout << "Enter new second user email:";
    std::cin >> secondUserEmail;

    network.updateFriendship(id, firstUserEmail, secondUserEmail);
}

void Console::uiDeleteFriendship() {
    std::string firstUserEmail;
    std::cout << "Enter first user email:";
    std::cin >> firstUserEmail;

    std::string secondUserEmail;
    std::cout << "Enter second user email:";
    std::cin >> secondUserEmail;

    network.deleteFriendship(firstUserEmail, secondUserEmail);
}

void Console::uiAddMessage() {
    std::string senderEmail;
    std::cout << "Enter sender email:";
    std::cin >> senderEmail;

    std::string receiverEmail;
    std::cout << "Enter receiver email:";
    std::cin >> receiverEmail;

    std::string data;
    std::cout << "Enter message:";
    std::cin.get();
    std::getline(std::cin, data);

    network.addMessage(senderEmail, receiverEmail, data);
}

void Console::uiShowMessages() {
    for (int i = 0; i < network.checkMessage().size(); i++) {
        std::cout << network.checkMessage()[i];
    }
}

void Console::uiUpdateMessage() {
    unsigned int id;
    std::cout << "Enter old message id:";
    std::cin >> id;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        throw MyException("Id must be an unsigned int.");
    }

    std::string newSenderEmail;
    std::cout << "Enter sender email:";
    std::cin >> newSenderEmail;

    std::string newReceiverEmail;
    std::cout << "Enter receiver email:";
    std::cin >> newReceiverEmail;

    std::string newData;
    std::cout << "Enter new message:";
    std::cin.get();
    std::getline(std::cin, newData);

    network.updateMessage(id, newSenderEmail, newReceiverEmail, newData);
}

void Console::uiDeleteMessage() {
    std::string senderEmail;
    std::cout << "Enter sender email:";
    std::cin >> senderEmail;

    std::string receiverEmail;
    std::cout << "Enter receiver email:";
    std::cin >> receiverEmail;

    std::string data;
    std::cout << "Enter message data:";
    std::cin.get();
    std::getline(std::cin, data);

    network.deleteMessage(senderEmail, receiverEmail, data);
}

void Console::uiLoggedUserAddFriend(User loggedUser) {
    std::string email;
    std::cout << "Insert user email:";
    std::cin >> email;
    network.addFriendship(loggedUser.getEmail(), email);
}

void Console::uiLoggedUserDeleteFriend(User loggedUser) {
    std::string userEmail;
    std::cout << "Delete friend by email:";
    std::cin >> userEmail;

    network.deleteFriendship(loggedUser.getEmail(), userEmail);
}

void Console::uiLoggedUserShowFriendList(User loggedUser) {
    List<User> friends = network.CheckFriends(loggedUser);
    for (int i = 0; i < friends.size(); i++) {
        std::cout << friends[i].getFirstName() << " "
                  << friends[i].getLastName() << '\n';
    }
}

void Console::uiLoggedUserSendMessage(User loggedUser) {
    std::string receiverEmail, data;
    std::cout << "Insert receiver email:";
    std::cin >> receiverEmail;

    std::cout << "Insert message:";
    std::cin.get();
    std::getline(std::cin, data);

    network.addMessage(loggedUser.getEmail(), receiverEmail,
                       data);
}

void Console::uiLoggedUserDeleteMessage(User loggedUser) {
    std::string receiverEmail, data;
    std::cout << "Insert receiver email:";
    std::cin >> receiverEmail;


    std::cout << "Insert message:";
    std::cin.get();
    std::getline(std::cin, data);

    network.deleteMessage(loggedUser.getEmail(), receiverEmail,
                          data);
}

void Console::uiLoggedUserShowConversation(User loggedUser) {
    std::string userEmail;
    std::cout << "Insert user email:";
    std::cin >> userEmail;
    List<Message> conversation = network.getConversation(
            loggedUser, userEmail);
    for (int i = 0; i < conversation.size(); i++) {
        std::cout << conversation[i] << '\n';
    }
}

void Console::uiLoggedUserCreateEvent(User loggedUser) {
    std::string name, date, description;
    std::cout << "Event name:";
    std::cin.get();
    std::getline(std::cin, name);

    std::cout << "Event date:";
    std::cin >> date;

    std::cout << "Event description:";
    std::cin.get();
    std::getline(std::cin, description);

    network.addEvent(loggedUser.getEmail(), name, date,
                     description);
}

void Console::uiLoggedUserShowCreatedEvents(User loggedUser) {
    std::vector<Event> eventsCreatedByUser;
    eventsCreatedByUser = network.getEventsByCreator(loggedUser);
    for(int i = 0; i < eventsCreatedByUser.size(); i++) {
        std::cout << eventsCreatedByUser[i] << '\n';
    }
}

void Console::uiLoggedUserDeleteEvent(User loggedUser) {
    unsigned int id;
    std::cout << "Event id:";
    std::cin >> id;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        throw MyException("ID must be an unsigned int.");
    }
    if(network.checkEvent(id).getCreator() == loggedUser) {
        network.deleteEvent(id);
    }
    else {
        throw MyException("This event was not created by you. You can't delete it.");
    }
}

void Console::runUserMenu(User loggedUser) {
    char loggedUserOption;
    do {
        showLoggedUserMenu(loggedUser);
        std::cin >> loggedUserOption;
        std::cout << '\n';
        switch (loggedUserOption) {
            case '1': {
                try {
                    std::cout << loggedUser << '\n';
                }
                catch (std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '2': {
                try {
                    uiLoggedUserAddFriend(loggedUser);
                }
                catch (std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '3': {
                try {
                    uiLoggedUserDeleteFriend(loggedUser);
                }
                catch (std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '4': {
                try {
                    uiLoggedUserShowFriendList(loggedUser);
                }
                catch (std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '5': {
                try {
                    uiLoggedUserSendMessage(loggedUser);
                }
                catch (std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '6': {
                try {
                    uiLoggedUserDeleteMessage(loggedUser);
                }
                catch (std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '7': {
                try {
                    uiLoggedUserShowConversation(loggedUser);
                }
                catch (std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '8': {
                try {
                    uiLoggedUserCreateEvent(loggedUser);
                }
                catch (std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '9': {
                try {
                    uiLoggedUserShowCreatedEvents(loggedUser);
                }
                catch (std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '0': {
                try {
                    uiLoggedUserDeleteEvent(loggedUser);
                }
                catch (std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case 'x': {
                break;
            }
            default: {
                std::cout << "Invalid option! Please try again!" << '\n';
            }
        }
    } while (loggedUserOption != 'x');
}

void Console::runLogInPage() {
    char firstMenuOption;
    do {
        showFirstMenu();
        std::cin >> firstMenuOption;
        std::cout << '\n';
        switch (firstMenuOption) {
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
                catch (std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '2': {
                try {
                    uiAddUser();
                }
                catch (std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case 'x': {
                break;
            }
            default: {
                std::cout << "Invalid option! Please try again!" << '\n';
            }
        }
    } while (firstMenuOption != 'x');
}

void Console::runAdminMenu() {
    char option;
    do {
        showMenu();
        std::cin >> option;
        std::cout << '\n';
        switch (option) {
            case '1': {
                char userOption;
                do {
                    showUserMenu();
                    std::cin >> userOption;
                    std::cout << '\n';
                    switch (userOption) {
                        case '1': {
                            try {
                                uiAddUser();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case '2': {
                            try {
                                uiShowUsers();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case '3': {
                            try {
                                uiUpdateUser();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case '4': {
                            try {
                                uiDeleteUser();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case 'x': {
                            break;
                        }
                        default: {
                            std::cout << "Invalid option! Please try again!"
                                      << '\n';
                        }
                    }
                } while (userOption != 'x');
                break;
            }
            case '2': {
                char messageOption;
                do {
                    showMessageMenu();
                    std::cin >> messageOption;
                    std::cout << '\n';
                    switch (messageOption) {
                        case '1': {
                            try {
                                uiAddMessage();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case '2': {
                            try {
                                uiShowMessages();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case '3': {
                            try {
                                uiUpdateMessage();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case '4': {
                            try {
                                uiDeleteMessage();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case 'x': {
                            break;
                        }
                        default: {
                            std::cout << "Invalid option! Please try again!"
                                      << '\n';
                        }
                    }
                } while (messageOption != 'x');
                break;
            }
            case '3': {
                char eventOption;
                do {
                    showEventMenu();
                    std::cin >> eventOption;
                    std::cout << '\n';
                    switch (eventOption) {
                        case '1': {
                            try {
                                uiAddEvent();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case '2': {
                            try {
                                uiShowEvents();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case '3': {
                            try {
                                uiUpdateEvent();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case '4': {
                            try {
                                uiDeleteEvent();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case 'x': {
                            break;
                        }
                        default: {
                            std::cout << "Invalid option! Please try again!"
                                      << '\n';
                        }
                    }
                } while (eventOption != 'x');
                break;
            }
            case '4': {
                char friendshipOption;
                do {
                    showFriendshipMenu();
                    std::cin >> friendshipOption;
                    std::cout << '\n';
                    switch (friendshipOption) {
                        case '1': {
                            try {
                                uiAddFriendship();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case '2': {
                            try {
                                uiShowFriendships();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case '3': {
                            try {
                                uiUpdateFriendship();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case '4': {
                            try {
                                uiDeleteFriendship();
                            }
                            catch (std::exception &e) {
                                std::cout << '\n' << e.what() << '\n';
                            }
                            break;
                        }
                        case 'x': {
                            break;
                        }
                        default: {
                            std::cout << "Invalid option! Please try again!"
                                      << '\n';
                        }
                    }
                } while (friendshipOption != 'x');
                break;
            }
            case 'x': {
                break;
            }
            default: {
                std::cout << "Invalid option! Please try again!" << '\n';
            }
        }
    } while (option != 'x');
}

void Console::run() {
    char option;
    do {
        showRunMenu();
        std::cin >> option;
        std::cout << '\n';
        switch (option) {
            case '1': {
                try {
                    runLogInPage();
                }
                catch(std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case '2': {
                try {
                    runAdminMenu();
                }
                catch(std::exception &e) {
                    std::cout << '\n' << e.what() << '\n';
                }
                break;
            }
            case 'x': {
                break;
            }
            default: {
                std::cout << "Invalid option! Please try again!" << '\n';
            }
        }
    } while (option != 'x');
}
