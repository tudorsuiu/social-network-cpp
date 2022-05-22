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

    /**
     * Destructor
     */
    ~BSTRepositoryCSV() = default;

    /**
     * Add entity to file
     * @param entity: T class object
     */
    void addEntity(T entity) {
        this->elements.add(entity);
        this->saveToFile(elements.getRoot());
    }

    /**
     * Get all entities from file
     * @return: BST<class T> - all entities stored in file
     */
    BST<T> read() {
        return elements;
    }

    /**
     * Read entity by id
     * @param id: unsigned int - entity id
     * @return: entity with given id
     */
    T readEntity(unsigned int id) {
        return elements.read(id);
    }

    /**
     * Update an entity from file
     * @param oldEntity: T class object - old entity
     * @param newEntity: T class object - updated entity
     */
    void updateEntity(T oldEntity, T newEntity) {
        elements.update(oldEntity, newEntity);
        this->saveToFile(elements.getRoot());
    }

    /**
     * Delete an entity from file
     * @param entity: unsigned int - entity
     */
    void deleteEntity(T entity) {
        elements.remove(entity);
        this->saveToFile(elements.getRoot());
    }

    /**
     * Check if BST is empty
     * @return: true if BST is empty, false otherwise
     */
    bool empty() {
        return elements.empty();
    }

    /**
     * Check BST size
     * @return: BST size
     */
    unsigned int size() {
        return elements.size();
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
