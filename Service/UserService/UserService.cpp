//
// Created by Tudor on 5/4/2022.
//

#include "UserService.h"
#include "../../Domain/MyException.h"

UserService::UserService(RepositoryCSV<User> &userRepository) : userRepository(userRepository) {}

void UserService::create(User user) {
    if(doesExistId(user.getId())) {
        throw MyException("An user with this ID already exists.");
    }
    else if(doesExistEmail(user.getEmail())) {
        throw MyException("An user with this email already exists.");
    }
    userValidator.validate(user);
    userRepository.addEntity(user);
}

List<User> UserService::read() {
    if(userRepository.readEntity().size() == 0) {
        throw MyException("There are no registered users.");
    }
    return userRepository.readEntity();
}

User UserService::read(unsigned int id) {
    if(!doesExistId(id)) {
        throw MyException("User with given ID was not found.");
    }
    return userRepository.readEntity(id);
}

void UserService::update(unsigned int id, User newUser) {
    if(!doesExistId(id)) {
        throw MyException("User with given ID was not found.");
    }
    userValidator.validate(newUser);
    userRepository.updateEntity(id, newUser);
}

void UserService::del(unsigned int id) {
    if(!doesExistId(id)) {
        throw MyException("User with given ID was not found.");
    }
    userRepository.deleteEntity(id);
}

bool UserService::doesExistId(unsigned int id) {
    return userRepository.getPosById(id) != -1;
}

bool UserService::doesExistEmail(std::string email) {
    for(int i = 0; i < userRepository.readEntity().size(); i++) {
        if(userRepository.readEntity()[i].getEmail() == email) {
            return true;
        }
    }
    return false;
}

User UserService::getUserByEmailAndPassword(std::string email, std::string password) {
    User user;
    for(int i = 0; i < userRepository.readEntity().size(); i++) {
        user = userRepository.readEntity()[i];
        if(user.getEmail() == email and user.getPassword() == password) {
            return user;
        }
    }
    return User(0, "Default", "Default", 19, "default@default.com", "default", "40712345678");
}

User UserService::getUserByEmail(std::string email) {
    User user;
    for(int i = 0; i < userRepository.readEntity().size(); i++) {
        user = userRepository.readEntity()[i];
        if(user.getEmail() == email) {
            return user;
        }
    }
    return User(0, "Default", "Default", 19, "default@default.com", "default", "40712345678");
}
