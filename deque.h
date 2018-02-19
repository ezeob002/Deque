//
//  deque.h
//  Deque
//
//  Created by Uchenna Ezeobi on 2/19/18.
//  Copyright © 2018 Uchenna Ezeobi. All rights reserved.
//

#ifndef deque_h
#define deque_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DequeNode
{
    void *data;
    struct DequeNode *next;
    struct DequeNode *prev;
}DequeNode;

typedef struct  DequeueList
{
    int sizeOfDequeue;
    size_t memorySize;
    DequeNode *head;
    DequeNode *tail;
}DequeList;

void queueInit(DequeList *dequeue, size_t memsorySize);
int getQueueSize(DequeList *dequeue);
void queuePeek(DequeList *, void *);
void clearQueue(DequeList *dequeue);
void dequePopFront(DequeList* deque, void* data);
void dequePopBack(DequeList* deque, void* data);
bool dequeIsEmpty(DequeList* deque);
bool dequePushFront(DequeList* deque, void *data);
bool dequePushBack(DequeList* deque, void *data);
void dequePeekFront(DequeList* deque, void *data);
void dequePeekBack(DequeList* deque, void *data);
//bool dequeIsEmpty()
#endif /* deque_h */
