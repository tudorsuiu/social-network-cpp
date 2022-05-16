//
// Created by Tudor on 5/13/2022.
//

#ifndef USERREPOSITORYCSV_H_EVENTSERVICE_H
#define USERREPOSITORYCSV_H_EVENTSERVICE_H


#include "../../Domain/Entities/Event/Event.h"
#include "../../Repository/RepositoryCSV.h"
#include "../../Domain/Validators/EventValidator/EventValidator.h"
#include "../UserService/UserService.h"

class EventService {
private:
    EventValidator eventValidator;
    RepositoryCSV<Event> eventRepository;
    UserService userService;
public:
    /**
     * Constructor
     * @param eventRepository: repository
     */
    EventService(RepositoryCSV<Event> &eventRepository, UserService &userService);

    /**
     * Add event to repository
     * @param event: Event object
     */
    void create(unsigned int id, std::string creatorEmail, std::string name, std::string date, std::string description);

    /**
     * Reads all events stored in repository
     * @return: all events stored in repository
     */
     List<Event> read();

     /**
      * Read event with given id
      * @param id: event id
      * @return: event with given id
      */
     Event read(unsigned int id);

     /**
      * Update event
      * @param id: Event id
      * @param newEvent: updated event
      */
     void update(unsigned int id, std::string newCreatorEmail, std::string newName, std::string newDate, std::string newDescription);

     /**
      * Delete event
      * @param id: event id
      */
     void del(unsigned int id);

     /**
      * Checks if entity with given ID exist
      * @param id: id
      * @return: true if exists, false otherwise
      */
     bool doesExistId(unsigned int id);
};


#endif //USERREPOSITORYCSV_H_EVENTSERVICE_H
