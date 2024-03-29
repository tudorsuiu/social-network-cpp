//
// Created by Tudor on 5/14/2022.
//

#include "FriendshipValidator.h"
#include "../../MyException.h"

void FriendshipValidator::validate(Friendship friendship) {
    if(friendship.getId() == 0 || friendship.getId() > INT_MAX) {
        throw MyException("Friendship ID must be positive.");
    }
}
