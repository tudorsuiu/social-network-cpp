//
// Created by Tudor on 5/11/2022.
//

#include <cassert>
#include <iostream>
#include "TestFriendship.h"
#include "../../../Domain/Friendship/Friendship.h"

void TestFriendship::constructor() {
    Friendship friendship;
    User user;
    assert(friendship.getId() == 0);
    assert(friendship.getFirstUser() == user);
    assert(friendship.getSecondUser() == user);
    assert(friendship.getStatus().empty() == true);
}

void TestFriendship::copyConstructor() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second, "pending");
    Friendship copyFriendship = friendship;
    assert(copyFriendship.getId() == 1);
    assert(copyFriendship.getFirstUser() == first);
    assert(copyFriendship.getSecondUser() == second);
    assert(copyFriendship.getStatus() == "pending");
}

void TestFriendship::lineConstructor() {
    Friendship friendship("1,1,First,Last,19,firstlast@gmail.com,cartof4,40753123456,2,Last,First,20,lastfirst@gmail.com,cartof4,40753123456,pending", ',');
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 20, "lastfirst@gmail.com", "cartof4", "40753123456");
    assert(friendship.getId() == 1);
    assert(friendship.getFirstUser() == first);
    assert(friendship.getSecondUser() == second);
    assert(friendship.getStatus() == "pending");
}

void TestFriendship::parametersConstructor() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second, "pending");
    assert(friendship.getId() == 1);
    assert(friendship.getFirstUser() == first);
    assert(friendship.getSecondUser() == second);
    assert(friendship.getStatus() == "pending");
}

void TestFriendship::getId() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second, "pending");
    assert(friendship.getId() == 1);
}

void TestFriendship::setId() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second, "pending");
    friendship.setId(2);
    assert(friendship.getId() == 2);
}

void TestFriendship::getFirstUser() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second, "pending");
    assert(friendship.getFirstUser() == first);
}

void TestFriendship::setFirstUser() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second, "pending");
    User newUser(3, "New", "New", 18, "newnew@gmail.com", "cartof4", "40753123456");
    friendship.setFirstUser(newUser);
    assert(friendship.getFirstUser() == newUser);
}

void TestFriendship::getSecondUser() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second, "pending");
    User newUser(3, "New", "New", 18, "newnew@gmail.com", "cartof4", "40753123456");
    friendship.setSecondUser(newUser);
    assert(friendship.getSecondUser() == newUser);
}

void TestFriendship::getStatus() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second, "pending");
    assert(friendship.getStatus() == "pending");
}

void TestFriendship::setStatus() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second, "pending");
    friendship.setStatus("rejected");
    assert(friendship.getStatus() == "rejected");
}

void TestFriendship::all() {
    constructor();
    copyConstructor();
    lineConstructor();
    parametersConstructor();
    getId();
    setId();
    getFirstUser();
    setFirstUser();
    getSecondUser();
    getStatus();
    setStatus();
}
