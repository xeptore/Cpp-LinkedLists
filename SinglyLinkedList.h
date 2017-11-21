/*
 * Created by Xeptore on 11/21/2017.
 * Copyright (c) 2017. All rights reserved.
 */

#ifndef SinglyLinkedList_H
#define SinglyLinkedList_H

class SinglyLinkedList {
private:
    int value;
    SinglyLinkedList *next;
    static SinglyLinkedList *first = nullptr;

public:
    explicit SinglyLinkedList(int value);

    void setValue(int value);
    int getValue();
    void setNextNode(SinglyLinkedList * node);
    SinglyLinkedList *getNextNode();

    void push(int newNodeValue);
    bool addNext(int targetNodeValue, int newNodeValue);
    bool addPrevious(int targetNodeValue, int newNodeValue);

    int pop();
    bool remove(int targetNodeValue);
    bool removeNext(int targetNodeValue);
    bool removePrevious(int targetNodeValue);
};

#endif //SinglyLinkedList_H
