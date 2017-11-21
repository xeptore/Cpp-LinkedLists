/*
 * Created by Xeptore on 11/21/2017.
 * Copyright (c) 2017.
 */

#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H

class DoublyLinkedList {
public:
    int value;
    DoublyLinkedList *next;
    DoublyLinkedList *prev;

    explicit DoublyLinkedList(int value);
};


#endif //DoublyLinkedList_H
