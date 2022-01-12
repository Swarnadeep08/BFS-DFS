#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;

int dequeue()
{
    int x=-1;
    struct Node* t;
    if(front==NULL)
        printf("Queue is Empty :)\n");
    else
    {
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Queue is full :)\n");
        return;
    }

    t->data = x;
    t->next = NULL;
    if(front==NULL)
        front = rear = t;
    else{
        rear->next = t;
        rear = t;
    }
}

int isEmpty()
{
    return front==NULL;
}
#endif // QUEUE_H_INCLUDED
