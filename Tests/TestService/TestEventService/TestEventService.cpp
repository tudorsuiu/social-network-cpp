//
// Created by Tudor on 5/21/2022.
//

#include <string>
#include <fstream>
#include <cassert>
#include "TestEventService.h"
#include "../../../Service/UserService/UserService.h"
#include "../../../Service/EventService/EventService.h"

void TestEventService::clearfile(std::string fileName) {
    std::ofstream file(fileName);
}

void TestEventService::create() {
    clearfile("testEventServiceUsers.csv");
    clearfile("testEventServiceEvents.csv");
    RepositoryCSV<User> userRepository("testEventServiceUsers.csv");
    BSTRepositoryCSV<Event> eventRepository("testEventServiceEvents.csv");
    UserService userService(userRepository);
    EventService eventService(eventRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    eventService.create(u1, "Concert", "24/02/2022", "Michael Jackson");
    eventService.create(u2, "Concert", "24/02/2022", "Eminem");
    assert(eventService.read(1) == Event(1, u1, "Concert", "24/02/2022", "Michael Jackson"));
    assert(eventService.read(2) == Event(2, u2, "Concert", "24/02/2022", "Eminem"));
}

void TestEventService::read() {
    clearfile("testEventServiceUsers.csv");
    clearfile("testEventServiceEvents.csv");
    RepositoryCSV<User> userRepository("testEventServiceUsers.csv");
    BSTRepositoryCSV<Event> eventRepository("testEventServiceEvents.csv");
    UserService userService(userRepository);
    EventService eventService(eventRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    eventService.create(u1, "Concert", "24/02/2022", "Michael Jackson");
    eventService.create(u2, "Concert", "24/02/2022", "Eminem");
    assert(eventService.read(1) == Event(1, u1, "Concert", "24/02/2022", "Michael Jackson"));
    assert(eventService.read(2) == Event(2, u2, "Concert", "24/02/2022", "Eminem"));
}

void TestEventService::update() {
    clearfile("testEventServiceUsers.csv");
    clearfile("testEventServiceEvents.csv");
    RepositoryCSV<User> userRepository("testEventServiceUsers.csv");
    BSTRepositoryCSV<Event> eventRepository("testEventServiceEvents.csv");
    UserService userService(userRepository);
    EventService eventService(eventRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    eventService.create(u1, "Concert", "24/02/2022", "Michael Jackson");
    eventService.create(u2, "Concert", "24/02/2022", "Eminem");
    eventService.update(Event(2, u2, "Concert", "24/02/2022", "Eminem"), Event(2, u1, "Concert", "24/02/2022", "Puya"));
    assert(eventService.read(1) == Event(1, u1, "Concert", "24/02/2022", "Michael Jackson"));
    assert(eventService.read(2) == Event(2, u1, "Concert", "24/02/2022", "Puya"));
}

void TestEventService::del() {
    clearfile("testEventServiceUsers.csv");
    clearfile("testEventServiceEvents.csv");
    RepositoryCSV<User> userRepository("testEventServiceUsers.csv");
    BSTRepositoryCSV<Event> eventRepository("testEventServiceEvents.csv");
    UserService userService(userRepository);
    EventService eventService(eventRepository, userService);
    User u1(1, "First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    User u2(2, "First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname1@domain.com", "parola123", "40712345678");
    userService.create("First name", "Last name", 18, "firstname.lastname2@domain.com", "parola123", "40712345678");
    eventService.create(u1, "Concert", "24/02/2022", "Michael Jackson");
    eventService.create(u2, "Concert", "24/02/2022", "Eminem");
    eventService.del(Event(1, u1, "Concert", "24/02/2022", "Michael Jackson"));
    eventService.del(Event(2, u2, "Concert", "24/02/2022", "Eminem"));
    assert(eventService.size() == 0);
}

void TestEventService::all() {
    create();
    read();
    update();
    del();
}
