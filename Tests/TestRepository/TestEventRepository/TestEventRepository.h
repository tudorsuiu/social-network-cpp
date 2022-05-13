//
// Created by Tudor on 5/13/2022.
//

#ifndef USERREPOSITORYCSV_H_TESTEVENTREPOSITORY_H
#define USERREPOSITORYCSV_H_TESTEVENTREPOSITORY_H


class TestEventRepository {
private:
    void clearFile(std::string fileName);
    void addEvent();
    void readEvent();
    void updateEvent();
    void deleteEvent();
    void getPosById();
public:
    void all();
};


#endif //USERREPOSITORYCSV_H_TESTEVENTREPOSITORY_H
