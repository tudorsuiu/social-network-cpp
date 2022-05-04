//
// Created by Tudor on 5/4/2022.
//

#ifndef PROIECT_SDA_USERSERVICE_H
#define PROIECT_SDA_USERSERVICE_H


#include "../../Repository/UserRepository/UserRepositoryCSV.h"

class UserService {
private:
    UserRepositoryCSV userRepository;
public:
    /**
     * Constructor
     * @param userRepository: repository
     */
    UserService(UserRepositoryCSV &userRepository);

    /**
     * Add user to repository
     * @param user: User object
     */
    void create(User user);

    /**
     * Reads all users stored in repository
     * @return: all users stored in repository
     */
    Array<User> read();

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
};


#endif //PROIECT_SDA_USERSERVICE_H
