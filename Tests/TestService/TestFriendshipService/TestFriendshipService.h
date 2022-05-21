//
// Created by Tudor on 5/21/2022.
//

#ifndef USERREPOSITORYCSV_H_TESTFRIENDSHIPSERVICE_H
#define USERREPOSITORYCSV_H_TESTFRIENDSHIPSERVICE_H


class TestFriendshipService {
private:
    void clearFile(std::string fileName);
    void create();
    void read();
    void update();
    void del();
    void doesExistId();
    void doesExistSecondUser();
    void getFriendshipByEmails();
    void getUserFriendList();
public:
    void all();

};


#endif //USERREPOSITORYCSV_H_TESTFRIENDSHIPSERVICE_H
