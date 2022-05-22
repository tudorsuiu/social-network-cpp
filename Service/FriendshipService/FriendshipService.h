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
    RepositoryCSV<Friendship> &friendshipRepository;
    UserService &userService;
public:
    /**
     * Constructor
     * @param friendshipRepository: repository
     */
    FriendshipService(RepositoryCSV<Friendship> &friendshipRepository, UserService &userService);

    /**
     * Last ID getter
     * @return: last ID from file
     */
    unsigned int getId();

    /**
     * Create friendship relation
     * @param firstUser: first user
     * @param secondUser: second user
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
     * Update oldFriendship with newFriendship
     * @param oldFriendship: old friendship relation
     * @param newFriendship: new friendship relation
     */
    void update(Friendship oldFriendship, Friendship newFriendship);

    /**
     * Delete friendship
     * @param friendship: friendship to be deleted
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

    /**
     * Getter for number o friendship relations
     * @return: number of friendship relations
     */
    unsigned int getNumberOfFriendships();

    /**
     * Get friendship relation by emails
     * @param firstUserEmail: first user email
     * @param secondUserEmail: last user email
     * @return: friendship relation by given emails
     */
    Friendship getFriendshipByEmails(std::string firstUserEmail, std::string secondUserEmail);

    /**
     * Get user friend list
     * @param user: user
     * @return: friend list for given user
     */
    List<User> getUserFriendList(User user);

    /**
     * Checks if friendship relation between two users exist
     * @param firstUser: first user
     * @param secondUser: second user
     * @return: true if friendship relation exist, false otherwise
     */
    bool doesExistFriendshipRelation(User firstUser, User secondUser);
};


#endif //USERREPOSITORYCSV_H_FRIENDSHIPSERVICE_H
