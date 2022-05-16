//
// Created by Tudor on 5/13/2022.
//

#include "EventService.h"
#include "../../Domain/MyException.h"

EventService::EventService(RepositoryCSV<Event> &eventRepository, UserService &userService) : eventRepository(eventRepository),
                                                                                              userService(userService){}

void EventService::create(unsigned int id, std::string creatorEmail, std::string name, std::string date, std::string description) {
    User creator = userService.getUserByEmail(creatorEmail);
    if(doesExistId(id)) {
        throw MyException("An event with this ID already exists.");
    }
    Event event(id, creator, name, date, description);
    eventValidator.validate(event);
    eventRepository.addEntity(event);
}

List<Event> EventService::read() {
    if(eventRepository.readEntity().size() == 0) {
        throw MyException("There are no events.");
    }
    return eventRepository.readEntity();
}

Event EventService::read(unsigned int id) {
    if(!doesExistId(id)) {
        throw MyException("Event with given ID was not found.");
    }
    return eventRepository.readEntity(id);
}

void EventService::update(unsigned int id, std::string newCreatorEmail, std::string newName, std::string newDate, std::string newDescription) {
    User newCreator = userService.getUserByEmail(newCreatorEmail);
    if(!doesExistId(id)) {
        throw MyException("Event with given ID was not found.");
    }
    Event newEvent(id, newCreator, newName, newDate, newDescription);
    eventValidator.validate(newEvent);
    eventRepository.updateEntity(id, newEvent);
}

void EventService::del(unsigned int id) {
    if(!doesExistId(id)) {
        throw MyException("Event with given ID was not found.");
    }
    eventRepository.deleteEntity(id);
}

bool EventService::doesExistId(unsigned int id) {
    return eventRepository.getPosById(id) != -1;
}
