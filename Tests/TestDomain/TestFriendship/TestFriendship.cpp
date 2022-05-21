//
// Created by Tudor on 5/11/2022.
//

#include <cassert>
#include <iostream>
#include "TestFriendship.h"
#include "../../../Domain/Entities/Friendship/Friendship.h"

void TestFriendship::constructor() {
    Friendship friendship;
    User user;
    assert(friendship.getId() == 0);
    assert(friendship.getFirstUser() == user);
    assert(friendship.getSecondUser() == user);
}

void TestFriendship::copyConstructor() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second);
    Friendship copyFriendship = friendship;
    assert(copyFriendship.getId() == 1);
    assert(copyFriendship.getFirstUser() == first);
    assert(copyFriendship.getSecondUser() == second);
}

void TestFriendship::lineConstructor() {
    Friendship friendship("1,1,First,Last,19,firstlast@gmail.com,cartof4,40753123456,2,Last,First,20,lastfirst@gmail.com,cartof4,40753123456", ',');
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 20, "lastfirst@gmail.com", "cartof4", "40753123456");
    assert(friendship.getId() == 1);
    assert(friendship.getFirstUser() == first);
    assert(friendship.getSecondUser() == second);
}

void TestFriendship::parametersConstructor() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second);
    assert(friendship.getId() == 1);
    assert(friendship.getFirstUser() == first);
    assert(friendship.getSecondUser() == second);
}

void TestFriendship::getId() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second);
    assert(friendship.getId() == 1);
}

void TestFriendship::setId() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second);
    friendship.setId(2);
    assert(friendship.getId() == 2);
}

void TestFriendship::getFirstUser() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second);
    assert(friendship.getFirstUser() == first);
}

void TestFriendship::setFirstUser() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second);
    User newUser(3, "New", "New", 18, "newnew@gmail.com", "cartof4", "40753123456");
    friendship.setFirstUser(newUser);
    assert(friendship.getFirstUser() == newUser);
}

void TestFriendship::getSecondUser() {
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123456");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123456");
    Friendship friendship(1,first, second);
    User newUser(3, "New", "New", 18, "newnew@gmail.com", "cartof4", "40753123456");
    friendship.setSecondUser(newUser);
    assert(friendship.getSecondUser() == newUser);
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
}
