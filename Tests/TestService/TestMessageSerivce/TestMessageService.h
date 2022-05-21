//
// Created by Tudor on 5/20/2022.
//

#ifndef USERREPOSITORYCSV_H_TESTMESSAGESERVICE_H
#define USERREPOSITORYCSV_H_TESTMESSAGESERVICE_H


class TestMessageService {
private:
    void clearFile(std::string fileName);
    void create();
    void read();
    void update();
    void del();
    void doesExistId();
    void getMessageByEmailsAndData();
    void getConversationWithUser();
public:
    void all();
};


#endif //USERREPOSITORYCSV_H_TESTMESSAGESERVICE_H
