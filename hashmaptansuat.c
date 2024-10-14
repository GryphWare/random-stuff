#include <stdio.h>
#include <stdlib.h>

#define table_size 1000

typedef struct Node{
    int data;
    int count;
    struct Node *next;
} Node;

typedef struct hashmap{
    Node *table[table_size];
}hashmap;

void inithashmap(hashmap *map){
    for(size_t i = 0; i < table_size; i++){
        map->table[i] = NULL;
    }
}

unsigned int hash(int value){
    return value % table_size;
}
void insert(hashmap *map, int value){
    unsigned int index = hash(value);
    Node *node = map->table[index];
    
    while (node){
        if(node->data == value){
            node->count++;
            return;
        }
            node = node ->next;
    }
    Node *new = (Node*) malloc (sizeof(Node));
    
    new -> data = value;
    new -> count = 1;
    new -> next = NULL;
    
    new -> next = map->table [index];
    map->table[index] = new;
}

void print(hashmap *map){
    for (size_t i = 0; i < table_size; i++){
        Node *current = map->table[i];
        while(current){
            printf("so %d %d lan\n", current->data, current->count);
            current = current->next;
        }
    }
    printf("hoat dong ne :3 \n");
}
void freeAll (hashmap *map){
    for (size_t i = 0; i < table_size; i++){
        Node *current = map->table[i];
        while(current){
            Node *temp = current;
            current = current -> next;
            free(temp);
        }
    }
    printf("du ma xem anime th <3");
}
int main() {
    hashmap map;
    inithashmap(&map);
    
    int arr[] = {1, 1, 2, 3, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    for (size_t i = 0; i < size; i++){
        insert(&map, arr[i]);
    }
    
    print(&map);
    freeAll(&map);
    return 0;
}