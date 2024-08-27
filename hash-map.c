#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 10

//tao hasmap dua vao struct Entry
typedef struct Entry{
    char *key; //bien str
    int value; //bien gia tri
    struct Entry *next; //tao mang lien ket
    } Entry;

//tao struct hasmap dua vao Entry
typedef struct hashmap {
    Entry *table[TABLE_SIZE]; //goi mang lien ket voi size la table_size;
    }Hashmap;
    
//tinh index hash
unsigned int hash(char *key){
    unsigned int hash = 0;
    while (*key){
        hash = (hash << 5) + *key++;
        }
    return hash % TABLE_SIZE; //phai chuyen str thanh int (quy tac 2)
    }

//ham initHashmap;
void initHashmap(Hashmap *map){
    for (size_t i = 0; i < TABLE_SIZE; i++){
        map->table[i] = NULL; //hashmap la phai null het (qui luat 1)
        }
    }
    
//tao entry
Entry *create(char *key, int value){
    Entry *New = (Entry*) malloc (sizeof(Entry));
    New->key = strdup(key); //toi ko hieu
    New->value = value;
    New->next = NULL; //cuoi day la null
    return New;
    }
//create qua insert
void insert (Hashmap *map, char *key, int value){
    unsigned int index = hash(key);
    Entry *entry = map->table[index]; //thang entry no se nhan map de xet
    //loop
    while(entry){
        //xet xem co bang nhau hay chua, roi gan gia tri vo
        if (strcmp(entry->key, key) == 0){
            entry->value = value;
            return;
            }
        entry = entry->next;
        }
        
    //key ko ton tai
    Entry *newEntry = create(key, value); //tao 
    newEntry->next = map->table[index]; //them o phia cuoi
    map->table[index] = newEntry; //xac dinh cuoi la size index;
    }

//tao sreach de in
int sreach(Hashmap *map, char *key){
    unsigned int index = hash(key);
    Entry *entry = map->table[index];
    
    while (entry){
        if (strcmp(entry->key, key) == 0){
            return entry->value; //in value ma
            }
        entry = entry->next;
        }
    return -1;
    printf("Ki co");
    }
    
//ham xoa
void delete_ (Hashmap *map, char *key){
    unsigned int index = hash(key);
    Entry *entry = map->table[index];
    Entry *prev = NULL;
    
    while (entry){
        if(strcmp(entry->key, key) == 0){
           if (prev) {
            prev->next = entry->next; //ko phai phan tu dau
            } else {
                map->table[index] = entry->next; //phan tu dau
                }
           free(entry->next); //key truoc
           free(entry); //entry sau
            }
        prev = entry;
        entry = entry->next; //neu ko tim dc
        }   
    }
    
/* Xin lỗi nhé, Amanai. Hiện tại không phải tôi đang tức giận vì cô hay gì đâu. Tôi cũng chả hận bất cứ ai cả. Chỉ là hiện giờ tôi cảm thấy... Thế giới hiện đang rất, rất dễ chịu. "Thiên thượng thiên hạ, duy ngã độc tôn".*/

void freeAll(Hashmap *map){
    for (size_t i = 0; i < TABLE_SIZE; i++){
        Entry *entry = map->table[i];
        while(entry){
            Entry *temp = entry;
            entry = entry->next;
            free(temp->key);
            free(temp);
            }
        }
    }

int main(){
    
    clock_t start = clock();
    
    //goi 
    Hashmap map;   
    //tao node hashmap la null qua initHashmap
    initHashmap(&map);
    
    insert(&map, "Chanh", 18);
    
    //in
    printf("what?: %d\n", sreach(&map, "help"));
    
    //xoa
    delete_(&map, "Chanh");
    
    printf("what?: %d\n", sreach(&map, "help"));
    
    freeAll(&map);
    
    clock_t end = clock();
    
    double time_taken = ((double)(end-start)) / CLOCKS_PER_SEC;
    
    printf("%4.10f", time_taken);
    
    
    
    return 0;
    }