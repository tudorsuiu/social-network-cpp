//
// Created by Tudor on 5/5/2022.
//

#include "TestAll.h"
#include "../TestDomain/TestUser/TestUser.h"
#include "../TestRepository/TestUserRepository/TestUserRepository.h"
#include "../TestService/TestUserService/TestUserService.h"
#include "../TestDomain/TestArray/TestArray.h"
#include "../TestDomain/TestFriendship/TestFriendship.h"
#include "../TestDomain/TestMessage/TestMessage.h"
#include "../TestDomain/TestEvent/TestEvent.h"

void TestAll::run() {
    TestUser testUser;
    testUser.all();

    TestUserRepository testUserRepository;
    testUserRepository.all();

    TestUserService testUserService;
    testUserService.all();

    TestArray testArray;
    testArray.all();

    TestFriendship testFriendship;
    testFriendship.all();

    TestMessage testMessage;
    testMessage.all();

    TestEvent testEvent;
    testEvent.all();
}
