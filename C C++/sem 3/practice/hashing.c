#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10000

typedef struct HashTable
{
    int *items;
} HashTable;

int hashFunction(int key)
{
    return key % SIZE;
}

void insertItem(HashTable *table, int key)
{
    int index = hashFunction(key);
    while (table->items[index] != -1 && table->items[index] != key)
    {
        index = (index + 1) % SIZE;
    }
    table->items[index] = key;
}

bool searchItem(HashTable *table, int key)
{
    int index = hashFunction(key);
    while (table->items[index] != -1)
    {
        if (table->items[index] == key)
        {
            return true;
        }
        index = (index + 1) % SIZE;
    }
    return false;
}

void deleteItem(HashTable *table, int key)
{
    int index = hashFunction(key);
    while (table->items[index] != -1)
    {
        if (table->items[index] == key)
        {
            table->items[index] = -2;
            return;
        }
        index = (index + 1) % SIZE;
    }
}

int main()
{
    int q;
    scanf("%d", &q);

    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->items = (int *)calloc(SIZE, sizeof(int));

    for (int i = 0; i < q; i++)
    {
        int queryType;
        scanf("%d", &queryType);

        switch (queryType)
        {
        case 1:
        {
            int x;
            scanf("%d", &x);
            insertItem(table, x);
            break;
        }
        case 2:
        {
            int y;
            scanf("%d", &y);
            printf("%s\n", searchItem(table, y));
            fflush(stdout); // Flush the output buffer
            break;
        }
        case 3:
        {
            int z;
            scanf("%d", &z);
            deleteItem(table, z);
            break;
        }
        }
    }

    return 0;
}