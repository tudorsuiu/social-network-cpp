//
// Created by Tudor on 5/6/2022.
//

#include <cassert>
#include "TestList.h"
#include "../../../Domain/ADT/List/List.h"

void TestList::constructor() {
    List<int> array;
    assert(array.size() == 0);
    assert(array.capacity() == 10);
}

void TestList::copyConstructor() {
    List<int> copyArray;
    List<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(8);
    array.push_back(9);
    array.push_back(10);
    array.push_back(11);
    copyArray = array;
    assert(copyArray.size() == 11);
    assert(copyArray.capacity() == 20);
}

void TestList::size() {
    List<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(8);
    array.push_back(9);
    array.push_back(10);
    array.push_back(11);
    assert(array.size() == 11);
}

void TestList::capacity() {
    List<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(8);
    array.push_back(9);
    array.push_back(10);
    array.push_back(11);
    array.push_back(12);
    array.push_back(13);
    array.push_back(14);
    array.push_back(15);
    array.push_back(16);
    array.push_back(17);
    array.push_back(18);
    array.push_back(19);
    array.push_back(20);
    array.push_back(21);
    assert(array.capacity() == 30);
}

void TestList::empty() {
    List<int> array;
    assert(array.empty() == true);

    array.push_back(1);
    assert(array.empty() == false);
}

void TestList::push_back() {
    List<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(8);
    array.push_back(9);
    array.push_back(10);
    array.push_back(11);
    assert(array.size() == 11);
    assert(array[0] == 1);
    assert(array[1] == 2);
    assert(array[2] == 3);
    assert(array[3] == 4);
    assert(array[4] == 5);
    assert(array[5] == 6);
    assert(array[6] == 7);
    assert(array[7] == 8);
    assert(array[8] == 9);
    assert(array[9] == 10);
    assert(array[10] == 11);
}

void TestList::pop_back() {
    List<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(8);
    array.push_back(9);
    array.push_back(10);
    array.push_back(11);
    assert(array.size() == 11);
    int test = array.pop_back();
    assert(test == 11);
    assert(array.size() == 10);
}

void TestList::insert() {
    List<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(8);
    array.push_back(9);
    array.push_back(10);
    array.push_back(11);
    assert(array.size() == 11);
    array.insert(3, 3);
    assert(array.size() == 12);
    assert(array[0] == 1);
    assert(array[1] == 2);
    assert(array[2] == 3);
    assert(array[3] == 3);
    assert(array[4] == 4);
    assert(array[5] == 5);
    assert(array[6] == 6);
    assert(array[7] == 7);
    assert(array[8] == 8);
    assert(array[9] == 9);
    assert(array[10] == 10);
    assert(array[11] == 11);
}

void TestList::erase() {
    List<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(8);
    array.push_back(9);
    array.push_back(10);
    array.push_back(11);
    assert(array.size() == 11);
    array.erase(6);
    assert(array.size() == 10);
    assert(array[0] == 1);
    assert(array[1] == 2);
    assert(array[2] == 3);
    assert(array[3] == 4);
    assert(array[4] == 5);
    assert(array[5] == 7);
    assert(array[6] == 8);
    assert(array[7] == 9);
    assert(array[8] == 10);
    assert(array[9] == 11);
}

void TestList::clear() {
    List<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(8);
    array.push_back(9);
    array.push_back(10);
    array.push_back(11);
    array.clear();
    assert(array.empty() == true);
}

void TestList::all() {
    constructor();
    copyConstructor();
    size();
    capacity();
    empty();
    push_back();
    pop_back();
    insert();
    erase();
    clear();
}
