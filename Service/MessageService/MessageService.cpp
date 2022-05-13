//
// Created by Tudor on 5/13/2022.
//

#include "MessageService.h"

MessageService::MessageService(RepositoryCSV<Message> &messageRepository) : messageRepository(messageRepository) {}

void MessageService::create(Message message) {
    messageRepository.addEntity(message);
}

List<Message> MessageService::read() {
    return messageRepository.readEntity();
}

Message MessageService::read(unsigned int id) {
    return messageRepository.readEntity(id);
}

void MessageService::update(unsigned int id, Message newMessage) {
    messageRepository.updateEntity(id, newMessage);
}

void MessageService::del(unsigned int id) {
    messageRepository.deleteEntity(id);
}
