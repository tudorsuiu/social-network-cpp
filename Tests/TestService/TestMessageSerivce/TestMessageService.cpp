//
// Created by Tudor on 5/20/2022.
//

#include <string>
#include <fstream>
#include <cassert>
#include "../../../Domain/Entities/Message/Message.h"
#include "../../../Domain/Entities/User/User.h"
#include "TestMessageService.h"
#include "../../../Repository/RepositoryCSV.h"
#include "../../../Service/UserService/UserService.h"
#include "../../../Service/MessageService/MessageService.h"

void TestMessageService::clearFile(std::string fileName) {
    std::ofstream file(fileName);
}

void TestMessageService::create() {
    clearFile("testMessageServiceMessages.csv");
    clearFile("testMessageServiceUsers.csv");
    RepositoryCSV<Message> messageRepository("testMessageServiceMessages.csv");
    RepositoryCSV<User> userRepository("testMessageServiceUsers.csv");
    UserService userService(userRepository);
    MessageService messageService(messageRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    messageService.create(u1, u2, "Salut");
    messageService.create(u2, u1, "Salut! Ce faci?");
    messageService.create(u1, u2, "Bine tu?");
    assert(messageService.read(1) == Message(1,u1, u2, "Salut"));
    assert(messageService.read(2) == Message(2, u2, u1, "Salut! Ce faci?"));
    assert(messageService.read(3) == Message(3,u1, u2, "Bine tu?"));
}

void TestMessageService::read() {
    clearFile("testMessageServiceMessages.csv");
    clearFile("testMessageServiceUsers.csv");
    RepositoryCSV<Message> messageRepository("testMessageServiceMessages.csv");
    RepositoryCSV<User> userRepository("testMessageServiceUsers.csv");
    UserService userService(userRepository);
    MessageService messageService(messageRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    messageService.create(u1, u2, "Salut");
    messageService.create(u2, u1, "Salut! Ce faci?");
    messageService.create(u1, u2, "Bine tu?");
    assert(messageService.read(1) == Message(1,u1, u2, "Salut"));
    assert(messageService.read(2) == Message(2, u2, u1, "Salut! Ce faci?"));
    assert(messageService.read(3) == Message(3,u1, u2, "Bine tu?"));
}

void TestMessageService::update() {
    clearFile("testMessageServiceMessages.csv");
    clearFile("testMessageServiceUsers.csv");
    RepositoryCSV<Message> messageRepository("testMessageServiceMessages.csv");
    RepositoryCSV<User> userRepository("testMessageServiceUsers.csv");
    UserService userService(userRepository);
    MessageService messageService(messageRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    messageService.create(u1, u2, "Salut");
    messageService.create(u2, u1, "Salut! Ce faci?");
    messageService.create(u1, u2, "Bine tu?");
    messageService.update(Message(2, u2, u1, "Salut! Ce faci?"), Message(3, u1, u2, "Bine tu?"));
    assert(messageService.read()[0] == Message(1,u1, u2, "Salut"));
    assert(messageService.read()[1] == Message(3,u1, u2, "Bine tu?"));
    assert(messageService.read()[2] == Message(3,u1, u2, "Bine tu?"));
}

void TestMessageService::del() {
    clearFile("testMessageServiceMessages.csv");
    clearFile("testMessageServiceUsers.csv");
    RepositoryCSV<Message> messageRepository("testMessageServiceMessages.csv");
    RepositoryCSV<User> userRepository("testMessageServiceUsers.csv");
    UserService userService(userRepository);
    MessageService messageService(messageRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    messageService.create(u1, u2, "Salut");
    messageService.create(u2, u1, "Salut! Ce faci?");
    messageService.create(u1, u2, "Bine tu?");
    assert(messageService.read(1) == Message(1,u1, u2, "Salut"));
    assert(messageService.read(2) == Message(2, u2, u1, "Salut! Ce faci?"));
    assert(messageService.read(3) == Message(3,u1, u2, "Bine tu?"));
    messageService.del(Message(2,u2,u1,"Salut! Ce faci?"));
    assert(messageService.read().size() == 2);
}

void TestMessageService::doesExistId() {
    clearFile("testMessageServiceMessages.csv");
    clearFile("testMessageServiceUsers.csv");
    RepositoryCSV<Message> messageRepository("testMessageServiceMessages.csv");
    RepositoryCSV<User> userRepository("testMessageServiceUsers.csv");
    UserService userService(userRepository);
    MessageService messageService(messageRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    messageService.create(u1, u2, "Salut");
    messageService.create(u2, u1, "Salut! Ce faci?");
    messageService.create(u1, u2, "Bine tu?");
    assert(messageService.read(1) == Message(1,u1, u2, "Salut"));
    assert(messageService.read(2) == Message(2, u2, u1, "Salut! Ce faci?"));
    assert(messageService.read(3) == Message(3,u1, u2, "Bine tu?"));
    assert(messageService.doesExistId(1) == true);
    assert(messageService.doesExistId(2) == true);
    assert(messageService.doesExistId(3) == true);
    assert(messageService.doesExistId(4) == false);
}

void TestMessageService::getMessageByEmailsAndData() {
    clearFile("testMessageServiceMessages.csv");
    clearFile("testMessageServiceUsers.csv");
    RepositoryCSV<Message> messageRepository("testMessageServiceMessages.csv");
    RepositoryCSV<User> userRepository("testMessageServiceUsers.csv");
    UserService userService(userRepository);
    MessageService messageService(messageRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    messageService.create(u1, u2, "Salut");
    messageService.create(u2, u1, "Salut! Ce faci?");
    messageService.create(u1, u2, "Bine tu?");
    assert(messageService.getMessageByEmailsAndData("firstname.lastname1@domain.com","firstname.lastname2@domain.com","Salut") == messageService.read(1));
}

void TestMessageService::getConversationWithUser() {
    clearFile("testMessageServiceMessages.csv");
    clearFile("testMessageServiceUsers.csv");
    RepositoryCSV<Message> messageRepository("testMessageServiceMessages.csv");
    RepositoryCSV<User> userRepository("testMessageServiceUsers.csv");
    UserService userService(userRepository);
    MessageService messageService(messageRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    messageService.create(u1, u2, "Salut");
    messageService.create(u2, u1, "Salut! Ce faci?");
    messageService.create(u1, u2, "Bine tu?");
    List<Message> result = messageService.getConversationWithUser(u1, u2);
    assert(result.size() == 3);
}

void TestMessageService::all() {
    create();
    read();
    update();
    del();
    doesExistId();
    getMessageByEmailsAndData();
    getConversationWithUser();
}
