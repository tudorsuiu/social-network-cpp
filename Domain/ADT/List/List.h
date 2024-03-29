//
// Created by Tudor on 4/23/2022.
//

#ifndef PROIECT_SDA_LIST_H
#define PROIECT_SDA_LIST_H

#include <iostream>
#include "../../MyException.h"

template<class T> class List {
private:
    int _DEFAULT_CAPACITY = 10;
    T* _entities;
    int _capacity;
    int _size;
    void _resize() {
        this->_capacity = this->_capacity + this->_DEFAULT_CAPACITY;
        T* newEntities = new T[this->_capacity];
        for(int i = 0; i < this->_size; i++) {
            newEntities[i] = this->_entities[i];
        }
        delete[] this->_entities;
        this->_entities = newEntities;
    }
public:
    /**
     * Constructor
     */
    List() {
        this->_size = 0;
        this->_capacity = _DEFAULT_CAPACITY;
        _entities = new T[this->_capacity];
    }

    /**
     * Copy-constructor
     * @param array: new array
     */
    List(const List<T> &array) {
        this->_capacity = array._capacity;
        this->_size = array._size;
        T* newEntities = new T[this->_capacity];
        for(int i = 0; i < this->_size; i++) {
            newEntities[i] = array[i];
        }
        this->_entities = newEntities;
    }

    /**
     * Destructor
     */
    ~List() {
        delete[] _entities;
    }

    /**
     * Size getter
     * @return: array size
     */
    int size() {
        return this->_size;
    }

    /**
     * Capacity getter
     * @return: array capacity
     */
    int capacity() {
        return this->_capacity;
    }

    /**
     * Checks if an array is empty
     * @return: true if the array is empty, false otherwise
     */
    bool empty() {
        return _size == 0;
    }

    /**
     * Add entity at the end of an array
     * @param entity: T class object
     */
    void push_back(T entity) {
        if(this->_size == this->_capacity) {
            _resize();
        }
        this->_entities[this->_size++] = entity;
    }

    /**
     * Returns and delete the last entity of an array
     * @return: last entity of an array
     */
    T pop_back() {
        if(empty()) {
            throw MyException("List is empty.");
        }
        T entity;
        entity = this->_entities[--this->_size];

        T* newEntities = new T[this->_size];
        for(int i = 0; i < this->_size; i++) {
            newEntities[i] = this->_entities[i];
        }
        delete[] this->_entities;

        this->_entities = newEntities;

        return entity;
    }

    /**
     * Insert an element in array
     * @param index: position in array
     * @param entity: T class object
     */
    void insert(int index, T entity) {
        if (index < 0 || index > this->_size) {
            throw MyException("Index out of range");
        }
        if(this->_size == this->_capacity) {
            this->_resize();
        }

        T* newEntities = new T[this->_capacity];
        for(int i = 0; i < this->_size; i++) {
            newEntities[i] = this->_entities[i];
        }
        delete[] this->_entities;

        for(int i = this->_size; i > index; i--) {
            newEntities[i] = newEntities[i - 1];
        }
        newEntities[index] = entity;

        this->_entities = newEntities;
        this->_size++;
    }

    /**
     * Removes first entity from array
     * @param entity: given entity
     */
    void erase(T entity) {
        if(empty()) {
            throw MyException("List is empty.");
        }

        int index = -1;
        for(int i = 0; i < _size; i++) {
            if(_entities[i] == entity) {
                index = i;
                i = _size;
            }
        }

        if (index < 0 || index >= this->_size) {
            throw MyException("Index out of range.");
        }

        T* newEntities = new T[this->_capacity];
        for(int i = 0; i < this->_size; i++) {
            newEntities[i] = this->_entities[i];
        }
        delete[] this->_entities;

        for(int i = index; i < this->_size - 1; i++) {
            newEntities[i] = newEntities[i + 1];
        }

        this->_size--;
        this->_entities = newEntities;
    }

    /**
     * Clears an array
     */
    void clear() {
        delete[] this->_entities;
        this->_size = 0;
        this->_capacity = _DEFAULT_CAPACITY;
        this->_entities = new T[this->_capacity];
    }

    T& operator[](int index) const {
        return _entities[index];
    }

    List<T> &operator=(const List<T> &array) {
        this->_capacity = array._capacity;
        this->_size = array._size;
        delete[] this->_entities;
        this->_entities = new T[this->_capacity];
        for(int i = 0; i < this->_size; i++) {
            this->_entities[i] = array._entities[i];
        }
        return *this;
    }
};


#endif //PROIECT_SDA_LIST_H
