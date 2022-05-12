//
// Created by Tudor on 5/4/2022.
//

#include "User.h"
#include "../Array/List.h"

User::User() {
    this->id = 0;
    this->age = 0;
}

User::User(unsigned int id, std::string firstName, std::string lastName, unsigned int age,
           std::string email, std::string password, std::string phoneNumber) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->email = email;
    this->password = password;
    this->phoneNumber = phoneNumber;
}

User::User(std::string line, char separator) {
    this->loadFromString(line, separator);
}

User::User(const User &user) {
    this->id = user.id;
    this->firstName = user.firstName;
    this->lastName = user.lastName;
    this->age = user.age;
    this->email = user.email;
    this->password = user.password;
    this->phoneNumber = user.phoneNumber;
}

User::~User() = default;

unsigned int User::getId() {
    return this->id;
}

void User::setId(unsigned int id) {
    this->id = id;
}

std::string User::getFirstName() {
    return this->firstName;
}

void User::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

std::string User::getLastName() {
    return this->lastName;
}

void User::setLastName(std::string lastName) {
    this->lastName = lastName;
}

unsigned int User::getAge() {
    return this->age;
}

void User::setAge(unsigned int age) {
    this->age = age;
}

std::string User::getEmail() {
    return this->email;
}

void User::setEmail(std::string email) {
    this->email = email;
}

std::string User::getPassword() {
    return this->password;
}

void User::setPassword(std::string password) {
    this->password = password;
}

std::string User::getPhoneNumber() {
    return this->phoneNumber;
}

void User::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

bool User::verifyPassword(std::string password) {
    return this->password == password;
}

std::string User::toStringDelimiter(char separator) {
    return std::to_string(this->id) + separator + this->firstName + separator + this->lastName + separator +
            std::to_string(this->age) + separator + this->email + separator + this->password + separator + this->phoneNumber;
}

void User::loadFromString(std::string line, char separator) {
    List<std::string> users;
    std::stringstream ss(line);
    std::string userInfo;
    while(getline(ss, userInfo, separator)) {
        users.push_back(userInfo);
    }
    if(users.size() == 7) {
        std::stringstream i(users[0]);
        i >> this->id;
        this->firstName = users[1];
        this->lastName = users[2];
        std::stringstream a(users[3]);
        a >> this->age;
        this->email = users[4];
        this->password = users[5];
        this->phoneNumber = users[6];
    }
}

User &User::operator=(const User &user) {
    this->id = user.id;
    this->firstName = user.firstName;
    this->lastName = user.lastName;
    this->age = user.age;
    this->email = user.email;
    this->password = user.password;
    this->phoneNumber = user.phoneNumber;
    return *this;
}

bool User::operator<(const User &user) const {
    return this->age < user.age;
}

bool User::operator>(const User &user) const {
    return user < *this;
}

bool User::operator<=(const User &user) const {
    return !(user < *this);
}

bool User::operator>=(const User &user) const {
    return !(*this < user);
}

bool User::operator==(const User &user) const {
    return this->id == user.id &&
    this->firstName == user.firstName &&
    this->lastName == user.lastName &&
    this->age == user.age &&
    this->email == user.email &&
    this->password == user.password &&
    this->phoneNumber == phoneNumber;
}

bool User::operator!=(const User &user) const {
    return !(*this == user);
}

std::istream &operator>>(std::istream &is, User &user) {
    unsigned int id;
    std::cout << "Enter user id:"; is >> id;
    user.id = id;

    std::string firstName;
    std::cout << "Enter user first name:"; is >> firstName;
    user.firstName = firstName;

    std::string lastName;
    std::cout << "Enter user last name:"; is >> lastName;
    user.lastName = lastName;

    unsigned int age;
    std::cout << "Enter user age:"; is >> age;
    user.age = age;

    std::string email;
    std::cout << "Enter user email:"; is >> email;
    user.email = email;

    std::string password;
    std::cout << "Enter user password:"; is >> password;
    user.password = password;

    std::string phoneNumber;
    std::cout << "Enter user phone number:"; is >> phoneNumber;
    user.phoneNumber = phoneNumber;

    return is;
}

std::ostream &operator<<(std::ostream &os, User &user) {
    os << "User id: " << user.id << '\n' <<
    "First name: " << user.firstName << '\n' <<
    "Last name: " << user.lastName << '\n' <<
    "Age: " << user.age << '\n' <<
    "Email: " << user.email << '\n' <<
    "Password: " << user.password << '\n' <<
    "Phone number: " << user.phoneNumber << '\n';

    return os;
}
