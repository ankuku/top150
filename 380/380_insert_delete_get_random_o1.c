# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <string.h>


# define TABLE_SIZE 10

typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct HashTable {
    HashNode** table;
} HashTable;

typedef struct {
    int* arr;
    int size;
    int capacity;
    HashTable* map;    
} RandomizedSet;

int hashFunctionIndex(int key) {
    return abs(key % TABLE_SIZE);
}

HashTable* createHashTable() {
    HashTable* map = (HashTable*) malloc(sizeof(HashTable));
    map->table = (HashNode**) calloc(TABLE_SIZE, sizeof(HashNode*));
    return map;
}

void insert(HashTable* map, int key, int value) {
    int hashIndex = hashFunctionIndex(key);
    HashNode* newNode = (HashNode*) malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->table[hashIndex];
    map->table[hashIndex] = newNode;
}

HashNode* search(HashTable* map, int key) {
    int hashIndex = hashFunctionIndex(key);
    HashNode* node = map->table[hashIndex];
    while (node != NULL) {
        if (node->key == key) return node;
        node = node->next;
    }
    return NULL;
}

void removeNode(HashTable* map, int key) {
    int hashIndex = hashFunctionIndex(key);
    HashNode* newNode = map->table[hashIndex];
    HashNode* prev = NULL;

    while (newNode != NULL && newNode->key != key) {
        prev = newNode;
        newNode = newNode->next;
    }
    if (newNode == NULL) return;

    if (prev == NULL) {
        map->table[hashIndex] = newNode->next;
    }
    else {
        prev->next = newNode->next;
    }
    free(newNode);
}

void freeHashTable(HashTable* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* newNode = map->table[i];
        while (newNode != NULL) {
            HashNode* temp = newNode;
            newNode = newNode->next;
            free(temp);
        }
    }
    free(map->table);
    free(map);
}

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* obj = (RandomizedSet*) malloc(sizeof(RandomizedSet));
    obj->arr = (int*) malloc(10* sizeof(int));
    obj->size = 0;
    obj->capacity = 10;
    obj->map = createHashTable();
    return obj;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    if (search(obj->map, val) != NULL) {
        return false;
    }

    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = (int*) realloc(obj->arr, obj->capacity * sizeof(int));
    }

    obj->arr[obj->size] = val;
    insert(obj->map, val, obj->size);
    obj->size++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    HashNode* newNode = search(obj->map, val);
    if (newNode == NULL) {
        return false;
    }

    int index = newNode->value;
    int last = obj->arr[obj->size - 1];

    obj->arr[index] = last;

    HashNode* lastNode = search(obj->map, last);
    lastNode->value = index;

    obj->size--;
    removeNode(obj->map, val);
    return true;

}

int randomizedSetGetRandom(RandomizedSet* obj) {
    if (obj->size == 0) return -1;
    int randIndex = rand() % obj->size;
    return obj->arr[randIndex];
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj->arr);
    freeHashTable(obj->map);
    free(obj);
}

int main() {
    // Command list and arguments
    char* commands[] = {"RandomizedSet", "remove", "remove", "insert", "getRandom", "remove", "insert"};
    int args[][1] = {{}, {0}, {0}, {0}, {}, {0}, {0}};
    int n = 7;

    // Expected output: [null, false, false, true, 0, true, true]
    RandomizedSet* obj;
    for (int i = 0; i < n; i++) {
        if (strcmp(commands[i], "RandomizedSet") == 0) {
            obj = randomizedSetCreate();
            printf("null\n");
        } else if (strcmp(commands[i], "insert") == 0) {
            bool result = randomizedSetInsert(obj, args[i][0]);
            printf(result ? "true\n" : "false\n");
        } else if (strcmp(commands[i], "remove") == 0) {
            bool result = randomizedSetRemove(obj, args[i][0]);
            printf(result ? "true\n" : "false\n");
        } else if (strcmp(commands[i], "getRandom") == 0) {
            int randomValue = randomizedSetGetRandom(obj);
            printf("%d\n", randomValue);
        }
    }

    randomizedSetFree(obj);

    return 0;
}