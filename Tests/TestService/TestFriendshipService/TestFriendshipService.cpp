//
// Created by Tudor on 5/21/2022.
//

#include <string>
#include <fstream>
#include <cassert>
#include "TestFriendshipService.h"
#include "../../../Service/UserService/UserService.h"
#include "../../../Domain/Entities/Friendship/Friendship.h"
#include "../../../Service/FriendshipService/FriendshipService.h"

void TestFriendshipService::clearFile(std::string fileName) {
    std::ofstream file(fileName);
}

void TestFriendshipService::create() {
    clearFile("testFriendshipServiceUsers.csv");
    clearFile("testFriendshipServiceFriendships.csv");
    RepositoryCSV<User> userRepository("testFriendshipServiceUsers.csv");
    UserService userService(userRepository);
    RepositoryCSV<Friendship> friendshipRepository("testFriendshipServiceFriendships.csv");
    FriendshipService friendshipService(friendshipRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    friendshipService.create(u1, u2);
    friendshipService.create(u1, u3);
    friendshipService.create(u2, u3);
    assert(friendshipService.read()[0] == Friendship(1, u1, u2));
    assert(friendshipService.read()[1] == Friendship(2, u1, u3));
    assert(friendshipService.read()[2] == Friendship(3, u2, u3));
}

void TestFriendshipService::read() {
    clearFile("testFriendshipServiceUsers.csv");
    clearFile("testFriendshipServiceFriendships.csv");
    RepositoryCSV<User> userRepository("testFriendshipServiceUsers.csv");
    UserService userService(userRepository);
    RepositoryCSV<Friendship> friendshipRepository("testFriendshipServiceFriendships.csv");
    FriendshipService friendshipService(friendshipRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    friendshipService.create(u1, u2);
    friendshipService.create(u1, u3);
    friendshipService.create(u2, u3);
    assert(friendshipService.read()[0] == Friendship(1, u1, u2));
    assert(friendshipService.read()[1] == Friendship(2, u1, u3));
    assert(friendshipService.read()[2] == Friendship(3, u2, u3));
}

void TestFriendshipService::update() {
    clearFile("testFriendshipServiceUsers.csv");
    clearFile("testFriendshipServiceFriendships.csv");
    RepositoryCSV<User> userRepository("testFriendshipServiceUsers.csv");
    UserService userService(userRepository);
    RepositoryCSV<Friendship> friendshipRepository("testFriendshipServiceFriendships.csv");
    FriendshipService friendshipService(friendshipRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    friendshipService.create(u1, u2);
    friendshipService.create(u1, u3);
    friendshipService.create(u2, u3);
    friendshipService.del(Friendship(3, u2, u3));
    friendshipService.update(Friendship(2, u1, u3), Friendship(3, u2, u3));
    assert(friendshipService.read()[0] == Friendship(1, u1, u2));
    assert(friendshipService.read()[1] == Friendship(3, u2, u3));
}

void TestFriendshipService::del() {
    clearFile("testFriendshipServiceUsers.csv");
    clearFile("testFriendshipServiceFriendships.csv");
    RepositoryCSV<User> userRepository("testFriendshipServiceUsers.csv");
    UserService userService(userRepository);
    RepositoryCSV<Friendship> friendshipRepository("testFriendshipServiceFriendships.csv");
    FriendshipService friendshipService(friendshipRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    friendshipService.create(u1, u2);
    friendshipService.create(u1, u3);
    friendshipService.create(u2, u3);
    friendshipService.del(Friendship(1, u1, u2));
    friendshipService.del(Friendship(2, u1, u3));
    friendshipService.del(Friendship(3, u2, u3));
    assert(friendshipService.getNumberOfFriendships() == 0);
}

void TestFriendshipService::doesExistId() {
    clearFile("testFriendshipServiceUsers.csv");
    clearFile("testFriendshipServiceFriendships.csv");
    RepositoryCSV<User> userRepository("testFriendshipServiceUsers.csv");
    UserService userService(userRepository);
    RepositoryCSV<Friendship> friendshipRepository("testFriendshipServiceFriendships.csv");
    FriendshipService friendshipService(friendshipRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    friendshipService.create(u1, u2);
    friendshipService.create(u1, u3);
    friendshipService.create(u2, u3);
    assert(friendshipService.doesExistId(1) == true);
    assert(friendshipService.doesExistId(2) == true);
    assert(friendshipService.doesExistId(3) == true);
    assert(friendshipService.doesExistId(4) == false);
}

void TestFriendshipService::doesExistSecondUser() {
    clearFile("testFriendshipServiceUsers.csv");
    clearFile("testFriendshipServiceFriendships.csv");
    RepositoryCSV<User> userRepository("testFriendshipServiceUsers.csv");
    UserService userService(userRepository);
    RepositoryCSV<Friendship> friendshipRepository("testFriendshipServiceFriendships.csv");
    FriendshipService friendshipService(friendshipRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    friendshipService.create(u1, u2);
    friendshipService.create(u1, u3);
    friendshipService.create(u2, u3);
    assert(friendshipService.doesExistSecondUser(u1) == true);
    assert(friendshipService.doesExistSecondUser(u2) == true);
    assert(friendshipService.doesExistSecondUser(u3) == true);
}

void TestFriendshipService::getFriendshipByEmails() {
    clearFile("testFriendshipServiceUsers.csv");
    clearFile("testFriendshipServiceFriendships.csv");
    RepositoryCSV<User> userRepository("testFriendshipServiceUsers.csv");
    UserService userService(userRepository);
    RepositoryCSV<Friendship> friendshipRepository("testFriendshipServiceFriendships.csv");
    FriendshipService friendshipService(friendshipRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    friendshipService.create(u1, u2);
    friendshipService.create(u1, u3);
    friendshipService.create(u2, u3);
    assert(friendshipService.getFriendshipByEmails(u1.getEmail(), u2.getEmail()) == friendshipService.read()[0]);
    assert(friendshipService.getFriendshipByEmails(u1.getEmail(), u3.getEmail()) == friendshipService.read()[1]);
    assert(friendshipService.getFriendshipByEmails(u2.getEmail(), u3.getEmail()) == friendshipService.read()[2]);
}

void TestFriendshipService::getUserFriendList() {
    clearFile("testFriendshipServiceUsers.csv");
    clearFile("testFriendshipServiceFriendships.csv");
    RepositoryCSV<User> userRepository("testFriendshipServiceUsers.csv");
    UserService userService(userRepository);
    RepositoryCSV<Friendship> friendshipRepository("testFriendshipServiceFriendships.csv");
    FriendshipService friendshipService(friendshipRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    friendshipService.create(u1, u2);
    friendshipService.create(u1, u3);
    friendshipService.create(u2, u3);
    assert(friendshipService.getUserFriendList(u1).size() == 2);
    assert(friendshipService.getUserFriendList(u1)[0] == u2);
    assert(friendshipService.getUserFriendList(u1)[1] == u3);
}

void TestFriendshipService::all() {
    create();
    read();
    update();
    del();
    doesExistId();
    doesExistSecondUser();
    getFriendshipByEmails();
    getUserFriendList();
}
