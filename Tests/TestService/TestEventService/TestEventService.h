//
// Created by Tudor on 5/21/2022.
//

#ifndef USERREPOSITORYCSV_H_TESTEVENTSERVICE_H
#define USERREPOSITORYCSV_H_TESTEVENTSERVICE_H


class TestEventService {
private:
    void clearfile(std::string fileName);
    void create();
    void read();
    void update();
    void del();
public:
    void all();
};


#endif //USERREPOSITORYCSV_H_TESTEVENTSERVICE_H
