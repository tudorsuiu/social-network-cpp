//
// Created by Tudor on 5/13/2022.
//

#ifndef USERREPOSITORYCSV_H_MESSAGESERVICE_H
#define USERREPOSITORYCSV_H_MESSAGESERVICE_H


#include "../../Domain/Entities/Message/Message.h"
#include "../../Repository/RepositoryCSV.h"
#include "../../Domain/Validators/MessageValidator/MessageValidator.h"
#include "../UserService/UserService.h"

class MessageService {
private:
    MessageValidator messageValidator;
    RepositoryCSV<Message> messageRepository;
    UserService userService;
public:
    /**
     * Constructor
     * @param messageRepository: repository
     */
    MessageService(RepositoryCSV<Message> &messageRepository, UserService &userService);

    /**
     * Add message to repository
     * @param message: Message object
     */
    void create(Message message);

    /**
     * Reads all messages stored in repository
     * @return: all messages stored in repository
     */
    List<Message> read();

    /**
     * Read message with given id
     * @param id: message id
     * @return:
     */
    Message read(unsigned int id);

    /**
     * Update message
     * @param id: message id
     * @param newMessage: update message
     */
    void update(unsigned int id, Message newMessage);

    /**
     * Delete message
     * @param id: message id
     */
    void del(unsigned int id);

    /**
     * Checks if entity ID already exist
     * @param id: id
     * @return: true if exists, false otherwise
     */
    bool doesExistId(unsigned int id);

    /**
     * Checks if the receiver exists
     * @param receiver: receiver
     * @return: true if exists, false otherwise
     */
    bool doesExistReceiver(User receiver);
};


#endif //USERREPOSITORYCSV_H_MESSAGESERVICE_H
