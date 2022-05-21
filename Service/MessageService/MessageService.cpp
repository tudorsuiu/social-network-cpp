//
// Created by Tudor on 5/13/2022.
//

#include "MessageService.h"
#include "../../Domain/MyException.h"

MessageService::MessageService(RepositoryCSV<Message> &messageRepository, UserService &userService) : messageRepository(messageRepository),
                                                                                                      userService(userService) {}

unsigned int MessageService::getId() {
    if(messageRepository.readEntity().size() == 0) {
        return 1;
    }
    else {
        return messageRepository.readEntity()[messageRepository.readEntity().size() - 1].getId() + 1;
    }
}

void MessageService::create(User sender, User receiver, std::string data) {
    if(!userService.doesExistEmail(receiver.getEmail())) {
        throw MyException("Message receiver doesn't have an account.");
    }
    Message message(getId(), sender, receiver, data);
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

void MessageService::update(Message oldMessage, Message newMessage) {
    if(!doesExistId(oldMessage.getId())) {
        throw MyException("Message with given ID was not found.");
    }
    else if(!userService.doesExistEmail(newMessage.getReceiver().getEmail())) {
        throw MyException("Message receiver doesn't have an account.");
    }
    messageValidator.validate(newMessage);
    messageRepository.updateEntity(oldMessage, newMessage);
}

void MessageService::del(Message message) {
    if(!doesExistId(message.getId())) {
        throw MyException("Message with given ID was not found.");
    }
    messageRepository.deleteEntity(message);
}

bool MessageService::doesExistId(unsigned int id) {
    return messageRepository.getPosById(id) != -1;
}

Message MessageService::getMessageByEmailsAndData(std::string senderEmail,
                                                  std::string receiverEmail,
                                                  std::string data) {
    for(int i = 0; i < messageRepository.readEntity().size(); i++) {
        Message message = messageRepository.readEntity()[i];
        if(message.getSender().getEmail() == senderEmail && message.getReceiver().getEmail() == receiverEmail && message.getData() == data) {
            return message;
        }
    }
    throw MyException("Message with given details was not found.");
}

List<Message> MessageService::getConversationWithUser(User loggedUser, User user) {
    List<Message> result;
    for(int i = 0; i < messageRepository.readEntity().size(); i++) {
        if(messageRepository.readEntity()[i].getSender() == loggedUser && messageRepository.readEntity()[i].getReceiver() == user) {
            result.push_back(messageRepository.readEntity()[i]);
        }
        if(messageRepository.readEntity()[i].getSender() == user && messageRepository.readEntity()[i].getReceiver() == loggedUser) {
            result.push_back(messageRepository.readEntity()[i]);
        }
    }
    return result;
}
