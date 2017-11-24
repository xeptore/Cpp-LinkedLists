/*
 * Created by Xeptore on 11/21/2017.
 * Copyright (c) 2017.
 */

#include "SinglyLinkedList.h"

// Constructor declaration
SinglyLinkedList::SinglyLinkedList(int value) {
    this->value = value;
    // Sets next node to NULL by default
    this->next = nullptr;
}

// Adds aa new node with value of <value> to end of the list
void push(SinglyLinkedList *node, int newNodeValue) {
    // Creates a copy of fist node to iterate through nodes list
    SinglyLinkedList *iterator = node;
    // Goes to next node until reaches the last node
    while (iterator->next != nullptr) {
        iterator = iterator->next;
    }
    // Creates a new node
    auto *newNode = new SinglyLinkedList(newNodeValue);
    // Add new node to end of list
    // Last node will point to new node as its next node
    iterator->next = newNode;
}

// Adds a new node with value of <value> after a node with value of <targetValue>
bool addNext(SinglyLinkedList *node, int targetNodeValue, int value) {
    // Creates a copy of fist node to iterate through nodes list
    SinglyLinkedList *iterator = node;
    // Goes to next node until reaches target node or reaches the last node of list
    while (iterator->value != targetNodeValue && iterator->next != nullptr) {
        iterator = iterator->next;
    }
    // Returns false as error if reaches the last node and can't find the target node
    if (iterator->next == nullptr && iterator->value != targetNodeValue) {
        return false;
    }
    // Creates a new node
    auto *newNode = new SinglyLinkedList(value);
    // Adds new created node right after the target node and before the previous node after the target node
    newNode->next = iterator->next;
    iterator->next = newNode;
    // Returns true as success
    return true;
}

// Adds a new node with value of <value> before a node with value of <targetValue>
bool addPrevious(SinglyLinkedList *node, int targetNodeValue, int value) {
    // Creates a copy of fist node to iterate through nodes list
    SinglyLinkedList *iterator = node;
    // Creates a new node
    auto *newNode = new SinglyLinkedList(value);
    // Adds new node to first of nodes list if targetNode is the first node of list
    if (iterator->value == targetNodeValue) {
        newNode->next = iterator;
        node = newNode;
        // Returns true as success
        return true;
    }
    // Goes to next node until reaches node before targetNode or reaches the last node of list
    while (iterator->next->value != targetNodeValue && iterator->next != nullptr) {
        iterator = iterator->next;
    }
    // Returns false as error if reaches the last node and can't find the target node
    if (iterator->next == nullptr) {
        return false;
    }
    // Adds new created node right before the targetNode and after the previous node before the targetNode
    newNode->next = iterator->next;
    iterator->next = newNode;
    // Returns true as success
    return true;
}

// Removes last node of list
int pop(SinglyLinkedList *node) {
    // Creates a copy of fist node to iterate through nodes list
    SinglyLinkedList *iterator = node;
    // Removes first node and return its value if there was only one node in list
    if (iterator->next == nullptr) {
        // Stores first value to a <returnValue> before deleting node
        int returnValue = iterator->value;
        // Removes node
        node = nullptr;
        // Returns node value stored in <returnValue>
        return returnValue;
    }
    // Goes to next node until reaches node before last node of list
    while (iterator->next->next != nullptr) {
        iterator = iterator->next;
    }
    // Stores value of last node in <returnValue>
    int returnValue = iterator->next->value;
    // Removes last node
    iterator->next = nullptr;
    // Returns stored value
    return returnValue;
}

// Removes a node with value of <targetNodeValue>
bool remove(SinglyLinkedList *node, int targetNodeValue) {
    // Creates a copy of fist node to iterate through nodes list
    SinglyLinkedList *iterator = node;
    // Removes first node if value of first node equals to <targetNodeValue>
    if (iterator->value == targetNodeValue) {
        // Sets first node of list to second node
        node = iterator->next;
        // Removes first node
        iterator = nullptr;
        // Returns true as success
        return true;
    }
    // Goes to next node until reaches node before the node with value of <targetNodeValue> or reaches the node before last node
    while (iterator->next->value != targetNodeValue && iterator->next->next != nullptr) {
        iterator = iterator->next;
    }
    // Returns false if reaches node before last node and can't find a node with value of <targetNodeValue>
    if (iterator->next->next == nullptr && iterator->next->value != targetNodeValue ) {
        return false;
    }
    // Misses node with value of <targetNodeValue>
    iterator->next = iterator->next->next;
    // Returns true as success
    return true;
}

// Removes next node of a node with value of <targetNodeValue>
bool removeNext(SinglyLinkedList *node, int targetNodeValue)  {
    // Creates a copy of fist node to iterate through nodes list
    SinglyLinkedList *iterator = node;
    // Misses second node if value of first node equals to <targetNodeValue>
    if (iterator->value == targetNodeValue) {
        node->next = node->next->next;
        // Returns true as success
        return true;
    }
    // Goes to next node until reaches node before the node with value of <targetNodeValue>
    while (iterator->next->value != targetNodeValue && iterator->next->next != nullptr) {
        iterator = iterator->next;
    }
    // Returns false if can't find a node with value of <targetNodeValue> and reaches end of list
    if (iterator->next->next== nullptr) {
        return false;
    }
    // Misses the node with value of <targetNodeValue>
    iterator->next->next = iterator->next->next->next;
    // Returns true as success
    return true;
}

// Removes previous node of a node with value of <targetNodeValue>
bool removePrevious(SinglyLinkedList *node, int targetNodeValue) {
    // Creates a copy of fist node to iterate through nodes list
    SinglyLinkedList *iterator = node;
    // Returns false as error if you want to delete a node before first node
    if (iterator->value == targetNodeValue) {
        return false;
    }
    // Goes to next node until reaches node before the node with value of <targetNodeValue>
    while (iterator->next->next->value != targetNodeValue && iterator->next->next->next != nullptr) {
        iterator = iterator->next;
    }
    // Returns false if can't find a node with value of <targetNodeValue> and reaches end of list
    if (iterator->next->next->next == nullptr && iterator->next->next->value != targetNodeValue) {
        return false;
    }
    // Misses the node with value of <targetNodeValue>
    iterator->next = iterator->next->next;
    return true;
}
