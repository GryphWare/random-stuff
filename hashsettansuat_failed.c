#include <stdio.h>
#include <stdbool.h>

#define table 1000

bool FalseArr[table] = {false};
int count[table] = {0};

unsigned int hash(int num){
    return num % table;
}

void hashfunction(int num){
    unsigned int index = hash(num);
    count[index]++;
    printf("so %d hien %d lan \n", num, count[index]);
}

int main(){
    
    int arr[] = {1, 1, 2, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    for (size_t i = 0; i < size; i++){
        hashfunction(arr[i]);
    }
    return 0;
}