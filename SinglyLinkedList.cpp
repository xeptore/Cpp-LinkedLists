/*
 * Created by Xeptore on 11/20/2017.
 * Copyright (c) 2017. All rights reserved.
 */

#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList(int value) {
    if (this->first == nullptr) {
        this->first = this;
    }
    this->value = value;
    // Sets next node to nullptr by default
    this->next = nullptr;
}

void SinglyLinkedList::setValue(int value) {
    this->value = value;
}

int SinglyLinkedList::getValue() {
    return this->value;
}

void SinglyLinkedList::setNextNode(SinglyLinkedList * node) {
    this->next = node;
}

SinglyLinkedList *SinglyLinkedList::getNextNode() {
    return this->next;
}

void SinglyLinkedList::push(int newNodeValue) {
    SinglyLinkedList *iterator = this->first;
    while (iterator->next != nullptr) {
        iterator = iterator->next;
    }
    auto *newNode = new SinglyLinkedList(newNodeValue);
    iterator->next = newNode;
}

bool SinglyLinkedList::addNext(int targetNodeValue, int value) {
    SinglyLinkedList *iterator = this->first;
    while (iterator->value != targetNodeValue && iterator->next != nullptr) {
        iterator = iterator->next;
    }
    if (iterator->next == nullptr && iterator->value != targetNodeValue) {
        return false;
    }
    auto *newNode = new SinglyLinkedList(value);
    newNode->next = iterator->next;
    iterator->next = newNode;
    return true;
}

bool SinglyLinkedList::addPrevious(int targetNodeValue, int value) {
    SinglyLinkedList *iterator = this->first;
    auto *newNode = new SinglyLinkedList(value);
    if (iterator->value == targetNodeValue) {
        newNode->next = iterator;
        this->first = newNode;
        return true;
    }
    while (iterator->next->value != targetNodeValue && iterator->next != nullptr) {
        iterator = iterator->next;
    }
    if (iterator->next == nullptr) {
        return false;
    }
    newNode->next = iterator->next;
    iterator->next = newNode;
    return true;
}

int SinglyLinkedList::pop() {
    SinglyLinkedList *iterator = this->first;
    if (iterator->next == nullptr) {
        int returnValue = iterator->value;
        this->first = nullptr;
        return returnValue;
    }
    while (iterator->next->next != nullptr) {
        iterator = iterator->next;
    }
    int returnValue = iterator->next->value;
    iterator->next = nullptr;
    return returnValue;
}

bool SinglyLinkedList::remove(int targetNodeValue) {
    SinglyLinkedList *iterator = this->first;
    if (iterator->value == targetNodeValue) {
        this->first = iterator->next;
        iterator = nullptr;
        return true;
    }
    while (iterator->next->value != targetNodeValue && iterator->next->next != nullptr) {
        iterator = iterator->next;
    }
    if (iterator->next->next == nullptr && iterator->next->value != targetNodeValue ) {
        return -1;
    }
    iterator->next = iterator->next->next;
    return true;
}

bool SinglyLinkedList::removeNext(int targetNodeValue)  {
    SinglyLinkedList *iterator = this->first;
    if (iterator->value == targetNodeValue) {
        this->first = this->first->next->next;
        return true;
    }
    while (iterator->next->value != targetNodeValue && iterator->next->next != nullptr) {
        iterator = iterator->next;
    }
    if (iterator->next->next == nullptr) {
        return false;
    }
    iterator->next->next = iterator->next->next->next;
    return true;
}

bool SinglyLinkedList::removePrevious(int targetNodeValue) {
    SinglyLinkedList *iterator = this->first;
    if (iterator->value == targetNodeValue) {
        return false;
    }
    while (iterator->next->next->value != targetNodeValue && iterator->next->next->next != nullptr) {
        iterator = iterator->next;
    }
    if (iterator->next->next->next == nullptr && iterator->next->next->value != targetNodeValue) {
        return false;
    }
    iterator->next = iterator->next->next;
    return true;
}
