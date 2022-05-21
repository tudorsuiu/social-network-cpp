//
// Created by Tudor on 5/17/2022.
//

#include "Network.h"

Network::Network(UserService &userService,
                 FriendshipService &friendshipService,
                 MessageService &messageService, EventService &eventService) : userService(userService),
                                                                               friendshipService(friendshipService),
                                                                               messageService(messageService),
                                                                               eventService(eventService) {}

void Network::addUser(std::string firstName, std::string lastName, unsigned int age, std::string email, std::string password, std::string phoneNumber) {
    userService.create(firstName, lastName, age, email, password, phoneNumber);
}

List<User> Network::checkUser() {
    return userService.read();
}

User Network::checkUser(unsigned int id) {
    return userService.read(id);
}

void Network::updateUser(std::string oldEmail, std::string firstName, std::string lastName, unsigned int age, std::string email, std::string password, std::string phoneNumber) {
    User oldUser = userService.getUserByEmail(oldEmail);
    User newUser(oldUser.getId(), firstName, lastName, age, email, password, phoneNumber);
    userService.update(oldUser, newUser);
}

void Network::deleteUser(std::string email) {
    User user = userService.getUserByEmail(email);
    userService.del(user);
}

void Network::addFriendship(std::string firstUserEmail, std::string secondUserEmail) {
    User firstUser = userService.getUserByEmail(firstUserEmail);
    User secondUser = userService.getUserByEmail(secondUserEmail);
    friendshipService.create(firstUser, secondUser);
}

List<Friendship> Network::checkFriendship() {
    return friendshipService.read();
}

Friendship Network::checkFriendship(unsigned int id) {
    return friendshipService.read(id);
}

void Network::updateFriendship(unsigned int id, std::string firstUserEmail, std::string secondUserEmail) {
    User newFirstUser = userService.getUserByEmail(firstUserEmail);
    User newSecondUser = userService.getUserByEmail(secondUserEmail);
    Friendship oldFriendship = friendshipService.read(id);
    Friendship newFriendship(id, newFirstUser, newSecondUser);
    friendshipService.update(oldFriendship, newFriendship);
}

void Network::deleteFriendship(std::string firstUserEmail, std::string secondUserEmail) {
    Friendship friendship = friendshipService.getFriendshipByEmails(firstUserEmail, secondUserEmail);
    friendshipService.del(friendship);
}

void Network::addEvent(std::string creatorEmail, std::string name, std::string date, std::string description) {
    User creator = userService.getUserByEmail(creatorEmail);
    eventService.create(creator, name, date, description);
}

BST<Event> Network::checkEvent() {
    return eventService.read();
}

Event Network::checkEvent(unsigned int id) {
    return eventService.read(id);
}

void Network::updateEvent(unsigned int id, std::string newCreatorEmail, std::string newName, std::string newDate, std::string newDescription) {
    User newCreator = userService.getUserByEmail(newCreatorEmail);
    Event oldEvent = eventService.read(id);
    Event newEvent(id, newCreator, newName, newDate, newDescription);
    eventService.update(oldEvent, newEvent);
}

void Network::deleteEvent(unsigned int id) {
    Event event = eventService.read(id);
    eventService.del(event);
}

void Network::addMessage(std::string senderEmail, std::string receiverEmail, std::string data) {
    User sender = userService.getUserByEmail(senderEmail);
    User receiver = userService.getUserByEmail(receiverEmail);
    messageService.create(sender, receiver, data);
}

List<Message> Network::checkMessage() {
    return messageService.read();
}

Message Network::checkMessage(unsigned int id) {
    return messageService.read(id);
}

void Network::updateMessage(unsigned int id, std::string newSenderEmail, std::string newReceiverEmail, std::string newData) {
    User newSender = userService.getUserByEmail(newSenderEmail);
    User newReceiver = userService.getUserByEmail(newReceiverEmail);
    Message oldMessage = messageService.read(id);
    Message newMessage(id, newSender, newReceiver, newData);
    messageService.update(oldMessage, newMessage);
}

void Network::deleteMessage(std::string senderEmail, std::string receiverEmail, std::string data) {
    Message message = messageService.getMessageByEmailsAndData(senderEmail, receiverEmail, data);
    messageService.del(message);
}

User Network::logIn(std::string email, std::string password) {
    User loggedUser = userService.getUserByEmailAndPassword(email, password);
    if(loggedUser != User(0, "Default", "Default", 19, "default@default.com", "default", "40712345678")) {
        return loggedUser;
    }
    else {
        throw MyException("Wrong email or password.");
    }
}

List<User> Network::CheckFriends(User loggedUser) {
    List<User> friends = friendshipService.getUserFriendList(loggedUser);
    if(friends.size() != 0) {
        return friends;
    }
    else {
        throw MyException("Friend list is empty.");
    }
}

void Network::SendMesssage(User loggedUser, std::string receiverEmail, std::string data) {
    User receiver = userService.getUserByEmail(receiverEmail);
    messageService.create(loggedUser, receiver, data);
}

List<Message> Network::getConversation(User loggedUser, std::string userEmail) {
    User user = userService.getUserByEmail(userEmail);
    List<Message> result = messageService.getConversationWithUser(loggedUser, user);
    if(result.empty()) {
        throw MyException("A conversation between this two users doesn't exist.");
    }
    return result;
}
