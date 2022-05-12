//
// Created by Tudor on 5/4/2022.
//

#ifndef PROIECT_SDA_USERREPOSITORYCSV_H
#define PROIECT_SDA_USERREPOSITORYCSV_H


#include "../../Domain/User/User.h"
#include "../../Domain/Array/List.h"

class UserRepositoryCSV {
private:
    List<User> users;
    std::string fileName;
public:
    /**
     * Read from file
     * @param fileName: file name
     */
    UserRepositoryCSV(std::string fileName);

    /**
     * Destructor
     */
    ~UserRepositoryCSV() = default;

    /**
     * Add user to file
     * @param user: User object
     */
    void addUser(User user);

    /**
     * Read users from file
     * @return: all users from file
     */
    List<User> readUser();

    /**
     * Read user from file
     * @param id: user id
     * @return: User with given id
     */
    User readUser(unsigned int id);

    /**
     * Update user from file
     * @param id: user id
     * @param newUser: updated user
     */
    void updateUser(unsigned int id, User newUser);

    /**
     * Delete user from file
     * @param id: user id
     */
    void deleteUser(unsigned int id);

    /**
     * Get position by user id
     * @param id: user id
     * @return: user position in file
     */
    unsigned int getPosById(unsigned int id);

    /**
     * Save users in file
     */
    void saveToFile();

    /**
     * Load users from file
     */
    void loadFromFile();
};


#endif //PROIECT_SDA_USERREPOSITORYCSV_H
