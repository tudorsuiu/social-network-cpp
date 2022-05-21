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
    assert(friendshipService.read(1) == Friendship(1, u1, u2));
    assert(friendshipService.read(2) == Friendship(2, u1, u3));
    assert(friendshipService.read(3) == Friendship(3, u2, u3));
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
    assert(friendshipService.read(1) == Friendship(1, u1, u2));
    assert(friendshipService.read(2) == Friendship(2, u1, u3));
    assert(friendshipService.read(3) == Friendship(3, u2, u3));
}

void TestFriendshipService::update() {

}

void TestFriendshipService::del() {

}

void TestFriendshipService::doesExistId() {

}

void TestFriendshipService::doesExistSecondUser() {

}

void TestFriendshipService::getFriendshipByEmails() {

}

void TestFriendshipService::getUserFriendList() {

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
