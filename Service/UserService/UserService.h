//
// Created by Tudor on 5/4/2022.
//

#ifndef PROIECT_SDA_USERSERVICE_H
#define PROIECT_SDA_USERSERVICE_H

#include "../../Domain/Entities/User/User.h"
#include "../../Repository/RepositoryCSV.h"
#include "../../Domain/Validators/UserValidator/UserValidator.h"
#include "../../Domain/ADT/BST/BST.h"

class UserService {
private:
    UserValidator userValidator;
    RepositoryCSV<User> &userRepository;
public:
    /**
     * Constructor
     * @param userRepository: repository
     */
    UserService(RepositoryCSV<User> &userRepository);

    /**
     * Last ID getter
     * @return: last ID from file
     */
    unsigned int getId();

    /**
     * Create user
     * @param firstName: first name
     * @param lastName: last name
     * @param age: age
     * @param email: email
     * @param password: password
     * @param phoneNumber: phone number
     */
    void create(std::string firstName, std::string lastName, unsigned int age, std::string email, std::string password, std::string phoneNumber);

    /**
     * Reads all users stored in repository
     * @return: all users stored in repository
     */
    List<User> read();

    /**
     * Read user with given id
     * @param id: user id
     * @return: user with given id
     */
    User read(unsigned int id);

    /**
     * Update oldUser with newUser
     * @param oldUser: old user
     * @param newUser: new user
     */
    void update(User oldUser, User newUser);

    /**
     * Delete user
     * @param user: user
     */
    void del(User user);

    /**
     * Number of users
     * @return: number of users
     */
    unsigned int numberOfUsers();

    /**
     * Checks if entity ID already exist
     * @param id: id
     * @return: true if exists, false otherwise
     */
    bool doesExistId(unsigned int id);

    /**
     * Checks if entity email already exist
     * @param email: email
     * @return: true if exists, false otherwise
     */
    bool doesExistEmail(std::string email);

    /**
     * Checks if user exists
     * @param user: user
     * @return: true if exists, false otherwise
     */
    bool doesExistUser(User user);

    /**
     * Checks if email and password are valid
     * @param email: email
     * @param password: password
     * @return: existing user if exists, default user otherwise
     */
    User getUserByEmailAndPassword(std::string email, std::string password);

    /**
     * Get user by email
     * @param email: to be searched email
     * @return: existing user if found, default user otherwise
     */
    User getUserByEmail(std::string email);
};


#endif //PROIECT_SDA_USERSERVICE_H
