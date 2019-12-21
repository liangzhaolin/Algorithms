#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct _StackNode{
    ElementType data;

    struct _StackNode *next;
}StackNode;

typedef struct _Stack{
    StackNode *top;
    StackNode *bottom;

    unsigned int number;
}Stack;

bool initStack(Stack **stack)
{
    *stack = (Stack *)malloc(sizeof(Stack));

    (*stack)->top = NULL;
    (*stack)->bottom = NULL;
}

bool push(Stack *stack, ElementType newData)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = newData;

    if (stack->bottom == NULL){
        stack->bottom = newNode;
        stack->top = newNode;
        stack->top->next = stack->bottom;   
    }
    else {
        newNode->next = stack->top;
        stack->top = newNode;
    }

    return true;
}

ElementType pop(Stack *stack)
{
    StackNode *temp = NULL;
    ElementType data;

    if (stack->top == NULL){
        printf("Empty Stack!\n");
    }
    else if (stack->top == stack->bottom){
        temp = stack->top;
        data = stack->top->data;

        free(temp);

        stack->bottom = NULL;
        stack->top = NULL;
    }
    else {
        temp = stack->top;
        data = stack->top->data;

        stack->top = stack->top->next;
        free(temp);
    }

    return data;
}

int main(int argc, char **argv)
{
    int temp;
    Stack *DemoStack;

    initStack(&DemoStack);

    for (temp=1; temp<=10; temp++){
        push(DemoStack, temp);
    }

    for (temp=0; temp<=10; temp++){
       printf("%d ", pop(DemoStack));
    }

    return 0;
}