//
// Created by Tudor on 5/13/2022.
//

#include <fstream>
#include <cassert>
#include "TestEventRepository.h"
#include "../../../Domain/Entities/Event/Event.h"
#include "../../../Repository/RepositoryCSV.h"

void TestEventRepository::clearFile(std::string fileName) {
    std::ofstream file(fileName);
}

void TestEventRepository::addEvent() {
    clearFile("testEventRepository.csv");
    RepositoryCSV<Event> repository("testEventRepository.csv");
    User creator(1, "Creator", "Test", 23, "creatortest@gmail.com", "cartof4", "40753123456");
    Event e1(1, creator, "Event name", "21/07/2002", "This is the description of the event1!");
    Event e2(2, creator, "Event name", "21/07/2002", "This is the description of the event2!");
    Event e3(3, creator, "Event name", "21/07/2002", "This is the description of the event3!");
    repository.addEntity(e1);
    repository.addEntity(e2);
    repository.addEntity(e3);
    assert(repository.readEntity(1) == e1);
    assert(repository.readEntity(2) == e2);
    assert(repository.readEntity(3) == e3);
}

void TestEventRepository::readEvent() {
    clearFile("testEventRepository.csv");
    RepositoryCSV<Event> repository("testEventRepository.csv");
    User creator(1, "Creator", "Test", 23, "creatortest@gmail.com", "cartof4", "40753123456");
    Event e1(1, creator, "Event name", "21/07/2002", "This is the description of the event1!");
    Event e2(2, creator, "Event name", "21/07/2002", "This is the description of the event2!");
    Event e3(3, creator, "Event name", "21/07/2002", "This is the description of the event3!");
    repository.addEntity(e1);
    repository.addEntity(e2);
    repository.addEntity(e3);
    assert(repository.readEntity(1) == e1);
    assert(repository.readEntity(2) == e2);
    assert(repository.readEntity(3) == e3);
}

void TestEventRepository::updateEvent() {
    clearFile("testEventRepository.csv");
    RepositoryCSV<Event> repository("testEventRepository.csv");
    User creator(1, "Creator", "Test", 23, "creatortest@gmail.com", "cartof4", "40753123456");
    Event e1(1, creator, "Event name", "21/07/2002", "This is the description of the event1!");
    Event e2(2, creator, "Event name", "21/07/2002", "This is the description of the event2!");
    Event e3(3, creator, "Event name", "21/07/2002", "This is the description of the event3!");
    repository.addEntity(e1);
    repository.addEntity(e2);
    repository.addEntity(e3);
    repository.updateEntity(3, Event(3, creator, "New event name", "21/09/2002", "This is the new description of the event3!"));
    assert(repository.readEntity(1) == e1);
    assert(repository.readEntity(2) == e2);
    assert(repository.readEntity(3) == Event(3, creator, "New event name", "21/09/2002", "This is the new description of the event3!"));
}

void TestEventRepository::deleteEvent() {
    clearFile("testEventRepository.csv");
    RepositoryCSV<Event> repository("testEventRepository.csv");
    User creator(1, "Creator", "Test", 23, "creatortest@gmail.com", "cartof4", "40753123456");
    Event e1(1, creator, "Event name", "21/07/2002", "This is the description of the event1!");
    Event e2(2, creator, "Event name", "21/07/2002", "This is the description of the event2!");
    Event e3(3, creator, "Event name", "21/07/2002", "This is the description of the event3!");
    repository.addEntity(e1);
    repository.addEntity(e2);
    repository.addEntity(e3);
    assert(repository.readEntity().size() == 3);
    repository.deleteEntity(1);
    repository.deleteEntity(2);
    repository.deleteEntity(3);
    assert(repository.readEntity().size() == 0);
}

void TestEventRepository::getPosById() {
    clearFile("testEventRepository.csv");
    RepositoryCSV<Event> repository("testEventRepository.csv");
    User creator(1, "Creator", "Test", 23, "creatortest@gmail.com", "cartof4", "40753123456");
    Event e1(1, creator, "Event name", "21/07/2002", "This is the description of the event1!");
    Event e2(2, creator, "Event name", "21/07/2002", "This is the description of the event2!");
    Event e3(3, creator, "Event name", "21/07/2002", "This is the description of the event3!");
    repository.addEntity(e1);
    repository.addEntity(e2);
    repository.addEntity(e3);
    assert(repository.getPosById(1) == 0);
    assert(repository.getPosById(2) == 1);
    assert(repository.getPosById(3) == 2);
}

void TestEventRepository::all() {
    addEvent();
    readEvent();
    updateEvent();
    deleteEvent();
    getPosById();
}
