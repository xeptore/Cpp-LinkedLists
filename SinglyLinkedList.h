/*
 * Created by Xeptore on 11/21/2017.
 * Copyright (c) 2017.
 */

#ifndef SinglyLinkedList_H
#define SinglyLinkedList_H

// Singly Linked List main calss
class SinglyLinkedList {
public:
    // Value os each node
    int value;
    // Pointer to next node
    SinglyLinkedList *next;

    // Constructor
    explicit SinglyLinkedList(int value);
};

#endif //SinglyLinkedList_H
