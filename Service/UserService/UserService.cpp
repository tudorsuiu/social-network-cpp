//
// Created by Tudor on 5/4/2022.
//

#include "UserService.h"
#include "../../Domain/MyException.h"

UserService::UserService(RepositoryCSV<User> &userRepository) : userRepository(userRepository) {}

unsigned int UserService::getId() {
    if(userRepository.readEntity().size() == 0) {
        return 1;
    }
    else {
        return userRepository.readEntity()[userRepository.readEntity().size() - 1].getId() + 1;
    }
}

void UserService::create(std::string firstName, std::string lastName, unsigned int age, std::string email, std::string password, std::string phoneNumber) {
    if(doesExistEmail(email)) {
        throw MyException("An user with this email already exists.");
    }
    User user(getId(), firstName, lastName, age, email, password, phoneNumber);
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
        throw MyException("User was not found.");
    }
    return userRepository.readEntity(id);
}

void UserService::update(User oldUser, User newUser) {
    if(!doesExistUser(oldUser)) {
        throw MyException("User was not found.");
    }
    else if(doesExistId(newUser.getId())) {
        throw MyException("An user with this ID already exists.");
    } else if(doesExistEmail(newUser.getEmail())) {
        throw MyException("An user with this email already exists.");
    }
    userValidator.validate(newUser);
    userRepository.updateEntity(oldUser, newUser);
}

void UserService::del(User user) {
    if(!doesExistUser(user)) {
        throw MyException("User was not found.");
    }
    userRepository.deleteEntity(user);
}

unsigned int UserService::numberOfUsers() {
    return userRepository.readEntity().size();
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

bool UserService::doesExistUser(User user) {
    for(int i = 0; i < userRepository.readEntity().size(); i++) {
        if(userRepository.readEntity()[i] == user) {
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
    throw MyException("An user with given credentials doesn't exist.");
}

User UserService::getUserByEmail(std::string email) {
    User user;
    for(int i = 0; i < userRepository.readEntity().size(); i++) {
        user = userRepository.readEntity()[i];
        if(user.getEmail() == email) {
            return user;
        }
    }
    throw MyException("An user with given email doesn't exist.");
}
