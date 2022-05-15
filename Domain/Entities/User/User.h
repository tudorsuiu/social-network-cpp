//
// Created by Tudor on 5/4/2022.
//

#ifndef PROIECT_SDA_USER_H
#define PROIECT_SDA_USER_H


#include <string>
#include <sstream>

class User {
private:
    unsigned int id;
    std::string firstName;
    std::string lastName;
    unsigned int age;
    std::string email;
    std::string password;
    std::string phoneNumber;
public:
    /**
     * Constructor
     */
    User();

    /**
     * Constructor with parameters
     * @param id: user id
     * @param firstName: user first name
     * @param lastName: user last name
     * @param age: user age
     * @param email: user email
     * @param password: user password
     * @param phoneNumber: user phone number
     */
    User(unsigned int id, std::string firstName, std::string lastName, unsigned int age, std::string email, std::string password, std::string phoneNumber);

    /**
     * Constructor from file
     * @param line: string with user details
     * @param separator: separator
     */
    User(std::string line, char separator);

    /**
     * Copy-constructor
     * @param user: User object
     */
    User(const User &user);

    /**
     * Destructor
     */
    ~User();

    /**
     * Id getter
     * @return: user id
     */
    unsigned int getId();

    /**
     * Id setter
     * @param id: new user id
     */
    void setId(unsigned int id);

    /**
     * First name getter
     * @return: user first name
     */
    std::string getFirstName();

    /**
     * First name setter
     * @param firstName: new user first name
     */
    void setFirstName(std::string firstName);

    /**
     * Last name getter
     * @return: user last name
     */
    std::string getLastName();

    /**
     * Last name setter
     * @param lastName: new user last name
     */
    void setLastName(std::string lastName);

    /**
     * Age getter
     * @return: user age
     */
    unsigned int getAge();

    /**
     * Age setter
     * @param age: new user age
     */
    void setAge(unsigned int age);

    /**
     * Email getter
     * @return: user email
     */
    std::string getEmail();

    /**
     * Email setter
     * @param email: new user email
     */
    void setEmail(std::string email);

    /**
     * Password getter
     * @return: user password
     */
    std::string getPassword();

    /**
     * Password setter
     * @param password: new user password
     */
    void setPassword(std::string password);

    /**
     * Phone number getter
     * @return: user phone number
     */
    std::string getPhoneNumber();

    /**
     * Phone number setter
     * @param phoneNumber: new user phone number
     */
    void setPhoneNumber(std::string phoneNumber);

    /**
     * Checks password for log in
     * @param password: inserted password
     * @return: true if passwords are equal, false otherwise
     */
    bool verifyPassword(std::string password);

    /**
     * To string delimiter
     * @param separator: separator
     * @return: User object transformed into string
     */
    std::string toStringDelimiter(char separator);

    /**
     * Load User from a string
     * @param line: given string
     * @param separator: separator
     */
    void loadFromString(std::string line, char separator);

    User& operator=(const User& user);
    bool operator<(const User& user) const;
    bool operator>(const User& user) const;
    bool operator<=(const User& user) const;
    bool operator>=(const User& user) const;
    bool operator==(const User& user) const;
    bool operator!=(const User& user) const;

    friend std::istream &operator>>(std::istream& is, User& user);
    friend std::ostream &operator<<(std::ostream& os, User& user);
};


#endif //PROIECT_SDA_USER_H
