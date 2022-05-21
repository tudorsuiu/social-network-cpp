//
// Created by Tudor on 5/5/2022.
//

#include "TestUserService.h"
#include "../../../Service/UserService/UserService.h"
#include <cassert>

void TestUserService::clearFile(std::string fileName) {
    std::ofstream file(fileName);
}

void TestUserService::createUser() {
    clearFile("testUserService.csv");
    RepositoryCSV<User> repository("testUserService.csv");
    UserService service(repository);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    service.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    service.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    service.create("First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    assert(service.read(1) == u1);
    assert(service.read(2) == u2);
    assert(service.read(3) == u3);
}

void TestUserService::readUser() {
    clearFile("testUserService.csv");
    RepositoryCSV<User> repository("testUserService.csv");
    UserService service(repository);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    service.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    service.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    service.create("First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    assert(service.read().size() == 3);
    assert(service.read(1) == u1);
    assert(service.read(2) == u2);
    assert(service.read(3) == u3);
}

void TestUserService::updateUser() {
    clearFile("testUserService.csv");
    RepositoryCSV<User> repository("testUserService.csv");
    UserService service(repository);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123","40712345678");
    User u4(4, "First name", "Last name", 20, "firstname.lastname4@domain.com", "parola123", "40712345678");
    service.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    service.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    service.create("First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    assert(service.read(1) == u1);
    assert(service.read(2) == u2);
    assert(service.read(3) == u3);
    service.update(u2, u4);
    assert(service.read(1) == u1);
    assert(service.read(4) == u4);
    assert(service.read(3) == u3);
}

void TestUserService::deleteUser() {
    clearFile("testUserService.csv");
    RepositoryCSV<User> repository("testUserService.csv");
    UserService service(repository);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    service.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    service.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    service.create("First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    assert(service.read(1) == u1);
    assert(service.read(2) == u2);
    assert(service.read(3) == u3);
    service.del(u2);
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
