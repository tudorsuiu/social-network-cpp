//
// Created by Tudor on 5/19/2022.
//

#ifndef USERREPOSITORYCSV_H_BSTREPOSITORYCSV_H
#define USERREPOSITORYCSV_H_BSTREPOSITORYCSV_H


#include <string>
#include <fstream>
#include "../Domain/ADT/BST/BST.h"

template<class T>
class BSTRepositoryCSV {
private:
    BST<T> elements;
    std::string fileName;
public:
    BSTRepositoryCSV(std::string name) {
        this->fileName = name;
        this->loadFromFile();
    }

    ~BSTRepositoryCSV() = default;

    void addEntity(T entity) {
        this->elements.add(entity);
        this->saveToFile(elements.getRoot());
    }

    BST<T> read() {
        return elements;
    }

    T readEntity(unsigned int id) {
        return elements.read(id);
    }

    void updateEntity(T oldEntity, T newEntity) {
        elements.update(oldEntity, newEntity);
        this->saveToFile(elements.getRoot());
    }

    void deleteEntity(T entity) {
        elements.remove(entity);
        this->saveToFile(elements.getRoot());
    }

    bool empty() {
        return elements.empty();
    }

    /**
     * Saves tree to file
     */
    void saveToFile(BSTNode<T> *root)
    {
        std::ofstream f(this->fileName);
        elements.saveToFileRecursive(f, root);
    }

    /**
     * Loads the elements from file into "elements" BST
     */
    void loadFromFile()
    {
        std::string line;
        std::ifstream f(this->fileName);
        while (std::getline(f, line)) {
            T object(line, ',');
            this->elements.add(object);
        }
    }
};


#endif //USERREPOSITORYCSV_H_BSTREPOSITORYCSV_H
