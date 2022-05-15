//
// Created by Tudor on 5/14/2022.
//

#ifndef USERREPOSITORYCSV_H_MYEXCEPTION_H
#define USERREPOSITORYCSV_H_MYEXCEPTION_H

#include <exception>

class MyException : public std::exception {
private:
    const char *message;
public:
    /**
     * Constructor
     * @param message: exception message
     */
    MyException(const char *message) : message(message) {}

    /**
     * Getter for exception message
     * @return: exception message
     */
    const char *what() const noexcept override {
        return message;
    }
};


#endif //USERREPOSITORYCSV_H_MYEXCEPTION_H
