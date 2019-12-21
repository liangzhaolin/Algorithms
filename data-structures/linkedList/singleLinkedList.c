#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct _ListNode {
    ElementType data;
    struct _ListNode *next;
} ListNode;

typedef struct _LinkedList {
    ListNode *head;

    unsigned int length;
} LinkedList;

bool initList(LinkedList **list)
{
    *list = (LinkedList *)malloc(sizeof(LinkedList));

    (*list)->head = NULL;

    return true;
}

bool insertList(LinkedList *list, ElementType newData)
{
    int temp = 1;

    ListNode *current = list->head;
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->data = newData;

    if (current == NULL){
        newNode->next = NULL;
        list->head = newNode;
    }
    else {
        while (current->next != NULL){
            current = current->next;
        }

        current->next = newNode;
        current->next->next = NULL;
    }

    return true;
}

bool deleteList(LinkedList *list, int pos)
{
    int temp=1;
    ListNode *previous = NULL;
    ListNode *current = list->head;
    if (current == NULL){
        printf("Empty!\n");
    }
    else if (pos == 1){
        list->head = current->next;
        free(current);
    }
    else {
        while ((current!=NULL)&&(temp<pos)){
            temp++;
            previous = current;
            current = current->next;
        }

        if (current == NULL){
            printf("Not Exist!\n");
        }
        else {
            previous->next = current->next;
            free(current);
        }
    }
}

void displayList(LinkedList *list)
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

    LinkedList *DemoList = NULL;

    initList(&DemoList);

    for (i=0; i<10; i++){
        insertList(DemoList, i);
    }

    displayList(DemoList);

    printf("\n\n");

    deleteList(DemoList, 4);

    displayList(DemoList);

    return 0;
}