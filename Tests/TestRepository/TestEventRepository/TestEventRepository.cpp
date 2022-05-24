//
// Created by Tudor on 5/13/2022.
//

#include <fstream>
#include <cassert>
#include "TestEventRepository.h"
#include "../../../Domain/Entities/Event/Event.h"
#include "../../../Repository/BSTRepositoryCSV.h"

void TestEventRepository::clearFile(std::string fileName) {
    std::ofstream file(fileName);
}

void TestEventRepository::addEvent() {
    clearFile("testEventRepository.csv");
    BSTRepositoryCSV<Event> repository("testEventRepository.csv");
    User creator(1, "Creator", "Test", 23, "creatortest@gmail.com", "cartof4", "40753123456");
    Event e1(1, creator, "Event name", "21/07/2002", "This is the description of the event1!");
    Event e2(2, creator, "Event name", "21/07/2002", "This is the description of the event2!");
    Event e3(3, creator, "Event name", "21/07/2002", "This is the description of the event3!");
    repository.addEntity(e1);
    repository.addEntity(e2);
    repository.addEntity(e3);
    assert(repository.read(1) == e1);
    assert(repository.read(2) == e2);
    assert(repository.read(3) == e3);
}

void TestEventRepository::readEvent() {
    clearFile("testEventRepository.csv");
    BSTRepositoryCSV<Event> repository("testEventRepository.csv");
    User creator(1, "Creator", "Test", 23, "creatortest@gmail.com", "cartof4", "40753123456");
    Event e1(1, creator, "Event name", "21/07/2002", "This is the description of the event1!");
    Event e2(2, creator, "Event name", "21/07/2002", "This is the description of the event2!");
    Event e3(3, creator, "Event name", "21/07/2002", "This is the description of the event3!");
    repository.addEntity(e1);
    repository.addEntity(e2);
    repository.addEntity(e3);
    assert(repository.read(1) == e1);
    assert(repository.read(2) == e2);
    assert(repository.read(3) == e3);
}

void TestEventRepository::updateEvent() {
    clearFile("testEventRepository.csv");
    BSTRepositoryCSV<Event> repository("testEventRepository.csv");
    User creator(1, "Creator", "Test", 23, "creatortest@gmail.com", "cartof4", "40753123456");
    Event e1(1, creator, "Event name", "21/07/2002", "This is the description of the event1!");
    Event e2(2, creator, "Event name", "21/07/2002", "This is the description of the event2!");
    Event e3(3, creator, "Event name", "21/07/2002", "This is the description of the event3!");
    repository.addEntity(e1);
    repository.addEntity(e2);
    repository.addEntity(e3);
    repository.updateEntity(e3, Event(3, creator, "New event name", "21/09/2002", "This is the new description of the event3!"));
    assert(repository.read(1) == e1);
    assert(repository.read(2) == e2);
    assert(repository.read(3) == Event(3, creator, "New event name", "21/09/2002", "This is the new description of the event3!"));
}

void TestEventRepository::deleteEvent() {
    clearFile("testEventRepository.csv");
    BSTRepositoryCSV<Event> repository("testEventRepository.csv");
    User creator(1, "Creator", "Test", 23, "creatortest@gmail.com", "cartof4", "40753123456");
    Event e1(1, creator, "Event name", "21/07/2002", "This is the description of the event1!");
    Event e2(2, creator, "Event name", "21/07/2002", "This is the description of the event2!");
    Event e3(3, creator, "Event name", "21/07/2002", "This is the description of the event3!");
    repository.addEntity(e1);
    repository.addEntity(e2);
    repository.addEntity(e3);
    repository.deleteEntity(e1);
    repository.deleteEntity(e2);
    repository.deleteEntity(e3);
    assert(repository.empty());
}

void TestEventRepository::all() {
    addEvent();
    readEvent();
    updateEvent();
    deleteEvent();
}
