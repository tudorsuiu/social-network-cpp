//
// Created by Tudor on 5/6/2022.
//

#include "Message.h"
#include "../../ADT/List/List.h"

Message::Message() {
    this->id = 0;
}

Message::Message(unsigned int id, User sender, User receiver,
                 std::string data) {
    this->id = id;
    this->sender = sender;
    this->receiver = receiver;
    this->data = data;
}

Message::Message(std::string line, char separator) {
    this->loadFromString(line, separator);
}

Message::Message(const Message &message) {
    this->id = message.id;
    this->sender = message.sender;
    this->receiver = message.receiver;
    this->data = message.data;
}

Message::~Message() = default;

unsigned int Message::getId() {
    return this->id;
}

void Message::setId(unsigned int id) {
    this->id = id;
}

User Message::getSender() {
    return this->sender;
}

void Message::setSender(User sender) {
    this->sender = sender;
}

User Message::getReceiver() {
    return receiver;
}

void Message::setReceiver(User receiver) {
    this->receiver = receiver;
}

std::string Message::getData() {
    return this->data;
}

void Message::setData(std::string data) {
    this->data = data;
}

std::string Message::toStringDelimiter(char separator) {
    return std::to_string(this->id) + separator + this->sender.toStringDelimiter(',') + separator + this->receiver.toStringDelimiter(',') + separator + this->data;
}

void Message::loadFromString(std::string line, char separator) {
    List<std::string> messages;
    std::stringstream ss(line);
    std::string messageInfo;
    while(getline(ss, messageInfo, separator)) {
        messages.push_back(messageInfo);
    }
    if(messages.size() == 16) {
        unsigned int firstUserId, firstUserAge, secondUserId, secondUserAge;
        std::stringstream i(messages[0]);
        i >> this->id;
        std::stringstream fui(messages[1]);
        fui >> firstUserId;
        this->sender.setId(firstUserId);
        this->sender.setFirstName(messages[2]);
        this->sender.setLastName(messages[3]);
        std::stringstream fua(messages[4]);
        fua >> firstUserAge;
        this->sender.setAge(firstUserAge);
        this->sender.setEmail(messages[5]);
        this->sender.setPassword(messages[6]);
        this->sender.setPhoneNumber(messages[7]);
        std::stringstream sui(messages[8]);
        sui >> secondUserId;
        this->receiver.setId(secondUserId);
        this->receiver.setFirstName(messages[9]);
        this->receiver.setLastName(messages[10]);
        std::stringstream sua(messages[11]);
        sua >> secondUserAge;
        this->receiver.setAge(secondUserAge);
        this->receiver.setEmail(messages[12]);
        this->receiver.setPassword(messages[13]);
        this->receiver.setPhoneNumber(messages[14]);
        this->data = messages[15];
    }
}

Message &Message::operator=(const Message &message) {
    this->id = message.id;
    this->sender = message.sender;
    this->receiver = message.receiver;
    this->data = message.data;
    return *this;
}

bool Message::operator==(const Message &message) const {
    return this->id == message.id &&
    this->sender == message.sender &&
    this->receiver == message.receiver &&
    this->data == message.data;
}

bool Message::operator!=(const Message &message) const {
    return !(*this == message);
}

std::istream &operator>>(std::istream &is, Message &message) {
    unsigned int id;
    std::cout << "Enter message id:"; is >> id;
    message.id = id;

    unsigned int firstUserId;
    std::cout << "Enter first user id:"; is >> firstUserId;
    message.sender.setId(firstUserId);

    std::string firstUserFirstName;
    std::cout << "Enter first user first name:"; is >> firstUserFirstName;
    message.sender.setFirstName(firstUserFirstName);

    std::string firstUserLastName;
    std::cout << "Enter first user last name:"; is >> firstUserLastName;
    message.sender.setLastName(firstUserLastName);

    unsigned int firstUserAge;
    std::cout << "Enter first user age:"; is >> firstUserAge;
    message.sender.setAge(firstUserAge);

    std::string firstUserEmail;
    std::cout << "Enter first user email:"; is >> firstUserEmail;
    message.sender.setEmail(firstUserEmail);

    std::string firstUserPassword;
    std::cout << "Enter first user password:"; is >> firstUserPassword;
    message.sender.setPassword(firstUserPassword);

    std::string firstUserPhoneNumber;
    std::cout << "Enter first user phone number:"; is >> firstUserPhoneNumber;
    message.sender.setPhoneNumber(firstUserPhoneNumber);

    unsigned int secondUserId;
    std::cout << "Enter second user id:"; is >> secondUserId;
    message.receiver.setId(secondUserId);

    std::string secondUserFirstName;
    std::cout << "Enter second user first name:"; is >> secondUserFirstName;
    message.receiver.setFirstName(secondUserFirstName);

    std::string secondUserLastName;
    std::cout << "Enter second user last name:"; is >> secondUserLastName;
    message.receiver.setLastName(secondUserLastName);

    unsigned int secondUserAge;
    std::cout << "Enter second user age:"; is >> secondUserAge;
    message.receiver.setAge(secondUserAge);

    std::string secondUserEmail;
    std::cout << "Enter second user email:"; is >> secondUserEmail;
    message.receiver.setEmail(secondUserEmail);

    std::string secondUserPassword;
    std::cout << "Enter second user password:"; is >> secondUserPassword;
    message.receiver.setPassword(secondUserPassword);

    std::string secondUserPhoneNumber;
    std::cout << "Enter second user phone number:"; is >> secondUserPhoneNumber;
    message.receiver.setPhoneNumber(secondUserPhoneNumber);

    std::string data;
    std::cout << "Enter message:"; is >> data;
    message.data = data;

    return is;
}

std::ostream &operator<<(std::ostream &os, Message &message) {
    os << "Message(" << message.id << ", " << message.sender.getFirstName() << " " << message.sender.getLastName() << ", "
    << message.receiver.getFirstName() << " " << message.receiver.getLastName() << ", " << message.data << ")" << '\n';

    return os;
}
