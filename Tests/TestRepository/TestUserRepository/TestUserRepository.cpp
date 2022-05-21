//
// Created by Tudor on 5/5/2022.
//

#include <cassert>
#include "TestUserRepository.h"
#include "../../../Domain/Entities/User/User.h"
#include "../../../Repository/RepositoryCSV.h"

void TestUserRepository::clearFile(std::string fileName) {
    std::ofstream file(fileName);
}

void TestUserRepository::addUser() {
    clearFile("testUserRepository.csv");
    RepositoryCSV<User> repository("testUserRepository.csv");
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    repository.addEntity(u1);
    repository.addEntity(u2);
    repository.addEntity(u3);
    assert(repository.readEntity(1) == u1);
    assert(repository.readEntity(2) == u2);
    assert(repository.readEntity(3) == u3);
}

void TestUserRepository::readUser() {
    clearFile("testUserRepository.csv");
    RepositoryCSV<User> repository("testUserRepository.csv");
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    repository.addEntity(u1);
    repository.addEntity(u2);
    repository.addEntity(u3);
    assert(repository.readEntity(1) == u1);
    assert(repository.readEntity(2) == u2);
    assert(repository.readEntity(3) == u3);
}

void TestUserRepository::updateUser() {
    clearFile("testUserRepository.csv");
    RepositoryCSV<User> repository("testUserRepository.csv");
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    User u4(4, "First name", "Last name", 20, "firstname.lastname4@domain.com", "parola123", "40712345678");
    repository.addEntity(u1);
    repository.addEntity(u2);
    repository.addEntity(u3);
    repository.updateEntity(u2, u4);
    assert(repository.readEntity(1) == u1);
    assert(repository.readEntity(4) == u4);
    assert(repository.readEntity(3) == u3);
}

void TestUserRepository::deleteUser() {
    clearFile("testUserRepository.csv");
    RepositoryCSV<User> repository("testUserRepository.csv");
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    repository.addEntity(u1);
    repository.addEntity(u2);
    repository.addEntity(u3);
    assert(repository.readEntity().size() == 3);
    assert(repository.readEntity(1) == u1);
    assert(repository.readEntity(2) == u2);
    assert(repository.readEntity(3) == u3);
    repository.deleteEntity(u3);
    assert(repository.readEntity().size() == 2);
    assert(repository.readEntity(1) == u1);
    assert(repository.readEntity(2) == u2);
}

void TestUserRepository::getPosById() {
    clearFile("testUserRepository.csv");
    RepositoryCSV<User> repository("testUserRepository.csv");
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    User u3(3, "First name", "Last name", 18, "firstname.lastname3@domain.com", "parola123", "40712345678");
    repository.addEntity(u1);
    repository.addEntity(u2);
    repository.addEntity(u3);
    assert(repository.getPosById(1) == 0);
    assert(repository.getPosById(2) == 1);
    assert(repository.getPosById(3) == 2);
}

void TestUserRepository::all() {
    addUser();
    readUser();
    updateUser();
    deleteUser();
    getPosById();
}
