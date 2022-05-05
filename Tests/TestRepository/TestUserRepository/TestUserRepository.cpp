//
// Created by Tudor on 5/5/2022.
//

#include <cassert>
#include <fstream>
#include "TestUserRepository.h"
#include "../../../Repository/UserRepository/UserRepositoryCSV.h"
void TestUserRepository::clearFile(std::string fileName) {
    std::ofstream file(fileName);
}

void TestUserRepository::addUser() {
    clearFile("testUserRepository.csv");
    UserRepositoryCSV repository("testUserRepository.csv");
    User u1(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    repository.addUser(u1);
    repository.addUser(u2);
    repository.addUser(u3);
    assert(repository.readUser(1) == u1);
    assert(repository.readUser(2) == u2);
    assert(repository.readUser(3) == u3);
}

void TestUserRepository::readUser() {
    clearFile("testUserRepository.csv");
    UserRepositoryCSV repository("testUserRepository.csv");
    User u1(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    repository.addUser(u1);
    repository.addUser(u2);
    repository.addUser(u3);
    assert(repository.readUser(1) == u1);
    assert(repository.readUser(2) == u2);
    assert(repository.readUser(3) == u3);
}

void TestUserRepository::updateUser() {
    clearFile("testUserRepository.csv");
    UserRepositoryCSV repository("testUserRepository.csv");
    User u1(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u4(4, "First name", "Last name", 20, "firstname.lastname@domain.com", "40712345678");
    repository.addUser(u1);
    repository.addUser(u2);
    repository.addUser(u3);
    repository.updateUser(2, u4);
    assert(repository.readUser(1) == u1);
    assert(repository.readUser(4) == u4);
    assert(repository.readUser(3) == u3);
}

void TestUserRepository::deleteUser() {
    clearFile("testUserRepository.csv");
    UserRepositoryCSV repository("testUserRepository.csv");
    User u1(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    repository.addUser(u1);
    repository.addUser(u2);
    repository.addUser(u3);
    assert(repository.readUser().size() == 3);
    assert(repository.readUser(1) == u1);
    assert(repository.readUser(2) == u2);
    assert(repository.readUser(3) == u3);
    repository.deleteUser(3);
    assert(repository.readUser().size() == 2);
    assert(repository.readUser(1) == u1);
    assert(repository.readUser(2) == u2);
}

void TestUserRepository::getPosById() {
    clearFile("testUserRepository.csv");
    UserRepositoryCSV repository("testUserRepository.csv");
    User u1(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname@domain.com", "40712345678");
    repository.addUser(u1);
    repository.addUser(u2);
    repository.addUser(u3);
    assert(repository.getPosById(1) == 0);
    assert(repository.getPosById(2) == 1);
    assert(repository.getPosById(3) == 2);
}

void TestUserRepository::all() {
    addUser();
    readUser();
    updateUser();
    deleteUser();
}
