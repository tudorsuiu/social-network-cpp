//
// Created by Tudor on 5/13/2022.
//

#ifndef USERREPOSITORYCSV_H_FRIENDSHIPSERVICE_H
#define USERREPOSITORYCSV_H_FRIENDSHIPSERVICE_H


#include "../../Domain/Entities/Friendship/Friendship.h"
#include "../../Repository/RepositoryCSV.h"
#include "../../Domain/Validators/FriendshipValidator/FriendshipValidator.h"
#include "../UserService/UserService.h"

class FriendshipService {
private:
    FriendshipValidator friendshipValidator;
    RepositoryCSV<Friendship> friendshipRepository;
    UserService userService;
public:
    /**
     * Constructor
     * @param friendshipRepository: repository
     */
    FriendshipService(RepositoryCSV<Friendship> &friendshipRepository, UserService &userService);

    /**
     * Create a Friendship object
     * @param id: friendship id
     * @param firstUserEmail: friendship first user email
     * @param secondUserEmail: friendship second user email
     * @param status: friendship status
     */
    void create(unsigned int id, std::string firstUserEmail, std::string secondUserEmail, std::string status);

    /**
     * Reads all friendships stored in repository
     * @return: all friendships stored in repository
     */
    List<Friendship> read();

    /**
     * Read friendship with given id
     * @param id: friendship id
     * @return: friendship with given id
     */
    Friendship read(unsigned int id);

    /**
     * Update a Friendship object
     * @param id: friendship id
     * @param newFirstUserEmail: new friendship first user email
     * @param newSecondUserEmail: new friendship second user email
     * @param newStatus: new friendship status
     */
    void update(unsigned int id, std::string newFirstUserEmail, std::string newSecondUserEmail, std::string newStatus);

    /**
     * Delete friendship
     * @param id: friendship id
     */
    void del(unsigned int id);

    /**
     * Checks if entity with given ID already exist
     * @param id: id
     * @return: true if exists, false otherwise
     */
    bool doesExistId(unsigned int id);

    /**
     * Checks if the receiver exists
     * @param secondUser: receiver
     * @return: true if exists, false otherwise
     */
    bool doesExistSecondUser(User secondUser);
};


#endif //USERREPOSITORYCSV_H_FRIENDSHIPSERVICE_H
