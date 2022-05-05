//
// Created by Tudor on 5/5/2022.
//

#include "TestUserService.h"
#include "../../../Repository/UserRepository/UserRepositoryCSV.h"
#include "../../../Service/UserService/UserService.h"
#include <fstream>
#include <cassert>

void TestUserService::clearFile(std::string fileName) {
    std::ofstream file(fileName);
}

void TestUserService::createUser() {
    clearFile("testService.csv");
    UserRepositoryCSV repository("testService.csv");
    UserService service(repository);
    User u1(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    service.create(u1);
    service.create(u2);
    service.create(u3);
    assert(service.read(1) == u1);
    assert(service.read(2) == u2);
    assert(service.read(3) == u3);
}

void TestUserService::readUser() {
    clearFile("testService.csv");
    UserRepositoryCSV repository("testService.csv");
    UserService service(repository);
    User u1(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    service.create(u1);
    service.create(u2);
    service.create(u3);
    assert(service.read().size() == 3);
    assert(service.read(1) == u1);
    assert(service.read(2) == u2);
    assert(service.read(3) == u3);
}

void TestUserService::updateUser() {
    clearFile("testService.csv");
    UserRepositoryCSV repository("testService.csv");
    UserService service(repository);
    User u1(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u4(4, "First name", "Last name", 20, "firstname.lastname@domain.com", "40712345678");
    service.create(u1);
    service.create(u2);
    service.create(u3);
    assert(service.read(1) == u1);
    assert(service.read(2) == u2);
    assert(service.read(3) == u3);
    service.update(2, u4);
    assert(service.read(1) == u1);
    assert(service.read(4) == u4);
    assert(service.read(3) == u3);
}

void TestUserService::deleteUser() {
    clearFile("testService.csv");
    UserRepositoryCSV repository("testService.csv");
    UserService service(repository);
    User u1(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    service.create(u1);
    service.create(u2);
    service.create(u3);
    assert(service.read(1) == u1);
    assert(service.read(2) == u2);
    assert(service.read(3) == u3);
    service.del(2);
    assert(service.read().size() == 2);
    assert(service.read(1) == u1);
    assert(service.read(3) == u3);
}

void TestUserService::all() {
    createUser();
    readUser();
    updateUser();
    deleteUser();
}
