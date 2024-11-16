#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define hash_table 100

typedef struct entry{
    int indexOfFood;
    char *food_hash;
    float priceOfFood;
    struct entry *Next;
} entry;

typedef struct hashmap{
    entry *table[hash_table];
} hashmap;

void initHashmap(hashmap *map){
    for(size_t i = 0; i < hash_table; i++){
        map->table[i] = NULL;
    }
}

unsigned int hash_key(char *key){
    
    unsigned int hash = 0;
    while (*key){
        hash = (hash << 5) + *key++;
    }
    return hash % hash_table;
}
entry *create(int index, char* food, float price){
    
    entry *new = (entry*) malloc (sizeof(entry));
    
    new->indexOfFood = index;
    new->food_hash = strdup(food);
    new->priceOfFood = price;
    new->Next = NULL;
    
    return new;
}
void insert(hashmap *map, int index, char* food, float price){
    
    unsigned int hash_index = hash_key(food);
    entry *newEntry = map->table[hash_index];
    
    while(newEntry){
        if(strcmp(newEntry->food_hash, food) == 0){
            newEntry->indexOfFood = index;
            newEntry->priceOfFood = price;
            return;
        }
        newEntry = newEntry->Next;
    }
    entry *NewNode = create(index, food, price);
    NewNode->Next = map->table[hash_index];
    map->table[hash_index] = NewNode;
}

bool isExist(hashmap *map, char* user){
    
    unsigned int hash_index = hash_key(user);
    entry *newEntry = map->table[hash_index];
    
    while (newEntry){
        if(strcmp(newEntry->food_hash, user) == 0){
            return true;
        }
        newEntry = newEntry->Next;
    }
    return false;
}

float getPrice (hashmap *map, char* food){
    
    unsigned int hash_index = hash_key(food);
    entry *newEntry = map->table[hash_index];
    
    while (newEntry){
        if(strcmp(newEntry->food_hash, food) == 0){
            return newEntry->priceOfFood;
        }
        newEntry = newEntry->Next;
    }
    return -1;
}
int main(){
    
    hashmap map;
    initHashmap(&map);
    
    insert(&map, 1, "Nachos", 6.00);
    insert(&map, 2, "Pizza", 6.00);
    insert(&map, 3, "Cheeseburger", 10.00);
    insert(&map, 4, "Water", 4.00);
    insert(&map, 5, "Coke", 5.00);
    
    printf("1.Nachos and Pizza: 6 usd\n");
    printf("2.Cheeseburger: 10 usd\n");
    printf("3.Water: 4 usd\n");
    printf("4.coke: 5 usd\n");
    
    float total = 0.00;
    
    printf("Nhap do an limit la 4: ");
    
    for (size_t i = 0; i < 4; i++){
        char user[20];
        scanf("%s", user);
        
        if(isExist(&map, user)){
            total += getPrice(&map, user);
        } else {
            printf("ko ton tai! \n");
            break;
        }
    }
    
    printf("total: %f", total);
    
    return 0;
}