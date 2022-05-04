//
// Created by Tudor on 5/4/2022.
//

#ifndef PROIECT_SDA_BST_H
#define PROIECT_SDA_BST_H

#include <iostream>
#include "BSTNode.h"

template<class T> class BST {
private:
    BSTNode<T> *root;
    void add(BSTNode<T> *adress, T element) {
        if(adress->info > element) {
            if(adress->left != nullptr) {
                add(adress->left, element);
            }
            else {
                adress->left = new BSTNode<T>(element, nullptr, nullptr);
            }
        }
        else {
            if(adress->right != nullptr) {
                add(adress->right, element);
            }
            else {
                adress->right = new BSTNode<T>(element, nullptr, nullptr);
            }
        }
    }

    void showInOrder(BSTNode<T> *adress) {
        if(adress != nullptr) {
            showInOrder(adress->left);
            std::cout << adress->info << '\n';
            showInOrder(adress->right);
        }
    }
public:
    /**
     * Constructor
     */
    BST() {
        this->root = nullptr;
    }

    /**
     * Add element
     * @param element: T class object
     */
    void add(T element) {
        if(this->root == nullptr) {
            this->root = new BSTNode<T>(element, nullptr, nullptr);
        }
        else {
            add(this->root, element);
        }
    }

    /**
     * Show all elements in order
     */
    void show() {
        showInOrder(this->root);
    }
};


#endif //PROIECT_SDA_BST_H
