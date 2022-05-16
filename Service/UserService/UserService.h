//
// Created by Tudor on 5/4/2022.
//

#ifndef PROIECT_SDA_USERSERVICE_H
#define PROIECT_SDA_USERSERVICE_H

#include "../../Domain/Entities/User/User.h"
#include "../../Repository/RepositoryCSV.h"
#include "../../Domain/Validators/UserValidator/UserValidator.h"

class UserService {
private:
    UserValidator userValidator;
    RepositoryCSV<User> userRepository;
public:
    /**
     * Constructor
     * @param userRepository: repository
     */
    UserService(RepositoryCSV<User> &userRepository);

    /**
     * Add user to repository
     * @param user: User object
     */
    void create(User user);

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
     * Update user
     * @param id: user id
     * @param newUser: updated user
     */
    void update(unsigned int id, User newUser);

    /**
     * Delete user
     * @param id: user id
     */
    void del(unsigned int id);

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
