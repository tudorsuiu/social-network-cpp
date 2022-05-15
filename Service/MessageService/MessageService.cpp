//
// Created by Tudor on 5/13/2022.
//

#include "MessageService.h"
#include "../../Domain/MyException.h"

MessageService::MessageService(RepositoryCSV<Message> &messageRepository, UserService &userService) : messageRepository(messageRepository),
                                                                                                      userService(userService) {}

void MessageService::create(Message message) {
    if(doesExistId(message.getId())) {
        throw MyException("A message with this ID already exists.");
    }
    else if(!doesExistReceiver(message.getReceiver())) {
        throw MyException("Message receiver doesn't have an account.");
    }
    messageValidator.validate(message);
    messageRepository.addEntity(message);
}

List<Message> MessageService::read() {
    if(messageRepository.readEntity().size() == 0) {
        throw MyException("There are no messages.");
    }
    return messageRepository.readEntity();
}

Message MessageService::read(unsigned int id) {
    if(!doesExistId(id)) {
        throw MyException("Message with given ID was not found.");
    }
    return messageRepository.readEntity(id);
}

void MessageService::update(unsigned int id, Message newMessage) {
    if(!doesExistId(id)) {
        throw MyException("Message with given ID was not found.");
    }
    else if(!doesExistReceiver(newMessage.getReceiver())) {
        throw MyException("Message receiver doesn't have an account.");
    }
    messageValidator.validate(newMessage);
    messageRepository.updateEntity(id, newMessage);
}

void MessageService::del(unsigned int id) {
    if(!doesExistId(id)) {
        throw MyException("Message with given ID was not found.");
    }
    messageRepository.deleteEntity(id);
}

bool MessageService::doesExistId(unsigned int id) {
    return messageRepository.getPosById(id) != -1;
}

bool MessageService::doesExistReceiver(User receiver) {
    for(int i = 0; i < userService.read().size(); i++) {
        if(userService.read()[i] == receiver) {
            return true;
        }
    }
    return false;
}
