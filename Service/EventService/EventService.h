//
// Created by Tudor on 5/13/2022.
//

#ifndef USERREPOSITORYCSV_H_EVENTSERVICE_H
#define USERREPOSITORYCSV_H_EVENTSERVICE_H


#include "../../Domain/Event/Event.h"
#include "../../Repository/RepositoryCSV.h"

class EventService {
private:
    RepositoryCSV<Event> eventRepository;
public:
    /**
     * Constructor
     * @param eventRepository: repository
     */
    EventService(RepositoryCSV<Event> &eventRepository);

    /**
     * Add event to repository
     * @param event: Event object
     */
    void create(Event event);

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
     void update(unsigned int id, Event newEvent);

     /**
      * Delete event
      * @param id: event id
      */
     void del(unsigned int id);
};


#endif //USERREPOSITORYCSV_H_EVENTSERVICE_H
