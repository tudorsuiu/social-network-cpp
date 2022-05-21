//
// Created by Tudor on 5/6/2022.
//

#include "Friendship.h"
#include "../../ADT/List/List.h"

Friendship::Friendship() {
    this->id = 0;
}

Friendship::Friendship(unsigned int id, User firstUser, User secondUser) {
    this->id = id;
    this->firstUser = firstUser;
    this->secondUser = secondUser;
}

Friendship::Friendship(std::string line, char separator) {
    this->loadFromstring(line, separator);
}

Friendship::Friendship(const Friendship &friendship) {
    this->id = friendship.id;
    this->firstUser = friendship.firstUser;
    this->secondUser = friendship.secondUser;
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

std::string Friendship::toStringDelimiter(char separator) {
    return std::to_string(this->id) + separator + firstUser.toStringDelimiter(',') + separator + secondUser.toStringDelimiter(',');
}

void Friendship::loadFromstring(std::string line, char separator) {
    List<std::string> friendships;
    std::stringstream ss(line);
    std::string friendshipInfo;
    while(getline(ss, friendshipInfo, separator)) {
        friendships.push_back(friendshipInfo);
    }
    if(friendships.size() == 15) {
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
    }
}

Friendship &Friendship::operator=(const Friendship &friendship) {
    this->id = friendship.id;
    this->firstUser = friendship.firstUser;
    this->secondUser = friendship.secondUser;
}

bool Friendship::operator==(const Friendship &friendship) const {
    return this->id == friendship.id &&
    this->firstUser == friendship.firstUser &&
    this->secondUser == friendship.secondUser;
}

bool Friendship::operator!=(const Friendship &friendship) const {
    return !(*this == friendship);
}

std::istream &operator>>(std::istream &is, Friendship &friendship) {
    unsigned int id;
    std::cout << "Enter friendship relation id:"; is >> id;
    friendship.id = id;

    unsigned int firstUserId;
    std::cout << "Enter first user id:"; is >> firstUserId;
    friendship.firstUser.setId(firstUserId);

    std::string firstUserFirstName;
    std::cout << "Enter first user first name:"; is >> firstUserFirstName;
    friendship.firstUser.setFirstName(firstUserFirstName);

    std::string firstUserLastName;
    std::cout << "Enter first user last name:"; is >> firstUserLastName;
    friendship.firstUser.setLastName(firstUserLastName);

    unsigned int firstUserAge;
    std::cout << "Enter first user age:"; is >> firstUserAge;
    friendship.firstUser.setAge(firstUserAge);

    std::string firstUserEmail;
    std::cout << "Enter first user email:"; is >> firstUserEmail;
    friendship.firstUser.setEmail(firstUserEmail);

    std::string firstUserPassword;
    std::cout << "Enter first user password:"; is >> firstUserPassword;
    friendship.firstUser.setPassword(firstUserPassword);

    std::string firstUserPhoneNumber;
    std::cout << "Enter first user phone number:"; is >> firstUserPhoneNumber;
    friendship.firstUser.setPhoneNumber(firstUserPhoneNumber);

    unsigned int secondUserId;
    std::cout << "Enter second user id:"; is >> secondUserId;
    friendship.secondUser.setId(secondUserId);

    std::string secondUserFirstName;
    std::cout << "Enter second user first name:"; is >> secondUserFirstName;
    friendship.secondUser.setFirstName(secondUserFirstName);

    std::string secondUserLastName;
    std::cout << "Enter second user last name:"; is >> secondUserLastName;
    friendship.secondUser.setLastName(secondUserLastName);

    unsigned int secondUserAge;
    std::cout << "Enter second user age:"; is >> secondUserAge;
    friendship.secondUser.setAge(secondUserAge);

    std::string secondUserEmail;
    std::cout << "Enter second user email:"; is >> secondUserEmail;
    friendship.secondUser.setEmail(secondUserEmail);

    std::string secondUserPassword;
    std::cout << "Enter second user password:"; is >> secondUserPassword;
    friendship.secondUser.setPassword(secondUserPassword);

    std::string secondUserPhoneNumber;
    std::cout << "Enter second user phone number:"; is >> secondUserPhoneNumber;
    friendship.secondUser.setPhoneNumber(secondUserPhoneNumber);

    return is;
}

std::ostream &operator<<(std::ostream &os, Friendship &friendship) {
    os << "Friendship(" << friendship.id << ", " << friendship.firstUser.getFirstName() << " "
    << friendship.firstUser.getLastName() << ", " << friendship.secondUser.getFirstName() << " "
    << friendship.secondUser.getLastName() << ")" << '\n';

    return os;
}
