//
// Created by Tudor on 5/13/2022.
//

#include "EventService.h"
#include "../../Domain/MyException.h"

EventService::EventService(RepositoryCSV<Event> &eventRepository, UserService &userService) : eventRepository(eventRepository),
                                                                                              userService(userService){}

void EventService::create(Event event) {
    if(doesExistId(event.getId())) {
        throw MyException("An event with this ID already exists.");
    }
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

void EventService::update(unsigned int id, Event newEvent) {
    if(!doesExistId(id)) {
        throw MyException("Event with given ID was not found.");
    }
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
