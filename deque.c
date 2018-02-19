//
//  deque.c
//  Deque
//
//  Created by Uchenna Ezeobi on 2/19/18.
//  Copyright © 2018 Uchenna Ezeobi. All rights reserved.
//

#include "deque.h"


void queueInit(DequeList *dequeue, size_t memorySize){
    dequeue->sizeOfDequeue = 0;
    dequeue->memorySize = memorySize;
    dequeue->head = NULL;
    dequeue->tail = NULL;
}

void clearQueue(DequeList *dequeue) {
    DequeNode* temp;
    while (dequeue->sizeOfDequeue > 0) {
        temp = dequeue->head;
        dequeue->head = temp->next;
        free(temp->data);
        free(temp);
        dequeue->sizeOfDequeue--;
    }
}

void queuePeek(DequeList *q, void *data)
{
    if(q->sizeOfDequeue > 0)
    {
        DequeNode *temp = q->head;
        memcpy(data, temp->data, q->memorySize);
    }
}

int getQueueSize(DequeList *dequeue) {
    return dequeue->sizeOfDequeue;
}

void dequePopFront(DequeList* deque, void* data) {
    
    if(deque->sizeOfDequeue > 0)
    {
        DequeNode *temp = deque->head;
        memcpy(data, temp->data, deque->memorySize);
        
        if(deque->sizeOfDequeue > 1)
        {
            deque->head = temp->next;
        }
        else
        {
            deque->head = NULL;
            deque->tail = NULL;
        }
        
        deque->sizeOfDequeue--;
        free(temp->data);
        free(temp);
    }
}
void dequePopBack(DequeList* deque, void* data) {
    
    if(deque->sizeOfDequeue > 0)
    {
        DequeNode *temp = deque->tail;
        memcpy(data, temp->data, deque->memorySize);
        
        if(deque->sizeOfDequeue > 1)
        {
            deque->tail = temp->prev;
        }
        else
        {
            deque->head = NULL;
            deque->tail = NULL;
        }
        
        deque->sizeOfDequeue--;
        free(temp->data);
        free(temp);
    }
}
bool dequeIsEmpty(DequeList* deque) {
    return deque->head == NULL;
}
bool dequePushFront(DequeList* deque, void *data) {
    DequeNode *newNode = (DequeNode*) malloc(sizeof(DequeNode));
    if(newNode == NULL) {return false;}
    newNode->data = malloc(deque->memorySize);
    if(newNode->data == NULL)
    {
        free(newNode);
        return false;
    }
    newNode->next = deque->head;
    newNode->prev = NULL;
    memcpy(newNode->data, data, deque->memorySize);
    if(deque->sizeOfDequeue == 0)
    {
        deque->head = newNode;
        deque->tail = newNode;
    }
    else
    {
        deque->head->prev = newNode;
        deque->head = newNode;
    }
    
    deque->sizeOfDequeue++;
    return true;
}

bool dequePushBack(DequeList* deque, void *data) {
    DequeNode *newNode = (DequeNode*) malloc(sizeof(DequeNode));
    if(newNode == NULL) {return false;}
    newNode->data = malloc(deque->memorySize);
    if(newNode->data == NULL)
    {
        free(newNode);
        return false;
    }
    newNode->prev = deque->tail;
    newNode->next = NULL;
    memcpy(newNode->data, data, deque->memorySize);
    if(deque->sizeOfDequeue == 0)
    {
        deque->head = newNode;
        deque->tail = newNode;
    }
    else
    {
        deque->tail->next = newNode;
        deque->tail = newNode;
    }
    
    deque->sizeOfDequeue++;
    return true;
}
void dequePeekFront(DequeList* deque, void *data) {
    
    if(deque->sizeOfDequeue > 0)
    {
        DequeNode *temp = deque->head;
        memcpy(data, temp->data, deque->memorySize);
    }
}
void dequePeekBack(DequeList* deque, void *data) {
    if(deque->sizeOfDequeue > 0)
    {
        DequeNode *temp = deque->tail;
        memcpy(data, temp->data, deque->memorySize);
    }
}




