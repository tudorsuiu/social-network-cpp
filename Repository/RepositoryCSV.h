//
// Created by Tudor on 5/13/2022.
//

#ifndef USERREPOSITORYCSV_H_REPOSITORYCSV_H
#define USERREPOSITORYCSV_H_REPOSITORYCSV_H

#include <fstream>
#include <string>
#include "../Domain/Array/List.h"

template<class T> class RepositoryCSV {
private:
    List<T> elements;
    std::string fileName;
public:
    /**
     * Read from file
     * @param name: string - file name
     */
    RepositoryCSV(std::string name) {
        this->fileName = name;
        this->loadFromFile();
    }

    /**
     * Destructor
     */
    ~RepositoryCSV() = default;

    /**
     * Add entity to file
     * @param entity: T class object
     */
    void addEntity(T entity) {
        this->elements.push_back(entity);
        this->saveToFile();
    }

    /**
     * Get all entities from file
     * @return: List<class T> - all entities stored in file
     */
    List<T> readEntity() {
        return this->elements;
    }

    /**
     * Read entity by id
     * @param id: unsigned int - entity id
     * @return: entity with given id
     */
    T readEntity(unsigned int id) {
        if(getPosById(id) != -1) {
            return elements[getPosById(id)];
        }
        else {
            throw std::out_of_range("Id out of range");
        }
    }

    /**
     * Update an entity from file
     * @param id: unsigned int - entity index
     * @param newEntity: T class object - updated entity
     */
    void updateEntity(unsigned int id, T newEntity) {
        if(getPosById(id) != -1) {
            elements[getPosById(id)] = newEntity;
            this->saveToFile();
        }
        else {
            throw std::out_of_range("Id out of range");
        }
    }

    /**
     * Delete an entity from file
     * @param id: unsigned int - id
     */
    void deleteEntity(unsigned int id) {
        if(getPosById(id) != -1) {
            elements.erase(getPosById(id));
            this->saveToFile();
        }
        else {
            throw std::out_of_range("Id out of range");
        }
    }

    /**
     * Get position by object index
     * @param index: unsigned int - object index
     * @return: int - object position
     */
    int getPosById(unsigned int id) {
        for(int i = 0; i < elements.size(); i++) {
            if(elements[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }

    /**
     * Saves the elements from list "elements" in file
     */
    void saveToFile()
    {
        std::ofstream f(this->fileName);
        for(int i = 0; i < elements.size(); i++) {
            f << elements[i].toStringDelimiter(',') << '\n';
        }
    }


    /**
     * Loads the elements from file into "elements" vector
     */
    void loadFromFile()
    {
        std::string line;
        std::ifstream f(this->fileName);
        while (std::getline(f, line)) {
            T object(line, ',');
            this->elements.push_back(object);
        }
    }
};


#endif //USERREPOSITORYCSV_H_REPOSITORYCSV_H
