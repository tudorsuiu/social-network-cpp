//
// Created by Tudor on 5/14/2022.
//

#include "EventValidator.h"
#include "../../MyException.h"

void EventValidator::validate(Event event) {
    if(event.getId() == 0 || event.getId() > INT_MAX) {
        throw MyException("Event ID must be positive.");
    }
    else if(event.getName().empty() == true) {
        throw MyException("Event name can't be empty.");
    }
    else if(event.getDate().size() != 10) {
        throw MyException("Event date isn't correct.");
    }
    else if(event.getDescription().find(',') != std::string::npos) {
        throw MyException("Event description shouldn't contain commas.");
    }
}
