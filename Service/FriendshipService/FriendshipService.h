//
// Created by Tudor on 5/13/2022.
//

#ifndef USERREPOSITORYCSV_H_FRIENDSHIPSERVICE_H
#define USERREPOSITORYCSV_H_FRIENDSHIPSERVICE_H


#include "../../Domain/Friendship/Friendship.h"
#include "../../Repository/RepositoryCSV.h"

class FriendshipService {
private:
    RepositoryCSV<Friendship> friendshipRepository;
public:
    /**
     * Constructor
     * @param friendshipRepository: repository
     */
    FriendshipService(RepositoryCSV<Friendship> &friendshipRepository);

    /**
     * Add friendship to repository
     * @param friendship: Friendship object
     */
    void create(Friendship friendship);

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
     * Update friendship
     * @param id: friendship id
     * @param newFriendship: updated friendship
     */
    void update(unsigned int id, Friendship newFriendship);

    /**
     * Delete friendship
     * @param id: friendship id
     */
    void del(unsigned int id);
};


#endif //USERREPOSITORYCSV_H_FRIENDSHIPSERVICE_H
