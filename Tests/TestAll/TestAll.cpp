//
// Created by Tudor on 5/5/2022.
//

#include "TestAll.h"
#include "../TestDomain/TestUser/TestUser.h"
#include "../TestRepository/TestUserRepository/TestUserRepository.h"
#include "../TestService/TestUserService/TestUserService.h"

void TestAll::run() {
    TestUser testUser;
    testUser.all();

    TestUserRepository testUserRepository;
    testUserRepository.all();

    TestUserService testUserService;
    testUserService.all();
}
