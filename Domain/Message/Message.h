//
// Created by Tudor on 5/6/2022.
//

#ifndef PROIECT_SDA_MESSAGE_H
#define PROIECT_SDA_MESSAGE_H


#include "../User/User.h"

class Message {
private:
    unsigned int id;
    User sender;
    User receiver;
    std::string data;
public:
    /**
     * Constructor
     */
    Message();

    /**
     * Constructor with parameters
     * @param id: message id
     * @param sender: message sender
     * @param receiver: message receiver
     * @param data: message data
     */
    Message(unsigned int id, User sender, User receiver, std::string data);

    /**
     * Constructor from file
     * @param line: string with message details
     * @param separator: separator
     */
    Message(std::string line, char separator);

    /**
     * Copy-constructor
     * @param message: Message object
     */
    Message(const Message &message);

    /**
     * Destructor
     */
    ~Message();

    /**
     * Id getter
     * @return: message id
     */
    unsigned int getId();

    /**
     * Id setter
     * @param id: new message id
     */
    void setId(unsigned int id);

    /**
     * Sender getter
     * @return: message sender
     */
    User getSender();

    /**
     * Sender setter
     * @param sender: new message sender
     */
    void setSender(User sender);

    /**
     * Receiver getter
     * @return: message receiver
     */
    User getReceiver();

    /**
     * Receiver setter
     * @param receiver: new message receiver
     */
    void setReceiver(User receiver);

    /**
     * Data getter
     * @return: message data
     */
    std::string getData();

    /**
     * Data setter
     * @param data: new message data
     */
    void setData(std::string data);

    /**
     * To string delimiter
     * @param separator: separator
     * @return: Message object transformed into string
     */
    std::string toStringDelimiter(char separator);

    /**
     * Load Message from a string
     * @param line: given string
     * @param separator: separator
     */
    void loadFromString(std::string line, char separator);

    Message& operator=(const Message& message);
    bool operator==(const Message& message) const;
    bool operator!=(const Message& message) const;

    friend std::istream &operator>>(std::istream& is, Message& message);
    friend std::ostream &operator<<(std::ostream& os, Message& message);
};


#endif //PROIECT_SDA_MESSAGE_H
