//
// Created by Tudor on 5/4/2022.
//

#include "UserService.h"

UserService::UserService(UserRepositoryCSV &userRepository) : userRepository(userRepository) {}

void UserService::create(User user) {
    userRepository.addUser(user);
}

List<User> UserService::read() {
    return userRepository.readUser();
}

User UserService::read(unsigned int id) {
    return userRepository.readUser(id);
}

void UserService::update(unsigned int id, User newUser) {
    userRepository.updateUser(id, newUser);
}

void UserService::del(unsigned int id) {
    userRepository.deleteUser(id);
}
