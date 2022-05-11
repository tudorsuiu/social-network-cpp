//
// Created by Tudor on 5/6/2022.
//

#include "Message.h"
#include "../Array/Array.h"

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
    Array<std::string> messages;
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






    return is;
}

std::ostream &operator<<(std::ostream &os, Message &message) {
    os << "Message id: " << message.id << '\n' <<
    "Message sender: " << message.sender.getFirstName() << " " << message.sender.getLastName() << '\n' <<
    "Message receiver: " << message.receiver.getFirstName() << " " << message.receiver.getLastName() << '\n' <<
    "Message: " << message.data << '\n';
    return os;
}
