//
// Created by Tudor on 5/6/2022.
//

#ifndef PROIECT_SDA_EVENT_H
#define PROIECT_SDA_EVENT_H


#include <string>
#include "../User/User.h"

class Event {
private:
    unsigned int id;
    User creator;
    std::string name;
    std::string date;
    std::string description;
public:
    /**
     * Constructor
     */
    Event();

    /**
     * Constructor with parameters
     * @param id: event id
     * @param creator: event creator
     * @param name: event name
     * @param date: event date
     * @param description: event description
     */
    Event(unsigned int id, User creator, std::string name, std::string date, std::string description);

    /**
     * Constructor from file
     * @param line: string with event details
     * @param separator: separator
     */
    Event(std::string line, char separator);

    /**
     * Copy-constructor
     * @param event: Event object
     */
    Event(const Event &event);

    /**
     * Destructor
     */
    ~Event();

    /**
     * Id getter
     * @return: event id
     */
    unsigned int getId();

    /**
     * Id setter
     * @param id: new event id
     */
    void setId(unsigned int id);

    /**
     * Creator getter
     * @return: event creator
     */
    User getCreator();

    /**
     * Creator setter
     * @param creator: new event creator
     */
    void setCreator(User creator);

    /**
     * Name getter
     * @return: event name
     */
    std::string getName();

    /**
     * Name setter
     * @param name: new event name
     */
    void setName(std::string name);

    /**
     * Date getter
     * @return: event date
     */
    std::string getDate();

    /**
     * Date setter
     * @param date: new event date
     */
    void setDate(std::string date);

    /**
     * Description getter
     * @return: event description
     */
    std::string getDescription();

    /**
     * Description setter
     * @param description: new event description
     */
    void setDescription(std::string description);

    /**
     * To string delimiter
     * @param separator: separator
     * @return: Event object transformed into string
     */
    std::string toStringDelimiter(char separator);

    /**
     * Load Event from a string
     * @param line: given string
     * @param separator: separator
     */
    void loadFromString(std::string line, char separator);

    Event& operator=(const Event& event);
    bool operator==(const Event& event) const;
    bool operator!=(const Event& event) const;

    friend std::istream &operator>>(std::istream& is, Event& event);
    friend std::ostream &operator<<(std::ostream& os, Event& event);
};


#endif //PROIECT_SDA_EVENT_H
