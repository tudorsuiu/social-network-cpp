//
// Created by Tudor on 5/6/2022.
//

#include "Event.h"
#include "../../ADT/List/List.h"

Event::Event() {
    this->id = 0;
}

Event::Event(unsigned int id, User creator, std::string name, std::string date,
             std::string description) {
    this->id = id;
    this->creator = creator;
    this->name = name;
    this->date = date;
    this->description = description;
}

Event::Event(std::string line, char separator) {
    this->loadFromString(line, separator);
}

Event::Event(const Event &event) {
    this->id = event.id;
    this->creator = event.creator;
    this->name = event.name;
    this->date = event.date;
    this->description = event.description;
}

Event::~Event() = default;

unsigned int Event::getId() {
    return this->id;
}

void Event::setId(unsigned int id) {
    this->id = id;
}

User Event::getCreator() {
    return this->creator;
}

void Event::setCreator(User creator) {
    this->creator = creator;
}

std::string Event::getName() {
    return this->name;
}

void Event::setName(std::string name) {
    this->name = name;
}

std::string Event::getDate() {
    return this->date;
}

void Event::setDate(std::string date) {
    this->date = date;
}

std::string Event::getDescription() {
    return this->description;
}

void Event::setDescription(std::string description) {
    this->description = description;
}

std::string Event::toStringDelimiter(char separator) {
    return std::to_string(this->id) + separator + this->creator.toStringDelimiter(',') + separator + this->name + separator + this->date + separator + this->description;
}

void Event::loadFromString(std::string line, char separator) {
    List<std::string> events;
    std::stringstream ss(line);
    std::string eventInfo;
    while(getline(ss, eventInfo, separator)) {
        events.push_back(eventInfo);
    }
    if(events.size() == 11) {
        unsigned int userId, userAge;
        std::stringstream i(events[0]);
        i >> this->id;
        std::stringstream ui(events[1]);
        ui >> userId;
        this->creator.setId(userId);
        this->creator.setFirstName(events[2]);
        this->creator.setLastName(events[3]);
        std::stringstream up(events[4]);
        up >> userAge;
        this->creator.setAge(userAge);
        this->creator.setEmail(events[5]);
        this->creator.setPassword(events[6]);
        this->creator.setPhoneNumber(events[7]);
        this->name = events[8];
        this->date = events[9];
        this->description = events[10];
    }
}

Event &Event::operator=(const Event &event) {
    this->id = event.id;
    this->creator = event.creator;
    this->name = event.name;
    this->date = event.date;
    this->description = event.description;
    return *this;
}

bool Event::operator==(const Event &event) const {
    return this->id == event.id &&
    this->creator == event.creator &&
    this->name == event.name &&
    this->date == event.date &&
    this->description == event.description;
}

bool Event::operator!=(const Event &event) const {
    return !(*this == event);
}

std::istream &operator>>(std::istream &is, Event &event) {
    unsigned int id;
    std::cout << "Enter event id:"; is >> id;
    event.id = id;

    unsigned int creatorId;
    std::cout << "Enter creator id:"; is >> creatorId;
    event.creator.setId(creatorId);

    std::string creatorFirstName;
    std::cout << "Enter creator first name:"; is >> creatorFirstName;
    event.creator.setFirstName(creatorFirstName);

    std::string creatorLastName;
    std::cout << "Enter creator last name:"; is >> creatorLastName;
    event.creator.setLastName(creatorLastName);

    unsigned int creatorAge;
    std::cout << "Enter creator age:"; is >> creatorAge;
    event.creator.setAge(creatorAge);

    std::string creatorEmail;
    std::cout << "Enter creator email:"; is >> creatorEmail;
    event.creator.setEmail(creatorEmail);

    std::string creatorPassword;
    std::cout << "Enter creator password:"; is >> creatorPassword;
    event.creator.setPassword(creatorPassword);

    std::string creatorPhoneNumber;
    std::cout << "Enter creator phone number:"; is >> creatorPhoneNumber;
    event.creator.setPhoneNumber(creatorPhoneNumber);

    std::string name;
    std::cout << "Enter event name:"; is >> name;
    event.setName(name);

    std::string date;
    std::cout << "Enter event date:"; is >> date;
    event.setDate(date);

    std::string description;
    std::cout << "Enter event description:"; is >> description;
    event.setDescription(description);

    return is;
}

std::ostream &operator<<(std::ostream &os, Event &event) {
    os << "Event id: " << event.id << '\n' <<
    "Event creator: " << event.creator.getFirstName() << " " <<
    event.creator.getLastName() << '\n' <<
    "Event name: " << event.name << '\n' <<
    "Event date: " << event.date << '\n' <<
    "Event description: " << event.description << '\n';

    return os;
}
