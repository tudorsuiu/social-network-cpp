//
// Created by Tudor on 5/13/2022.
//

#include <cassert>
#include "TestMessage.h"
#include "../../../Domain/Message/Message.h"

void TestMessage::constructor() {
    Message message;
    User user;
    assert(message.getId() == 0);
    assert(message.getSender() == user);
    assert(message.getReceiver() == user);
    assert(message.getData().empty() == true);
}

void TestMessage::copyConstructor() {
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message message(1, sender, receiver, "Hello! This is a test.");
    Message copyMessage = message;
    assert(copyMessage.getId() == 1);
    assert(copyMessage.getSender() == sender);
    assert(copyMessage.getReceiver() == receiver);
    assert(copyMessage.getData() == "Hello! This is a test.");
}

void TestMessage::lineConstructor() {
    Message message("1,1,Sender,Test,19,sendertest@gmail.com,cartof4,40753123456,2,Receiver,Test,19,receivertest@gmail.com,cartof4,40753234567,Hello! This is a test.", ',');
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    assert(message.getId() == 1);
    assert(message.getSender() == sender);
    assert(message.getReceiver() == receiver);
    assert(message.getData() == "Hello! This is a test.");
}

void TestMessage::parametersConstructor() {
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message message(1, sender, receiver, "Hello! This is a test.");
    assert(message.getId() == 1);
    assert(message.getSender() == sender);
    assert(message.getReceiver() == receiver);
    assert(message.getData() == "Hello! This is a test.");
}

void TestMessage::getId() {
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message message(1, sender, receiver, "Hello! This is a test.");
    assert(message.getId() == 1);
}

void TestMessage::setId() {
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message message(1, sender, receiver, "Hello! This is a test.");
    message.setId(2);
    assert(message.getId() == 2);
}

void TestMessage::getSender() {
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message message(1, sender, receiver, "Hello! This is a test.");
    assert(message.getSender() == sender);
}

void TestMessage::setSender() {
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message message(1, sender, receiver, "Hello! This is a test.");
    User newSender(1, "New", "Sender", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    message.setSender(newSender);
    assert(message.getSender() == newSender);
}

void TestMessage::getReceiver() {
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message message(1, sender, receiver, "Hello! This is a test.");
    assert(message.getReceiver() == receiver);
}

void TestMessage::setReceiver() {
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message message(1, sender, receiver, "Hello! This is a test.");
    User newReceiver(1, "New", "Receiver", 19, "receivertest@gmail.com", "cartof4", "40753123456");
    message.setReceiver(newReceiver);
    assert(message.getReceiver() == newReceiver);
}

void TestMessage::getData() {
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message message(1, sender, receiver, "Hello! This is a test.");
    assert(message.getData() == "Hello! This is a test.");
}

void TestMessage::setData() {
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message message(1, sender, receiver, "Hello! This is a test.");
    message.setData("Hello! This is a change.");
    assert(message.getData() == "Hello! This is a change.");
}

void TestMessage::all() {
    constructor();
    copyConstructor();
    lineConstructor();
    parametersConstructor();
    getId();
    setId();
    getSender();
    setSender();
    getReceiver();
    setReceiver();
    getData();
    setData();
}
