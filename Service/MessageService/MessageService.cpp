//
// Created by Tudor on 5/13/2022.
//

#include "MessageService.h"
#include "../../Domain/MyException.h"

MessageService::MessageService(RepositoryCSV<Message> &messageRepository, UserService &userService) : messageRepository(messageRepository),
                                                                                                      userService(userService) {}

void MessageService::create(unsigned int id, std::string senderEmail, std::string receiverEmail, std::string data) {
    User sender = userService.getUserByEmail(senderEmail);
    User receiver = userService.getUserByEmail(receiverEmail);
    if(doesExistId(id)) {
        throw MyException("A message with this ID already exists.");
    }
    else if(!doesExistReceiver(receiver)) {
        throw MyException("Message receiver doesn't have an account.");
    }
    Message message(id, sender, receiver, data);
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

void MessageService::update(unsigned int id, std::string newSenderEmail, std::string newReceiverEmail, std::string newData) {
    User newSender = userService.getUserByEmail(newSenderEmail);
    User newReceiver = userService.getUserByEmail(newReceiverEmail);
    if(!doesExistId(id)) {
        throw MyException("Message with given ID was not found.");
    }
    else if(!doesExistReceiver(newReceiver)) {
        throw MyException("Message receiver doesn't have an account.");
    }
    Message newMessage(id, newSender, newReceiver, newData);
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
