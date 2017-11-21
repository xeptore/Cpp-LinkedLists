/*
 * Created by Xeptore on 11/21/17.
 * Copyright (c) 2017.
 */

#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H

class DoublyLinkedList {
private:
    int value;
    DoublyLinkedList *next;
    DoublyLinkedList *prev;
    static DoublyLinkedList *first = nullptr;

public:
    explicit DoublyLinkedList(int value);

    void setValue(int value);
    int getValue();
    void setNextNode(DoublyLinkedList * node);
    DoublyLinkedList *getNextNode();
    void setPrevNode(DoublyLinkedList * node);
    DoublyLinkedList *getPrevNode();

    void push(int newNodeValue);
    bool addNext(int targetNodeValue, int newNodeValue);
    bool addPrevious(int targetNodeValue, int newNodeValue);

    int pop();
    bool remove(int targetNodeValue);
    bool removeNext(int targetNodeValue);
    bool removePrevious(int targetNodeValue);
};


#endif //DoublyLinkedList_H
