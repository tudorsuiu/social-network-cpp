//
// Created by Tudor on 5/17/2022.
//

#ifndef USERREPOSITORYCSV_H_NETWORK_H
#define USERREPOSITORYCSV_H_NETWORK_H


#include "../../../Service/UserService/UserService.h"
#include "../../../Service/FriendshipService/FriendshipService.h"
#include "../../../Service/MessageService/MessageService.h"
#include "../../../Service/EventService/EventService.h"

class Network {
private:
    UserService userService;
    FriendshipService friendshipService;
    MessageService messageService;
    EventService eventService;
public:
    Network(UserService &userService, FriendshipService &friendshipService, MessageService &messageService, EventService &eventService);

    void addUser(std::string firstName, std::string lastName, unsigned int age, std::string email, std::string password, std::string phoneNumber);
    List<User> checkUser();
    User checkUser(unsigned int id);
    void updateUser(std::string oldEmail, std::string firstName, std::string lastName, unsigned int age, std::string email, std::string password, std::string phoneNumber);
    void deleteUser(std::string email);
    void addFriendship(std::string firstUserEmail, std::string secondUserEmail);
    List<Friendship> checkFriendship();
    Friendship checkFriendship(unsigned int id);
    void updateFriendship(unsigned int id, std::string firstUserEmail, std::string secondUserEmail);
    void deleteFriendship(std::string firstUserEmail, std::string secondUserEmail);
    void addEvent(std::string creatorEmail, std::string name, std::string date, std::string description);
    BST<Event> checkEvent();
    Event checkEvent(unsigned int id);
    void updateEvent(unsigned int id, std::string newCreatorEmail, std::string newName, std::string newDate, std::string newDescription);
    void deleteEvent(unsigned int id);
    void addMessage(std::string senderEmail, std::string receiverEmail, std::string data);
    List<Message> checkMessage();
    Message checkMessage(unsigned int id);
    void updateMessage(unsigned int id, std::string newSenderEmail, std::string newReceiverEmail, std::string newData);
    void deleteMessage(unsigned int id);

    std::vector<Event> getEventsByCreator(User user);

    User logIn(std::string email, std::string password);

    List<User> CheckFriends(User loggedUser);
    void SendMesssage(User loggedUser, std::string receiverEmail, std::string data);
    List<Message> getConversation(User loggedUser, std::string userEmail);
};


#endif //USERREPOSITORYCSV_H_NETWORK_H
