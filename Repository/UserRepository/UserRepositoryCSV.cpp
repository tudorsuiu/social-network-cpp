//
// Created by Tudor on 5/4/2022.
//

#include <fstream>
#include "UserRepositoryCSV.h"

UserRepositoryCSV::UserRepositoryCSV(std::string fileName) {
    this->fileName = fileName;
    this->loadFromFile();
}

void UserRepositoryCSV::addUser(User user) {
    this->users.push_back(user);
    this->saveToFile();
}

List<User> UserRepositoryCSV::readUser() {
    return users;
}

User UserRepositoryCSV::readUser(unsigned int id) {
    if(getPosById(id) != -1) {
        return users[getPosById(id)];
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

void UserRepositoryCSV::updateUser(unsigned int id, User newUser) {
    if(getPosById(id) != -1) {
        users[getPosById(id)] = newUser;
        this->saveToFile();
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

void UserRepositoryCSV::deleteUser(unsigned int id) {
    if(getPosById(id) != -1) {
        users.erase(getPosById(id));
        this->saveToFile();
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

unsigned int UserRepositoryCSV::getPosById(unsigned int id) {
    for(int i = 0; i < users.size(); i++) {
        if(users[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

void UserRepositoryCSV::saveToFile() {
    std::ofstream fout(this->fileName);
    for(int i = 0; i < users.size(); i++) {
        fout << users[i].toStringDelimiter(',') << std::endl;
    }
    fout.close();
}

void UserRepositoryCSV::loadFromFile() {
    std::string line;
    std::ifstream fin(this->fileName);
    while(std::getline(fin, line)) {
        User user(line, ',');
        this->users.push_back(user);
    }
}
