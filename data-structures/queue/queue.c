#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct _QueueNode{
    ElementType data;
    struct _QueueNode *next;
}QueueNode;

typedef struct _Queue{
    QueueNode *head;
    QueueNode *tail;
}Queue;

bool initQueue(Queue **queue)
{
    *queue = (Queue *)malloc(sizeof(Queue));

    (*queue)->head = NULL;
    (*queue)->tail = NULL;
}

bool pushQueue(Queue *queue, ElementType newData)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = newData;

    if ((queue->head == NULL)&&(queue->tail == NULL)){
        queue->head = newNode;
        queue->tail = newNode;
    }
    else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    return true;
}

ElementType popQueue(Queue *queue)
{
    ElementType data;
    QueueNode *temp = NULL;

    if (queue->head == NULL){
        printf("Empty Queue!\n");
    }
    else {
        data = queue->head->data;
        temp = queue->head;
        queue->head = queue->head->next;

        free(temp);
    }

    return data;
}

int main(int argc, char **argv)
{
    int temp;
    Queue *DemoQueue;

    initQueue(&DemoQueue);

    for (temp=0; temp<10; temp++){
        pushQueue(DemoQueue, temp);
    }

    for (temp=0; temp<=10; temp++){
        printf("%d ", popQueue(DemoQueue));
    }

    return 0;
}