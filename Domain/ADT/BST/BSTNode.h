//
// Created by Tudor on 5/4/2022.
//

#ifndef PROIECT_SDA_BSTNODE_H
#define PROIECT_SDA_BSTNODE_H

template<typename T> class BST;

template<class T> class BSTNode {
private:
    T info;
    BSTNode<T> *left;
    BSTNode<T> *right;
public:
    /**
     * Constructor
     * @param info: T class object
     */
    BSTNode(T info) : info(info) {
        this->left = nullptr;
        this->right = nullptr;
    }

    /**
     * Constructor with parameters
     * @param info: T class object
     * @param left: left pointer
     * @param right: right pointer
     */
    BSTNode(T info, BSTNode<T> *left, BSTNode<T> *right) : info(info), left(left), right(right) {}

//    /**
//     * Destructor
//     */
//    ~BSTNode() {
//        delete left;
//        delete right;
//    }

    friend class BST<T>;
};


#endif //PROIECT_SDA_BSTNODE_H
