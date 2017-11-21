/*
 * Created by Xeptore on 11/21/17.
 * Copyright (c) 2017.
 */

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(int value) {
    if (this->first == nullptr) {
        this->first = this;
    }
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

void DoublyLinkedList::setValue(int value) {
    this->value = value;
}

int DoublyLinkedList::getValue() {
    return this->value;
}

void DoublyLinkedList::setNextNode(DoublyLinkedList *node) {
    this->next = node;
}

DoublyLinkedList *DoublyLinkedList::getNextNode() {
    return this->next;
}

void DoublyLinkedList::setPrevNode(DoublyLinkedList *node) {
    this->prev = node;
}

DoublyLinkedList *DoublyLinkedList::getPrevNode() {
    return this->prev;
}

void DoublyLinkedList::push(int newNodeValue) {
    DoublyLinkedList *iterator = this->first;
    while (iterator->next != nullptr) {
        iterator = iterator->next;
    }
    auto *newNode = new DoublyLinkedList(newNodeValue);
    iterator->next = newNode;
}

bool DoublyLinkedList::addNext(int targetNodeValue, int newNodeValue) {
    DoublyLinkedList *iterator = this->first;
    while (iterator->value != targetNodeValue && iterator->next != nullptr) {
        iterator = iterator->next;
    }
    if (iterator->next == nullptr && iterator->value != targetNodeValue) {
        return false;
    }
    auto *newNode = new DoublyLinkedList(newNodeValue);
    newNode->next = iterator->next;
    iterator->next = newNode;
    return true;
}

bool DoublyLinkedList::addPrevious(int targetNodeValue, int newNodeValue) {
    DoublyLinkedList *iterator = this->first;
    auto *newNode = new DoublyLinkedList(newNodeValue);
    if (iterator->value == targetNodeValue) {
        newNode->next = iterator;
        iterator->prev = newNode;
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
    newNode->next->prev = newNode;
    newNode->prev = iterator;
    return true;
}

int DoublyLinkedList::pop() {
    DoublyLinkedList *iterator = this->first;
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

bool DoublyLinkedList::remove(int targetNodeValue) {
    DoublyLinkedList *iterator = this->first;
    if (iterator->value == targetNodeValue) {
        this->first = iterator->next;
        this->first->prev = nullptr;
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

bool DoublyLinkedList::removeNext(int targetNodeValue) {
    DoublyLinkedList *iterator = this->first;
    if (iterator->value == targetNodeValue) {
        this->first = this->first->next->next;
        this->first = nullptr;
        return true;
    }
    while (iterator->next->value != targetNodeValue && iterator->next->next != nullptr) {
        iterator = iterator->next;
    }
    if (iterator->next->next == nullptr) {
        return false;
    }
    iterator->next->next = iterator->next->next->next;
    iterator->next->next->prev = iterator->next;
    return true;
}

bool DoublyLinkedList::removePrevious(int targetNodeValue) {
    DoublyLinkedList *iterator = this->first;
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
    iterator->next->prev = iterator;
    return true;
}
