//
// Created by Tudor on 5/13/2022.
//

#include "FriendshipService.h"
#include "../../Domain/MyException.h"

FriendshipService::FriendshipService(RepositoryCSV<Friendship> &friendshipRepository, UserService &userService) : friendshipRepository(friendshipRepository),
                                                                                        userService(userService) {}

void FriendshipService::create(unsigned int id, std::string firstUserEmail, std::string secondUserEmail, std::string status) {
    User firstUser = userService.getUserByEmail(firstUserEmail);
    User secondUser = userService.getUserByEmail(secondUserEmail);
    if(doesExistId(id)) {
        throw MyException("A friendship realtion with this ID already exists.");
    }
    else if(!doesExistSecondUser(secondUser)) {
        throw MyException("Friendship receiver doesn't have an account.");
    }
    Friendship friendship(id, firstUser, secondUser, status);
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

void FriendshipService::update(unsigned int id, std::string newFirstUserEmail, std::string newSecondUserEmail, std::string newStatus) {
    User newFirstUser = userService.getUserByEmail(newFirstUserEmail);
    User newSecondUser = userService.getUserByEmail(newSecondUserEmail);
    if(!doesExistId(id)) {
        throw MyException("Friendship relation with given ID was not found.");
    }
    else if(!doesExistSecondUser(newSecondUser)) {
        throw MyException("Friendship receiver doesn't have an account.");
    }
    Friendship newFriendship(id, newFirstUser, newSecondUser, newStatus);
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
