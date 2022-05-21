//
// Created by Tudor on 5/13/2022.
//

#include "TestFriendshipRepository.h"
#include <fstream>
#include <cassert>
#include "../../../Domain/Entities/User/User.h"
#include "../../../Domain/Entities/Friendship/Friendship.h"
#include "../../../Repository/RepositoryCSV.h"

void TestFriendshipRepository::clearFile(std::string fileName) {
    std::ofstream file(fileName);
}

void TestFriendshipRepository::addFriendship() {
    clearFile("testFriendshipRepository.csv");
    RepositoryCSV<Friendship> repository("testFriendshipRepository.csv");
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123451");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123452");
    User third(3, "Third", "Fourth", 19, "thirdfourth@gmail.com", "cartof4", "40753123453");
    User fourth(4, "Fourth", "Third", 19, "fourththird@gmail.com", "cartof4", "40753123454");
    User fifth(5, "Fifth", "Sixth", 19, "fifthsixth@gmail.com", "cartof4", "40753123455");
    User sixth(6, "Sixth", "Fifth", 19, "sixthfifth@gmail.com", "cartof4", "40753123456");
    Friendship f1(1,first, second);
    Friendship f2(2,third, fourth);
    Friendship f3(3,fifth, sixth);
    repository.addEntity(f1);
    repository.addEntity(f2);
    repository.addEntity(f3);
    assert(repository.readEntity(1) == f1);
    assert(repository.readEntity(2) == f2);
    assert(repository.readEntity(3) == f3);
}

void TestFriendshipRepository::readFriendship() {
    clearFile("testFriendshipRepository.csv");
    RepositoryCSV<Friendship> repository("testFriendshipRepository.csv");
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123451");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123452");
    User third(3, "Third", "Fourth", 19, "thirdfourth@gmail.com", "cartof4", "40753123453");
    User fourth(4, "Fourth", "Third", 19, "fourththird@gmail.com", "cartof4", "40753123454");
    User fifth(5, "Fifth", "Sixth", 19, "fifthsixth@gmail.com", "cartof4", "40753123455");
    User sixth(6, "Sixth", "Fifth", 19, "sixthfifth@gmail.com", "cartof4", "40753123456");
    Friendship f1(1,first, second);
    Friendship f2(2,third, fourth);
    Friendship f3(3,fifth, sixth);
    repository.addEntity(f1);
    repository.addEntity(f2);
    repository.addEntity(f3);
    assert(repository.readEntity(1) == f1);
    assert(repository.readEntity(2) == f2);
    assert(repository.readEntity(3) == f3);
}

void TestFriendshipRepository::updateFriendship() {
    clearFile("testFriendshipRepository.csv");
    RepositoryCSV<Friendship> repository("testFriendshipRepository.csv");
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123451");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123452");
    User third(3, "Third", "Fourth", 19, "thirdfourth@gmail.com", "cartof4", "40753123453");
    User fourth(4, "Fourth", "Third", 19, "fourththird@gmail.com", "cartof4", "40753123454");
    User fifth(5, "Fifth", "Sixth", 19, "fifthsixth@gmail.com", "cartof4", "40753123455");
    User sixth(6, "Sixth", "Fifth", 19, "sixthfifth@gmail.com", "cartof4", "40753123456");
    Friendship f1(1,first, second);
    Friendship f2(2,third, fourth);
    Friendship f3(3,fifth, sixth);
    repository.addEntity(f1);
    repository.addEntity(f2);
    repository.addEntity(f3);
    repository.updateEntity(f1,Friendship(1,first,second));
    repository.updateEntity(f2,Friendship(2,third,fourth));
    repository.updateEntity(f3,Friendship(3,fifth,sixth));
    assert(repository.readEntity(1) == Friendship(1,first,second));
    assert(repository.readEntity(2) == Friendship(2,third,fourth));
    assert(repository.readEntity(3) == Friendship(3,fifth,sixth));
}

void TestFriendshipRepository::deleteFriendship() {
    clearFile("testFriendshipRepository.csv");
    RepositoryCSV<Friendship> repository("testFriendshipRepository.csv");
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123451");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123452");
    User third(3, "Third", "Fourth", 19, "thirdfourth@gmail.com", "cartof4", "40753123453");
    User fourth(4, "Fourth", "Third", 19, "fourththird@gmail.com", "cartof4", "40753123454");
    User fifth(5, "Fifth", "Sixth", 19, "fifthsixth@gmail.com", "cartof4", "40753123455");
    User sixth(6, "Sixth", "Fifth", 19, "sixthfifth@gmail.com", "cartof4", "40753123456");
    Friendship f1(1,first, second);
    Friendship f2(2,third, fourth);
    Friendship f3(3,fifth, sixth);
    repository.addEntity(f1);
    repository.addEntity(f2);
    repository.addEntity(f3);
    assert(repository.readEntity().size() == 3);
    repository.deleteEntity(f1);
    repository.deleteEntity(f2);
    repository.deleteEntity(f3);
    assert(repository.readEntity().size() == 0);
}

void TestFriendshipRepository::getPosById() {
    clearFile("testFriendshipRepository.csv");
    RepositoryCSV<Friendship> repository("testFriendshipRepository.csv");
    User first(1, "First", "Last", 19, "firstlast@gmail.com", "cartof4", "40753123451");
    User second(2, "Last", "First", 19, "lastfirst@gmail.com", "cartof4", "40753123452");
    User third(3, "Third", "Fourth", 19, "thirdfourth@gmail.com", "cartof4", "40753123453");
    User fourth(4, "Fourth", "Third", 19, "fourththird@gmail.com", "cartof4", "40753123454");
    User fifth(5, "Fifth", "Sixth", 19, "fifthsixth@gmail.com", "cartof4", "40753123455");
    User sixth(6, "Sixth", "Fifth", 19, "sixthfifth@gmail.com", "cartof4", "40753123456");
    Friendship f1(1,first, second);
    Friendship f2(2,third, fourth);
    Friendship f3(3,fifth, sixth);
    repository.addEntity(f1);
    repository.addEntity(f2);
    repository.addEntity(f3);
    assert(repository.getPosById(1) == 0);
    assert(repository.getPosById(2) == 1);
    assert(repository.getPosById(3) == 2);
    assert(repository.getPosById(4) == -1);
}

void TestFriendshipRepository::all() {
    addFriendship();
    readFriendship();
    updateFriendship();
    deleteFriendship();
    getPosById();
}
