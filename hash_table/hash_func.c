#include <stdio.h>

#define MAX_CAPACITY 5000

/**
 * struct Ht_item - HashTable item
 * @key: key
 * @value: value
 */
typedef struct Ht_item
{
    char *key;
    char *value;
} Ht_item;

/**
 * struct HashTable - HashTable
 * @size: size of HashTable
 * @count: number of buckets filled
 * @items: pointer to HashTable items
 */
typedef struct HashTable
{
    // Contain array of pointers to items
    Ht_item **items;
    int size;
    int count;
} HashTable;

/** 
 * create_item - Function for allocating and creating items
 * @Description: Create items by allocating memory for a key and value
 * and return a pointer to them
 * @key: key
 * @value: value
 * Return: Returns HashTable item
 */
Ht_item create_item(char *key, char *value)
{
    // Creates a pointer to a new HashTable item
    Ht_item *item = (Ht_item*) malloc(sizeof(Ht_item));
    item->key = (char*) malloc(sizeof(key) + 1);
    item->value = (char*) malloc(sizeof(value) + 1);
    strcpy(item->key, key);
    strcpy(item->value, value);

    return (item);
}

/**
 * create_table - Create a table by allocating memory
 * and setting size, count and items
 * @size: size of HashTable
 * Return: Returns table
 */
HashTable *create_table(int size)
{
    int i;

    HashTable *table = (HashTable *) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item **) calloc(table->size, sizeof(Ht_item*));

    for (i = 0; i < table->size; i++)
    {
        table->items[i] = NULL;
    }

    return (table);
}

/**
 * free_item - Free table item
 * @item: pointer to item
 * Return: void
 */
void free_item(Ht_item *item)
{
    free(item->key);
    free(item->value);
    free(item);
}

/**
 * free_table - Free table
 * @table: pointer to table
 * Return: void
 */
void free_table(HashTable *table)
{
    int i;

    for (i = 0; i < table->size; i++)
    {
        Ht_item *item = table->items[i];
        
        if (item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);
}

/* Defining a hash function */
unsigned long hash_function(char *str)
{
    unsigned long i;
    int j;

    i = 0;

    for (j = 0; str[j]; j++)
    {
        i += str[j];
    }

    return (i % MAX_CAPACITY);
}



int main(int argc, char *argv[])
{
    (void) argc;

    printf("Index is %lu\n", hash_function(argv[1]));
    return (0);
}
