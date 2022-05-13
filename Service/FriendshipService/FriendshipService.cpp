//
// Created by Tudor on 5/13/2022.
//

#include "FriendshipService.h"

FriendshipService::FriendshipService(RepositoryCSV<Friendship> &friendshipRepository) : friendshipRepository(friendshipRepository) {}

void FriendshipService::create(Friendship friendship) {
    friendshipRepository.addEntity(friendship);
}

List<Friendship> FriendshipService::read() {
    return friendshipRepository.readEntity();
}

Friendship FriendshipService::read(unsigned int id) {
    return friendshipRepository.readEntity(id);
}

void FriendshipService::update(unsigned int id, Friendship newFriendship) {
    friendshipRepository.updateEntity(id, newFriendship);
}

void FriendshipService::del(unsigned int id) {
    friendshipRepository.deleteEntity(id);
}
