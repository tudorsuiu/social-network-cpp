//
// Created by Tudor on 5/5/2022.
//

#ifndef PROIECT_SDA_TESTUSERSERVICE_H
#define PROIECT_SDA_TESTUSERSERVICE_H


#include <string>

class TestUserService {
private:
    void clearFile(std::string fileName);
public:
    void createUser();
    void readUser();
    void updateUser();
    void deleteUser();
    void getPosById();
    void all();
};


#endif //PROIECT_SDA_TESTUSERSERVICE_H
