//
// Created by Tudor on 5/13/2022.
//

#include <fstream>
#include <cassert>
#include "TestMessageRepository.h"
#include "../../../Domain/Entities/User/User.h"
#include "../../../Domain/Entities/Message/Message.h"
#include "../../../Repository/RepositoryCSV.h"

void TestMessageRepository::clearFile(std::string fileName) {
    std::ofstream file(fileName);
}

void TestMessageRepository::addMessage() {
    clearFile("testMessageRepository.csv");
    RepositoryCSV<Message> repository("testMessageRepository.csv");
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message m1(1, sender, receiver, "Hello!");
    Message m2(2, sender, receiver, "Hello! How are you?");
    Message m3(3, sender, receiver, "I'm fine.");
    repository.addEntity(m1);
    repository.addEntity(m2);
    repository.addEntity(m3);
    assert(repository.readEntity(1) == m1);
    assert(repository.readEntity(2) == m2);
    assert(repository.readEntity(3) == m3);
}

void TestMessageRepository::readMessage() {
    clearFile("testMessageRepository.csv");
    RepositoryCSV<Message> repository("testMessageRepository.csv");
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message m1(1, sender, receiver, "Hello!");
    Message m2(2, sender, receiver, "Hello! How are you?");
    Message m3(3, sender, receiver, "I'm fine.");
    repository.addEntity(m1);
    repository.addEntity(m2);
    repository.addEntity(m3);
    assert(repository.readEntity(1) == m1);
    assert(repository.readEntity(2) == m2);
    assert(repository.readEntity(3) == m3);
}

void TestMessageRepository::updateMessage() {
    clearFile("testMessageRepository.csv");
    RepositoryCSV<Message> repository("testMessageRepository.csv");
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message m1(1, sender, receiver, "Hello!");
    Message m2(2, sender, receiver, "Hello! How are you?");
    Message m3(3, sender, receiver, "I'm fine.");
    repository.addEntity(m1);
    repository.addEntity(m2);
    repository.addEntity(m3);
    repository.updateEntity(m2, Message(2, sender, receiver, "Hello!"));
    assert(repository.readEntity(1) == m1);
    assert(repository.readEntity(2) == Message(2, sender, receiver, "Hello!"));
    assert(repository.readEntity(3) == m3);
}

void TestMessageRepository::deleteMessage() {
    clearFile("testMessageRepository.csv");
    RepositoryCSV<Message> repository("testMessageRepository.csv");
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message m1(1, sender, receiver, "Hello!");
    Message m2(2, sender, receiver, "Hello! How are you?");
    Message m3(3, sender, receiver, "I'm fine.");
    repository.addEntity(m1);
    repository.addEntity(m2);
    repository.addEntity(m3);
    assert(repository.readEntity(1) == m1);
    assert(repository.readEntity(2) == m2);
    assert(repository.readEntity(3) == m3);
    assert(repository.readEntity().size() == 3);
    repository.deleteEntity(m1);
    repository.deleteEntity(m2);
    repository.deleteEntity(m3);
    assert(repository.readEntity().size() == 0);
}

void TestMessageRepository::getPosById() {
    RepositoryCSV<Message> repository("testMessageRepository.csv");
    clearFile("testMessageRepository.csv");
    User sender(1, "Sender", "Test", 19, "sendertest@gmail.com", "cartof4", "40753123456");
    User receiver(2, "Receiver", "Test", 19, "receivertest@gmail.com", "cartof4", "40753234567");
    Message m1(1, sender, receiver, "Hello!");
    Message m2(2, sender, receiver, "Hello! How are you?");
    Message m3(3, sender, receiver, "I'm fine.");
    repository.addEntity(m1);
    repository.addEntity(m2);
    repository.addEntity(m3);
    assert(repository.getPosById(1) == 0);
    assert(repository.getPosById(2) == 1);
    assert(repository.getPosById(3) == 2);
}

void TestMessageRepository::all() {
    addMessage();
    readMessage();
    updateMessage();
    deleteMessage();
    getPosById();
}
