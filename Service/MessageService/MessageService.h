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
    RepositoryCSV<Message> &messageRepository;
    UserService &userService;
public:
    /**
     * Constructor
     * @param messageRepository: repository
     */
    MessageService(RepositoryCSV<Message> &messageRepository, UserService &userService);

    /**
     * Last ID getter
     * @return: last ID from file
     */
    unsigned int getId();

    /**
     * Create message
     * @param sender: message sender
     * @param receiver: message receiver
     * @param data: message
     */
    void create(User sender, User receiver, std::string data);

    /**
     * Reads all messages stored in repository
     * @return: all messages stored in repository
     */
    List<Message> read();

    /**
     * Read message with given id
     * @param id: message id
     * @return: message with given id
     */
    Message read(unsigned int id);

    /**
     * Update oldMessage to newMessage
     * @param oldMessage: old message
     * @param newMessage: new message
     */
    void update(Message oldMessage, Message newMessage);

    /**
     * Delete message
     * @param message: message to be deleted
     */
    void del(Message message);

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

    /**
     * Get message by email and data
     * @param senderEmail: sender email
     * @param receiverEmail: receiver email
     * @param data: message
     * @return: Message object
     */
    Message getMessageByEmailsAndData(std::string senderEmail, std::string receiverEmail, std::string data);

    /**
     * Get conversation with user
     * @param loggedUser: user
     * @param user: user
     * @return: List<Message> - conversation
     */
    List<Message> getConversationWithUser(User loggedUser, User user);
};


#endif //USERREPOSITORYCSV_H_MESSAGESERVICE_H
