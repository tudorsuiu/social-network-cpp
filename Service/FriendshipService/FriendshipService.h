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

    unsigned int getId();

    /**
     * Create a Friendship object
     * @param id: friendship id
     * @param firstUserEmail: friendship first user email
     * @param secondUserEmail: friendship second user email
     */
    void create(User firstUser, User secondUser);

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
     */
    void update(Friendship oldFriendship, Friendship newFriendship);

    /**
     * Delete friendship
     * @param id: friendship id
     */
    void del(Friendship friendship);

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

    Friendship getFriendshipByEmails(std::string firstUserEmail, std::string secondUserEmail);

    List<User> getUserFriendList(User user);
};


#endif //USERREPOSITORYCSV_H_FRIENDSHIPSERVICE_H
