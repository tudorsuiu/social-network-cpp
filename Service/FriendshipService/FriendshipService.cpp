//
// Created by Tudor on 5/13/2022.
//

#include "FriendshipService.h"
#include "../../Domain/MyException.h"

FriendshipService::FriendshipService(RepositoryCSV<Friendship> &friendshipRepository, UserService &userService) : friendshipRepository(friendshipRepository),
                                                                                        userService(userService) {}

void FriendshipService::create(Friendship friendship) {
    if(doesExistId(friendship.getId())) {
        throw MyException("A friendship realtion with this ID already exists.");
    }
    else if(!doesExistSecondUser(friendship.getSecondUser())) {
        throw MyException("Friendship receiver doesn't have an account.");
    }
    friendshipValidator.validate(friendship);
    friendshipRepository.addEntity(friendship);
}

List<Friendship> FriendshipService::read() {
    if(friendshipRepository.readEntity().size() == 0) {
        throw MyException("There are no friendship relations.");
    }
    return friendshipRepository.readEntity();
}

Friendship FriendshipService::read(unsigned int id) {
    if(!doesExistId(id)) {
        throw MyException("Friendship relation with given ID was not found.");
    }
    return friendshipRepository.readEntity(id);
}

void FriendshipService::update(unsigned int id, Friendship newFriendship) {
    if(!doesExistId(id)) {
        throw MyException("Friendship relation with given ID was not found.");
    }
    else if(!doesExistSecondUser(newFriendship.getSecondUser())) {
        throw MyException("Friendship receiver doesn't habe an account.");
    }
    friendshipValidator.validate(newFriendship);
    friendshipRepository.updateEntity(id, newFriendship);
}

void FriendshipService::del(unsigned int id) {
    if(!doesExistId(id)) {
        throw MyException("Friendship relation with given ID was not found.");
    }
    friendshipRepository.deleteEntity(id);
}

bool FriendshipService::doesExistId(unsigned int id) {
    return friendshipRepository.getPosById(id) != -1;
}

bool FriendshipService::doesExistSecondUser(User secondUser) {
    for(int i = 0; i < userService.read().size(); i++) {
        if(userService.read()[i] == secondUser) {
            return true;
        }
    }
    return false;
}
