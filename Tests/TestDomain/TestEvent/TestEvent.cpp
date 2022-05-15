//
// Created by Tudor on 5/13/2022.
//

#include <cassert>
#include "TestEvent.h"
#include "../../../Domain/Entities/Event/Event.h"

void TestEvent::constructor() {
    Event event;
    User user;
    assert(event.getId() == 0);
    assert(event.getCreator() == user);
    assert(event.getName().empty() == true);
    assert(event.getDate().empty() == true);
    assert(event.getDescription().empty() == true);
}

void TestEvent::copyConstructor() {
    User creator(1, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    Event event(1, creator, "Event name", "24/02/2002", "This is the event description!");
    Event copyEvent = event;
    assert(copyEvent.getId() == 1);
    assert(copyEvent.getCreator() == creator);
    assert(copyEvent.getName() == "Event name");
    assert(copyEvent.getDate() == "24/02/2002");
    assert(copyEvent.getDescription() == "This is the event description!");
}

void TestEvent::lineConstructor() {
    Event event("1,1,Event,Creator,19,eventcreator@gmail.com,cartof4,40753123456,Event name,24/02/2002,This is the event description!", ',');
    User creator(1,"Event","Creator",19,"eventcreator@gmail.com","cartof4","40753123456");
    assert(event.getId() == 1);
    assert(event.getCreator() == creator);
    assert(event.getName() == "Event name");
    assert(event.getDate() == "24/02/2002");
    assert(event.getDescription() == "This is the event description!");
}

void TestEvent::parametersConstructor() {
    User creator(1, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    Event event(1, creator, "Event name", "24/02/2002", "This is the event description!");
    assert(event.getId() == 1);
    assert(event.getCreator() == creator);
    assert(event.getName() == "Event name");
    assert(event.getDate() == "24/02/2002");
    assert(event.getDescription() == "This is the event description!");
}

void TestEvent::getId() {
    User creator(1, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    Event event(1, creator, "Event name", "24/02/2002", "This is the event description!");
    assert(event.getId() == 1);
}

void TestEvent::setId() {
    User creator(1, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    Event event(1, creator, "Event name", "24/02/2002", "This is the event description!");
    event.setId(2);
    assert(event.getId() == 2);
}

void TestEvent::getCreator() {
    User creator(1, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    Event event(1, creator, "Event name", "24/02/2002", "This is the event description!");
    assert(event.getCreator() == creator);
}

void TestEvent::setCreator() {
    User creator(1, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    Event event(1, creator, "Event name", "24/02/2002", "This is the event description!");
    User newCreator(2, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    event.setCreator(newCreator);
    assert(event.getCreator() == newCreator);
}

void TestEvent::getName() {
    User creator(1, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    Event event(1, creator, "Event name", "24/02/2002", "This is the event description!");
    assert(event.getName() == "Event name");
}

void TestEvent::setName() {
    User creator(1, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    Event event(1, creator, "Event name", "24/02/2002", "This is the event description!");
    event.setName("New event name");
    assert(event.getName() == "New event name");
}

void TestEvent::getDate() {
    User creator(1, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    Event event(1, creator, "Event name", "24/02/2002", "This is the event description!");
    assert(event.getDate() == "24/02/2002");
}

void TestEvent::setDate() {
    User creator(1, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    Event event(1, creator, "Event name", "24/02/2002", "This is the event description!");
    event.setDate("01/12/2012");
    assert(event.getDate() == "01/12/2012");
}

void TestEvent::getDescription() {
    User creator(1, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    Event event(1, creator, "Event name", "24/02/2002", "This is the event description!");
    assert(event.getDescription() == "This is the event description!");
}

void TestEvent::setDescription() {
    User creator(1, "Event", "Creator", 19, "creatortest@gmail.com", "cartof4", "40753123456");
    Event event(1, creator, "Event name", "24/02/2002", "This is the event description!");
    event.setDescription("This is the new event description!");
    assert(event.getDescription() == "This is the new event description!");
}

void TestEvent::all() {
    constructor();
    copyConstructor();
    lineConstructor();
    parametersConstructor();
    getId();
    setId();
    getCreator();
    setCreator();
    getName();
    setName();
    getDate();
    setDate();
    getDescription();
    setDescription();
}
