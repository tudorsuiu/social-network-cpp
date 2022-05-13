//
// Created by Tudor on 5/4/2022.
//

#include "UserService.h"
#include "../../Repository/RepositoryCSV.h"
#include "../../Domain/User/User.h"

UserService::UserService(RepositoryCSV<User> &userRepository) : userRepository(userRepository) {}

void UserService::create(User user) {
    userRepository.addEntity(user);
}

List<User> UserService::read() {
    return userRepository.readEntity();
}

User UserService::read(unsigned int id) {
    return userRepository.readEntity(id);
}

void UserService::update(unsigned int id, User newUser) {
    userRepository.updateEntity(id, newUser);
}

void UserService::del(unsigned int id) {
    userRepository.deleteEntity(id);
}
