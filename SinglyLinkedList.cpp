/*
 * Created by Xeptore on 11/21/2017.
 * Copyright (c) 2017.
 */

#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList(int value) {
    this->value = value;
    this->next = nullptr;
}

void push(SinglyLinkedList *node, int newNodeValue) {
    SinglyLinkedList *iterator = node;
    while (iterator->next != nullptr) {
        iterator = iterator->next;
    }
    auto *newNode = new SinglyLinkedList(newNodeValue);
    iterator->next = newNode;
}

bool addNext(SinglyLinkedList *node, int targetNodeValue, int value) {
    SinglyLinkedList *iterator = node;
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

bool addPrevious(SinglyLinkedList *node, int targetNodeValue, int value) {
    SinglyLinkedList *iterator = node;
    auto *newNode = new SinglyLinkedList(value);
    if (iterator->value == targetNodeValue) {
        newNode->next = iterator;
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
    return true;
}

int pop(SinglyLinkedList *node) {
    SinglyLinkedList *iterator = node;
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

bool remove(SinglyLinkedList *node, int targetNodeValue) {
    SinglyLinkedList *iterator = node;
    if (iterator->value == targetNodeValue) {
        node = iterator->next;
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

bool removeNext(SinglyLinkedList *node, int targetNodeValue)  {
    SinglyLinkedList *iterator = node;
    if (iterator->value == targetNodeValue) {
        node->next = node->next->next;
        return true;
    }
    while (iterator->next->value != targetNodeValue && iterator->next->next != nullptr) {
        iterator = iterator->next;
    }
    if (iterator->next->next== nullptr) {
        return false;
    }
    iterator->next->next = iterator->next->next->next;
    return true;
}

bool removePrevious(SinglyLinkedList *node, int targetNodeValue) {
    SinglyLinkedList *iterator = node;
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
