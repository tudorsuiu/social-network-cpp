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

    unsigned int getId();

    /**
     * Create a Message object
     * @param id: message id
     * @param senderEmail: message sender
     * @param receiverEmail: message receiver
     * @param data: message data
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
     * @return:
     */
    Message read(unsigned int id);

    /**
     * Update a Message object
     * @param id: new message id
     * @param newSenderEmail: new message sender
     * @param newReceiverEmail: new message receiver
     * @param newData: new message data
     */
    void update(Message oldMessage, Message newMessage);

    /**
     * Delete message
     * @param id: message id
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

    Message getMessageByEmailsAndData(std::string senderEmail, std::string receiverEmail, std::string data);

    List<Message> getConversationWithUser(User loggedUser, User user);
};


#endif //USERREPOSITORYCSV_H_MESSAGESERVICE_H
