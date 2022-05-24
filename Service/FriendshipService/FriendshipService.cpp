//
// Created by Tudor on 5/13/2022.
//

#include "FriendshipService.h"
#include "../../Domain/MyException.h"

FriendshipService::FriendshipService(RepositoryCSV<Friendship> &friendshipRepository, UserService &userService) : friendshipRepository(friendshipRepository),
                                                                                                                  userService(userService) {}

unsigned int FriendshipService::getId() {
    if(friendshipRepository.readEntity().size() == 0) {
        return 1;
    }
    else {
        return friendshipRepository.readEntity()[friendshipRepository.readEntity().size() - 1].getId() + 1;
    }
}

void FriendshipService::create(User firstUser, User secondUser) {
    if(!doesExistSecondUser(secondUser)) {
        throw MyException("Friendship receiver doesn't have an account.");
    }
    else if(doesExistFriendshipRelation(firstUser, secondUser)) {
        throw MyException("Users are already friends.");
    }
    else if(firstUser == secondUser) {
        throw MyException("A friendship relation can't be created between the same users.");
    }
    Friendship friendship(getId(), firstUser, secondUser);
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

void FriendshipService::update(Friendship oldFriendship, Friendship newFriendship) {
    if(!doesExistId(oldFriendship.getId())) {
        throw MyException("Friendship relation with given ID was not found.");
    }
    else if(!doesExistSecondUser(newFriendship.getSecondUser())) {
        throw MyException("Friendship receiver doesn't have an account.");
    }
    else if(doesExistFriendshipRelation(newFriendship.getFirstUser(), newFriendship.getSecondUser())) {
        throw MyException("Users are already friends.");
    }
    else if(oldFriendship.getFirstUser() == newFriendship.getSecondUser()) {
        throw MyException("A friendship relation can't be created between the same users.");
    }
    friendshipValidator.validate(newFriendship);
    friendshipRepository.updateEntity(oldFriendship, newFriendship);
}

void FriendshipService::del(Friendship friendship) {
    if(!doesExistId(friendship.getId())) {
        throw MyException("Friendship relation with given ID was not found.");
    }
    friendshipRepository.deleteEntity(friendship);
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

unsigned int FriendshipService::getNumberOfFriendships() {
    return friendshipRepository.readEntity().size();
}

Friendship FriendshipService::getFriendshipByEmails(std::string firstUserEmail,
                                                    std::string secondUserEmail) {
    for(int i = 0; i < friendshipRepository.readEntity().size(); i++) {
        Friendship friendship = friendshipRepository.readEntity()[i];
        if(friendship.getFirstUser().getEmail() == firstUserEmail &&
        friendship.getSecondUser().getEmail() == secondUserEmail) {
            return friendship;
        }
    }
    throw MyException("Friendship relation between these users was not found.");
}

List<User> FriendshipService::getUserFriendList(User user) {
    List<User> result;
    for(int i = 0; i < friendshipRepository.readEntity().size(); i++) {
        if(friendshipRepository.readEntity()[i].getFirstUser() == user) {
            result.push_back(friendshipRepository.readEntity()[i].getSecondUser());
        }
        if(friendshipRepository.readEntity()[i].getSecondUser() == user) {
            result.push_back(friendshipRepository.readEntity()[i].getFirstUser());
        }
    }
    return result;
}

bool FriendshipService::doesExistFriendshipRelation(User firstUser,
                                                    User secondUser) {
    for(int i = 0; i < friendshipRepository.readEntity().size(); i++) {
        Friendship friendship = friendshipRepository.readEntity()[i];
        if(friendship.getFirstUser() == firstUser && friendship.getSecondUser() == secondUser || friendship.getSecondUser() == firstUser && friendship.getFirstUser() == secondUser) {
            return true;
        }
    }
    return false;
}
