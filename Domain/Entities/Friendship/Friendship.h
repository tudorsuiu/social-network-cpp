//
// Created by Tudor on 5/6/2022.
//

#ifndef PROIECT_SDA_FRIENDSHIP_H
#define PROIECT_SDA_FRIENDSHIP_H


#include "../User/User.h"

class Friendship {
private:
    unsigned int id;
    User firstUser;
    User secondUser;
public:
    /**
     * Constructor
     */
    Friendship();

    /**
     * Constructor with parameters
     * @param id: friendship id
     * @param firstPerson: person that creates the friendship
     * @param secondPerson: person that accepts/declines the friendship
     */
    Friendship(unsigned int id, User firstUser, User secondUser);

    /**
     * Constructor from file
     * @param line: string with friendship details
     * @param separator: separator
     */
    Friendship(std::string line, char separator);

    /**
     * Copy-constructor
     * @param friendship: Friendshgip object
     */
    Friendship(const Friendship &friendship);

    /**
     * Destructor
     */
    ~Friendship();

    /**
     * Id getter
     * @return: friendship id
     */
    unsigned int getId();

    /**
     * Id setter
     * @param id: new friendship id
     */
    void setId(unsigned int id);

    /**
     * First user getter
     * @return: friendship sender getter
     */
    User getFirstUser();

    /**
     * First user setter
     * @param firstUser: new friendship sender
     */
    void setFirstUser(User firstUser);

    /**
     * Second user getter
     * @return: friendship receiver
     */
    User getSecondUser();

    /**
     * Second user setter
     * @param secondUser: new friendship receiver
     */
    void setSecondUser(User secondUser);

    /**
     * To string delimiter
     * @param separator: separator
     * @return: Friendship object transformed into string
     */
    std::string toStringDelimiter(char separator);

    /**
     * Load Friendship from a string
     * @param line: given string
     * @param separator: separator
     */
    void loadFromstring(std::string line, char separator);

    Friendship& operator=(const Friendship& friendship);
    bool operator==(const Friendship& friendship) const;
    bool operator!=(const Friendship& friendship) const;

    friend std::istream &operator>>(std::istream& is, Friendship& friendship);
    friend std::ostream &operator<<(std::ostream& os, Friendship& friendship);
};


#endif //PROIECT_SDA_FRIENDSHIP_H
