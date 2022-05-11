//
// Created by Tudor on 5/6/2022.
//

#include "Friendship.h"
#include "../Array/Array.h"

Friendship::Friendship() {
    this->id = 0;
}

Friendship::Friendship(unsigned int id, User firstUser, User secondUser,
                       std::string status) {
    this->id = id;
    this->firstUser = firstUser;
    this->secondUser = secondUser;
    this->status = status;
}

Friendship::Friendship(std::string line, char separator) {
    this->loadFromstring(line, separator);
}

Friendship::Friendship(const Friendship &friendship) {
    this->id = friendship.id;
    this->firstUser = friendship.firstUser;
    this->secondUser = friendship.secondUser;
    this->status = friendship.status;
}

Friendship::~Friendship() = default;

unsigned int Friendship::getId() {
    return this->id;
}

void Friendship::setId(unsigned int id) {
    this->id = id;
}

User Friendship::getFirstUser() {
    return this->firstUser;
}

void Friendship::setFirstUser(User firstUser) {
    this->firstUser = firstUser;
}

User Friendship::getSecondUser() {
    return secondUser;
}

void Friendship::setSecondUser(User secondUser) {
    this->secondUser = secondUser;
}

std::string Friendship::getStatus() {
    return this->status;
}

void Friendship::setStatus(std::string status) {
    this->status = status;
}

std::string Friendship::toStringDelimiter(char separator) {
    return std::to_string(this->id) + separator + firstUser.toStringDelimiter(',') + separator + secondUser.toStringDelimiter(',') + separator + this->status;
}

void Friendship::loadFromstring(std::string line, char separator) {
    Array<std::string> friendships;
    std::stringstream ss(line);
    std::string friendshipInfo;
    while(getline(ss, friendshipInfo, separator)) {
        friendships.push_back(friendshipInfo);
    }
    if(friendships.size() == 16) {
        unsigned int firstUserId, firstUserAge, secondUserId, secondUserAge;
        std::stringstream i(friendships[0]);
        i >> this->id;
        std::stringstream fui(friendships[1]);
        fui >> firstUserId;
        this->firstUser.setId(firstUserId);
        this->firstUser.setFirstName(friendships[2]);
        this->firstUser.setLastName(friendships[3]);
        std::stringstream fua(friendships[4]);
        fua >> firstUserAge;
        this->firstUser.setAge(firstUserAge);
        this->firstUser.setEmail(friendships[5]);
        this->firstUser.setPassword(friendships[6]);
        this->firstUser.setPhoneNumber(friendships[7]);
        std::stringstream sui(friendships[8]);
        sui >> secondUserId;
        this->secondUser.setId(secondUserId);
        this->secondUser.setFirstName(friendships[9]);
        this->secondUser.setLastName(friendships[10]);
        std::stringstream sua(friendships[11]);
        sua >> secondUserAge;
        this->secondUser.setAge(secondUserAge);
        this->secondUser.setEmail(friendships[12]);
        this->secondUser.setPassword(friendships[13]);
        this->secondUser.setPhoneNumber(friendships[14]);
        this->status = friendships[15];
    }
}

Friendship &Friendship::operator=(const Friendship &friendship) {
    this->id = friendship.id;
    this->firstUser = friendship.firstUser;
    this->secondUser = friendship.secondUser;
    this->status = friendship.status;
}

bool Friendship::operator==(const Friendship &friendship) const {
    return this->id == friendship.id &&
    this->firstUser == friendship.firstUser &&
    this->secondUser == friendship.secondUser &&
    this->status == friendship.status;
}

bool Friendship::operator!=(const Friendship &friendship) const {
    return !(*this == friendship);
}

std::istream &operator>>(std::istream &is, Friendship &friendship) {











    return is;
}

std::ostream &operator<<(std::ostream &os, Friendship &friendship) {
    os << "Friendship id: " << friendship.id << '\n' <<
    "This is a relation of friendship between: " << friendship.firstUser << " and " << friendship.secondUser << '\n' <<
    "Friendship status: " << friendship.status << '\n';
    return os;
}
