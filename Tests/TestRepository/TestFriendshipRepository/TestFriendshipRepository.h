//
// Created by Tudor on 5/13/2022.
//

#ifndef USERREPOSITORYCSV_H_TESTFRIENDSHIPREPOSITORY_H
#define USERREPOSITORYCSV_H_TESTFRIENDSHIPREPOSITORY_H


#include <string>

class TestFriendshipRepository {
private:
    void clearFile(std::string fileName);
    void addFriendship();
    void readFriendship();
    void updateFriendship();
    void deleteFriendship();
    void getPosById();
public:
    void all();
};


#endif //USERREPOSITORYCSV_H_TESTFRIENDSHIPREPOSITORY_H
