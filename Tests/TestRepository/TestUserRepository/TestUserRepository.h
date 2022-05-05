//
// Created by Tudor on 5/5/2022.
//

#ifndef PROIECT_SDA_TESTUSERREPOSITORY_H
#define PROIECT_SDA_TESTUSERREPOSITORY_H

#include <string>

class TestUserRepository {
private:
    void clearFile(std::string fileName);
public:
    void addUser();
    void readUser();
    void updateUser();
    void deleteUser();
    void getPosById();
    void all();
};


#endif //PROIECT_SDA_TESTUSERREPOSITORY_H
