//
// Created by Tudor on 5/18/2022.
//

#include <cassert>
#include "TestBST.h"
#include "../../../Domain/ADT/BST/BST.h"

void TestBST::add() {
    BST<int> bst;
    bst.add(49);
    bst.add(82);
    bst.add(43);
    bst.add(92);
    bst.add(81);
    bst.add(89);
    bst.add(15);
    bst.add(64);
    bst.add(9);
    bst.add(8);
    assert(bst.exist(8));
    assert(bst.exist(9));
    assert(bst.exist(15));
    assert(bst.exist(43));
    assert(bst.exist(49));
    assert(bst.exist(64));
    assert(bst.exist(81));
    assert(bst.exist(82));
    assert(bst.exist(89));
    assert(bst.exist(92));
}

void TestBST::read() {
    BST<int> bst;
    bst.add(49);
    bst.add(82);
    bst.add(43);
    bst.add(92);
    bst.add(81);
    bst.add(89);
    bst.add(15);
    bst.add(64);
    bst.add(9);
    bst.add(8);
    assert(bst.getRoot() != nullptr);
}

void TestBST::update() {
    BST<int> bst;
    bst.add(49);
    bst.add(82);
    bst.add(43);
    bst.add(92);
    bst.add(81);
    bst.add(89);
    bst.add(15);
    bst.add(64);
    bst.add(9);
    bst.add(8);
    bst.update(81, 21);
    assert(bst.exist(81) == false);
    assert(bst.exist(21));
}

void TestBST::remove() {
    BST<int> bst;
    bst.add(49);
    bst.add(82);
    bst.add(43);
    bst.add(92);
    bst.add(81);
    bst.add(89);
    bst.add(15);
    bst.add(64);
    bst.add(9);
    bst.add(8);
    bst.del(81);
    assert(bst.exist(81) == false);
}

void TestBST::exist() {
    BST<int> bst;
    bst.add(49);
    bst.add(82);
    bst.add(43);
    bst.add(92);
    bst.add(81);
    bst.add(89);
    bst.add(15);
    bst.add(64);
    bst.add(9);
    bst.add(8);
    assert(bst.exist(8));
    assert(bst.exist(9));
    assert(bst.exist(15));
    assert(bst.exist(43));
    assert(bst.exist(49));
    assert(bst.exist(64));
    assert(bst.exist(81));
    assert(bst.exist(82));
    assert(bst.exist(89));
    assert(bst.exist(92));
}

void TestBST::empty() {
    BST<int> bst;
    assert(bst.empty());
    bst.add(15);
    bst.add(9);
    bst.add(8);
    bst.add(43);
    assert(bst.exist(8));
    assert(bst.exist(9));
    assert(bst.exist(15));
    assert(bst.exist(43));
    assert(bst.empty() == false);
}

void TestBST::all() {
    add();
    read();
    update();
    remove();
    exist();
    empty();
}
