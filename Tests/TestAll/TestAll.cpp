//
// Created by Tudor on 5/5/2022.
//

#include "TestAll.h"
#include "../TestDomain/TestUser/TestUser.h"
#include "../TestRepository/TestUserRepository/TestUserRepository.h"
#include "../TestService/TestUserService/TestUserService.h"
#include "../TestDomain/TestList/TestList.h"
#include "../TestDomain/TestFriendship/TestFriendship.h"
#include "../TestDomain/TestMessage/TestMessage.h"
#include "../TestDomain/TestEvent/TestEvent.h"
#include "../TestRepository/TestMessageRepository/TestMessageRepository.h"
#include "../TestRepository/TestEventRepository/TestEventRepository.h"
#include "../TestRepository/TestFriendshipRepository/TestFriendshipRepository.h"
#include "../TestDomain/TestBST/TestBST.h"
#include "../TestService/TestMessageSerivce/TestMessageService.h"
#include "../TestService/TestFriendshipService/TestFriendshipService.h"
#include "../TestService/TestEventService/TestEventService.h"

void TestAll::run() {
    TestList testList;
    testList.all();

    TestBST testBST;
    testBST.all();

    TestUser testUser;
    testUser.all();

    TestUserRepository testUserRepository;
    testUserRepository.all();

    TestUserService testUserService;
    testUserService.all();

    TestFriendship testFriendship;
    testFriendship.all();

    TestFriendshipRepository testFriendshipRepository;
    testFriendshipRepository.all();

    TestFriendshipService testFriendshipService;
    testFriendshipService.all();

    TestMessage testMessage;
    testMessage.all();

    TestMessageRepository testMessageRepository;
    testMessageRepository.all();

    TestMessageService testMessageService;
    testMessageService.all();

    TestEvent testEvent;
    testEvent.all();

    TestEventRepository testEventRepository;
    testEventRepository.all();

    TestEventService testEventService;
    testEventService.all();

}
