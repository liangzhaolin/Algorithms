#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct _ListNode{
    ElementType data;
    struct _ListNode *prev;
    struct _ListNode *next;
}ListNode;

typedef struct _DoublyLinkedList{
    ListNode *head;
    
    unsigned int length;
}DoublyLinkedList;

bool initList(DoublyLinkedList **list)
{
    *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    
    (*list)->head = NULL;
    (*list)->length = 0;

    return true;
}

bool insertList(DoublyLinkedList *list, ElementType newData)
{
    ListNode *current = list->head;

    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (current == NULL){
        list->head = newNode;
    }
    else {
        while (current->next != NULL){
            current = current->next;
        }

        newNode->prev = current;
        current->next = newNode;
    }

    return true;
}

void displayList(DoublyLinkedList *list)
{
    ListNode *current = list->head;
    if (current == NULL){
        printf("Empty!\n");
    }
    else {
        do {
            printf("Data: %d\n", current->data);
            current = current->next;
        } while(current != NULL);
    }
}

int main(int argc, char **argv)
{
    int i;

    DoublyLinkedList *DemoList;

    initList(&DemoList);

    for (i=0; i<10; i++){
        insertList(DemoList, i);
    }

    displayList(DemoList);

    return 0;
}