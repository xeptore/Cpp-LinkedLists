/*
 * Created by Xeptore on 11/21/2017.
 * Copyright (c) 2017.
 */

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(int value) {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

void push(DoublyLinkedList *node, int newNodeValue) {
    DoublyLinkedList *iterator = node;
    while (iterator->next != nullptr) {
        iterator = iterator->next;
    }
    auto *newNode = new DoublyLinkedList(newNodeValue);
    iterator->next = newNode;
}

bool addNext(DoublyLinkedList *node, int targetNodeValue, int newNodeValue) {
    DoublyLinkedList *iterator = node;
    while (iterator->value != targetNodeValue && iterator->next != nullptr) {
        iterator = iterator->next;
    }
    if (iterator->next == nullptr && iterator->value != targetNodeValue) {
        return false;
    }
    auto *newNode = new DoublyLinkedList(newNodeValue);
    newNode->next = iterator->next;
    newNode->next->prev = newNode;
    iterator->next = newNode;
    newNode->prev = iterator;
    return true;
}

bool addPrevious(DoublyLinkedList *node, int targetNodeValue, int newNodeValue) {
    DoublyLinkedList *iterator = node;
    auto *newNode = new DoublyLinkedList(newNodeValue);
    if (iterator->value == targetNodeValue) {
        newNode->next = node;
        node->prev = newNode;
        node = newNode;
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

int pop(DoublyLinkedList *node) {
    DoublyLinkedList *iterator = node;
    if (iterator->next == nullptr) {
        int returnValue = iterator->value;
        node = nullptr;
        return returnValue;
    }
    while (iterator->next->next != nullptr) {
        iterator = iterator->next;
    }
    int returnValue = iterator->next->value;
    iterator->next = nullptr;
    return returnValue;
}

bool remove(DoublyLinkedList *node, int targetNodeValue) {
    DoublyLinkedList *iterator = node;
    if (iterator->value == targetNodeValue) {
        node = iterator->next;
        node->prev = nullptr;
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

bool removeNext(DoublyLinkedList *node, int targetNodeValue) {
    DoublyLinkedList *iterator = node;
    if (iterator->value == targetNodeValue) {
        if (iterator->next == nullptr) {
            return true;
        }
        node = iterator->next->next;
        return true;
    }
    while (iterator->next->value != targetNodeValue && iterator->next->next != nullptr) {
        iterator = iterator->next;
    }
    if (iterator->next->next == nullptr) {
        return true;
    }
    iterator->next->next = iterator->next->next->next;
    iterator->next->next->prev = iterator->next;
    return true;
}

bool removePrevious(DoublyLinkedList *node, int targetNodeValue) {
    DoublyLinkedList *iterator = node;
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
