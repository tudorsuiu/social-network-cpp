//
// Created by Tudor on 5/14/2022.
//

#include "UserValidator.h"
#include "../../MyException.h"

void UserValidator::validate(User user) {
    if(user.getId() == 0 || user.getId() > INT_MAX) {
        throw MyException("User ID must be positive.");
    }
    else if(user.getAge() < 18 || user.getAge() > 99) {
        throw MyException("The user must be at least 18 years old.");
    }
    else if(user.getEmail().size() < 10) {
        throw MyException("User email is invalid.");
    }
    else if(user.getPhoneNumber().size() != 11) {
        throw MyException("The user's phone number is invalid.");
    }
}
