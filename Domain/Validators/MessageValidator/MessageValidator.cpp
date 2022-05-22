//
// Created by Tudor on 5/14/2022.
//

#include "MessageValidator.h"
#include "../../MyException.h"

void MessageValidator::validate(Message message) {
    if(message.getId() == 0 || message.getId() > INT_MAX) {
        throw MyException("Message ID must be positive.");
    }
    else if(message.getData().find(',') != std::string::npos) {
        throw MyException("Messages should not contain commas.");
    }
}
