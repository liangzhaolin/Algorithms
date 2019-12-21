#include <stdio.h>
#include <stdlib.h>

#define LoadFactor 0.8
#define HashSize 32

typedef int ValueType;
typedef int KeyType;
typedef unsigned int (*HashFunc)(KeyType value);

typedef enum _State{
    Empty,
    Valid,
    Invalid
}State;

typedef struct _HashNode{
    State state;
    KeyType key;
    ValueType value;
    struct _HashNode *next;
}HashNode;

typedef struct _HashTable{
    HashNode *data[HashSize];
    int size;
    HashFunc hashFunc;
}HashTable;

unsigned int defaultHashFunc(KeyType key)
{
    return (unsigned int)key%31;
}

void initHashTable(HashTable **ht)
{
    *ht = (HashTable *)malloc(sizeof(HashTable));
    (*ht)->hashFunc = defaultHashFunc;

    (*ht) ->size = 0;

    for (int i=0; i<HashSize; i++){
        (*ht)->data[i] = NULL;
    }
}

void insertHashTable(HashTable *ht, KeyType key, ValueType value)
{
    HashNode *newNode;
    HashNode *cur;
    unsigned int index;

    if (ht->size >= HashSize * LoadFactor){
        perror("Expand loadFactor!\n");
    }

    index = ht->hashFunc(key);
    newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->state = Valid;
    newNode->next = NULL;
    
    if (ht->data[index] == NULL){
        ht->data[index] = newNode;
    }
    else {
        cur = ht->data[index];
        while (cur->next != NULL){
            cur = cur->next;
        }

        cur->next = newNode;
    }
    
}

void findHashTable()
{
    
}

void showTable(HashTable *ht)
{
    HashNode *cur;

    for (int i=0; i<HashSize; i++){
        printf("Index:%d    ", i);

        if (ht->data[i] == NULL){
            printf("NULL\n");
        }
        else {
            cur = ht->data[i];
            while (cur != NULL){
                printf("%d$%d   ", cur->key, cur->value);
                cur = cur->next;
            }
            printf("\n");
        }
    }
}

int main(int argc, char **argv)
{
    HashTable *table = NULL;

    initHashTable(&table);

    insertHashTable(table, 2, 12);
    insertHashTable(table, 33, 43);
    insertHashTable(table, 5, 15);
    insertHashTable(table, 9, 19);

    showTable(table);

    return 0;
}