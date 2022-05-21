//
// Created by Tudor on 5/13/2022.
//

#include "EventService.h"
#include "../../Domain/MyException.h"

EventService::EventService(BSTRepositoryCSV<Event> &eventRepository, UserService &userService) : eventRepository(eventRepository),
                                                                                              userService(userService){}

void EventService::create(User creator, std::string name, std::string date, std::string description) {
    Event event(this->id, creator, name, date, description);
    eventValidator.validate(event);
    eventRepository.addEntity(event);
    this->id++;
}

BST<Event> EventService::read() {
   if(eventRepository.empty()) {
       throw MyException("There are no events.");
   }
   return eventRepository.read();
}

Event EventService::read(unsigned int id) {
    return eventRepository.readEntity(id);
}

void EventService::update(Event oldEvent, Event newEvent) {
    eventValidator.validate(newEvent);
    eventRepository.updateEntity(oldEvent, newEvent);
}

void EventService::del(Event event) {
    eventRepository.deleteEntity(event);
}
