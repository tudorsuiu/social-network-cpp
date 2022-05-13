//
// Created by Tudor on 5/13/2022.
//

#ifndef USERREPOSITORYCSV_H_TESTMESSAGEREPOSITORY_H
#define USERREPOSITORYCSV_H_TESTMESSAGEREPOSITORY_H


#include <string>

class TestMessageRepository {
private:
    void clearFile(std::string fileName);
    void addMessage();
    void readMessage();
    void updateMessage();
    void deleteMessage();
    void getPosById();
public:
    void all();
};


#endif //USERREPOSITORYCSV_H_TESTMESSAGEREPOSITORY_H
