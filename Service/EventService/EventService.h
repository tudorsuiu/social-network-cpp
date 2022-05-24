//
// Created by Tudor on 5/13/2022.
//

#ifndef USERREPOSITORYCSV_H_EVENTSERVICE_H
#define USERREPOSITORYCSV_H_EVENTSERVICE_H


#include "../../Domain/Entities/Event/Event.h"
#include "../../Domain/Validators/EventValidator/EventValidator.h"
#include "../UserService/UserService.h"
#include "../../Repository/BSTRepositoryCSV.h"

class EventService {
private:
    EventValidator eventValidator;
    BSTRepositoryCSV<Event> &eventRepository;
    UserService &userService;
public:
    /**
     * Constructor
     * @param eventRepository: repository
     * @param userService: user service
     */
    EventService(BSTRepositoryCSV<Event> &eventRepository, UserService &userService);

    /**
     * Last ID getter
     * @return: last ID from file
     */
    unsigned int getId();

    /**
     * Create event
     * @param creator: event creator
     * @param name: event name
     * @param date: event date
     * @param description: event description
     */
    void create(User creator, std::string name, std::string date, std::string description);

    /**
     * Reads all events stored in repository
     * @return: BST<Event> - all events stored in repository
     */
    BST<Event> read();

    /**
     * Read event with given id
     * @param id: event id
     * @return: event with given id
     */
    Event read(unsigned int id);

    /**
     * Update oldEvent with newEvent
     * @param oldEvent: old event
     * @param newEvent: new event
     */
    void update(Event oldEvent, Event newEvent);

    /**
     * Delete event
     * @param event: event to be deleted
     */
    void del(Event event);

    /**
     * Number of events
     * @return: number of events
     */
    unsigned int size();

    /**
     * Add every event into vector
     * @return: events in vector
     */
    std::vector<Event> getEventsInVector();

    /**
     * Shows all events created by given user
     * @param user: user
     * @return: all events created by given user
     */
    std::vector<Event> getEventsByUser(User user);
};


#endif //USERREPOSITORYCSV_H_EVENTSERVICE_H
