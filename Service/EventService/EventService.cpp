//
// Created by Tudor on 5/13/2022.
//

#include "EventService.h"

EventService::EventService(RepositoryCSV<Event> &eventRepository) : eventRepository(eventRepository) {}

void EventService::create(Event event) {
    eventRepository.addEntity(event);
}

List<Event> EventService::read() {
    return eventRepository.readEntity();
}

Event EventService::read(unsigned int id) {
    return eventRepository.readEntity(id);
}

void EventService::update(unsigned int id, Event newEvent) {
    eventRepository.updateEntity(id, newEvent);
}

void EventService::del(unsigned int id) {
    eventRepository.deleteEntity(id);
}
