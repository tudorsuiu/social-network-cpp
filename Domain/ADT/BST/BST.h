//
// Created by Tudor on 5/4/2022.
//

#ifndef PROIECT_SDA_BST_H
#define PROIECT_SDA_BST_H

#include <iostream>
#include "BSTNode.h"
#include "../../MyException.h"

template<class T> class BST {
private:
    BSTNode<T> *root;
    /**
     * Add element
     * @param node: node
     * @param element: T class object
     */
    BSTNode<T> *insert(BSTNode<T> *node, T element) {
        if(exist(element)) {
            throw MyException("Element already exists in tree.");
        }
        if(!node) {
            return new BSTNode<T>(element, nullptr, nullptr);
        }
        if(element > node->info) {
            node->right = insert(node->right, element);
        }
        else {
            node->left = insert(node->left, element);
        }
        return node;
    }

    /**
     * Search a given element in a given ADT
     * @param node: node
     * @param element: T class object
     * @return
     */
    BSTNode<T> *search(BSTNode<T> *node, T element) {
        if(node == nullptr || node->info == element) {
            return node;
        }
        if(node->info < element) {
            return search(node->right, element);
        }
        return search(node->left, element);
    }

    /**
     * Show in order
     * @param root: root
     */
    void showInOrder(BSTNode<T> *root) {
        if(root != nullptr) {
            showInOrder(root->left);
            std::cout << root->info << '\n';
            showInOrder(root->right);
        }
    }

    /**
     * Determine the node with minimum info value found
     * @param node: node
     * @return: the node with minimum info value found
     */
    BSTNode<T> *minValueNode(BSTNode<T> *node) {
        BSTNode<T> *current = node;
        while(current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    /**
     * Delete element
     * @param node: root
     * @param element: T class object
     * @return: the new root
     */
    BSTNode<T> *remove(BSTNode<T> *node, T element) {
        BSTNode<T> *temp;
        if(node == nullptr) {
            return node;
        }
        if(node->info > element) {
            node->left = remove(node->left, element);
        }
        else if(element > node->info) {
            node->right = remove(node->right, element);
        }
        else {
            if(node->left == nullptr && node->right == nullptr) {
                return nullptr;
            }
            else if(node->left == nullptr) {
                temp = node->right;
                free(node);
                return temp;
            }
            else if(node->right == nullptr) {
                temp = node->left;
                free(node);
                return temp;
            }
            temp = minValueNode(node->right);
            node->info = temp->info;
            node->right = remove(node->right, temp->info);
        }
        return node;
    }

    /**
     * Search a node that contains an entity with the given id
     * @param node: node
     * @param id: given id
     * @return: node that contains an entity with the given id
     */
    BSTNode<T> *searchById(BSTNode<T> *node, unsigned int id) {
        if(node == nullptr || node->info.getId() == id) {
            return node;
        }
        if(node->info.getId() < id) {
            return searchById(node->right, id);
        }
        return searchById(node->left, id);
    }

//    /**
//     * Destroys from memory
//     * @param node: node
//     */
//    void DestroyRecursive(BSTNode<T> *node) {
//        if(node != nullptr) {
//            DestroyRecursive(node->left);
//            DestroyRecursive(node->right);
//        }
//        delete node;
//    }
public:
    /**
     * Constructor
     */
    BST() {
        this->root = nullptr;
    }

//    /**
//     * Destructor
//     */
//    ~BST() {
//        DestroyRecursive(this->root);
//    }

    /**
     * Add element
     * @param element: T class object
     */
    void add(T element) {
        this->root = insert(this->root, element);
    }

    /**
     * Root getter
     * @return: root
     */
    BSTNode<T> *getRoot() {
        return this->root;
    }

    /**
     * Read entity by given id
     * @param id: given id
     * @return: entity with given id or default entity
     */
    T &read(unsigned int id) {
        return searchById(this->root, id)->info;
    }

    /**
     * Update element
     * @param element: element
     * @param newElement: new element
     */
    void update(T element, T newElement) {
        remove(element);
        add(newElement);
    }

    /**
     * Delete element
     * @param element: T class object
     */
    void remove(T element) {
        this->root = remove(this->root, element);
    }

    /**
     * Show all elements in order
     */
    void show() {
        showInOrder(this->root);
    }

    /**
     * Check if element exist
     * @param element: T class object
     * @return: true if element exist, false otherwise
     */
    bool exist(T element) {
        return search(this->root, element) != nullptr;
    }

    void saveToFileRecursive(std::ofstream &f,BSTNode<T> *root) {
        if(root != nullptr) {
            saveToFileRecursive(f, root->left);
            f << root->info.toStringDelimiter(',') << '\n';
            saveToFileRecursive(f, root->right);
        }
    }

    /**
     * Check if tree is empty
     * @return: true if tree is empty, false otherwise
     */
    bool empty() {
        return this->root == nullptr;
    }
};


#endif //PROIECT_SDA_BST_H
