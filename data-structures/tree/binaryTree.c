#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct _BinaryTreeNode{
    ElementType data;
    struct _BinaryTreeNode *left;
    struct _BinaryTreeNode *right;
}BinaryTreeNode;

typedef struct _BinaryTree{
    BinaryTreeNode *root;


}BinaryTree;

bool initTree(BinaryTree **tree)
{
    *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    (*tree)->root = NULL;
}

bool insertTree(BinaryTree *tree, ElementType newData)
{
    BinaryTreeNode *current = tree->root;
    BinaryTreeNode *parent = NULL;
    BinaryTreeNode *newNode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;

    if (current == NULL){
        tree->root = newNode;
    }
    else {
        while (current != NULL){
            parent = current;

            if (newData < current->data){
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (newData < parent->data){
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
    }

    return true;
}

void preOrder(BinaryTreeNode *node)
{
    if (node){
        printf("%d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

int main(int argc, char **argv)
{
    int temp, data;
    BinaryTree *DemoTree;

    initTree(&DemoTree);

    for (temp=0; temp<5; temp++){
        printf("Input:\n");
        scanf("%d", &data);
        insertTree(DemoTree, data);
        printf("Input Success!\n");
    }

    preOrder(DemoTree->root);

    return 0;
}