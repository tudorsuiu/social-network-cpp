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
    BSTRepositoryCSV<Event> eventRepository;
    UserService userService;
    unsigned int id = 1;
public:
    /**
     * Constructor
     * @param eventRepository: repository
     * @param userService: user service
     */
    EventService(BSTRepositoryCSV<Event> &eventRepository, UserService &userService);

    void create(User creator, std::string name, std::string date, std::string description);

    /**
     * Reads all events stored in repository
     * @return: all events stored in repository
     */
    BST<Event> read();

    /**
     * Read event with given id
     * @param id: event id
     * @return: event with given id
     */
    Event read(unsigned int id);

    /**
     * Updates an Event object
     * @param id: event id
     * @param newCreatorEmail: new event creator email
     * @param newName: new event name
     * @param newDate: new event date
     * @param newDescription: new event description
     */
    void update(Event oldEvent, Event newEvent);


    /**
     * Delete event
     * @param event: event to be deleted
     */
    void del(Event event);

    /**
     * Checks if entity with given ID exist
     * @param id: id
     * @return: true if exists, false otherwise
     */
    bool doesExistId(unsigned int id);
};


#endif //USERREPOSITORYCSV_H_EVENTSERVICE_H
