#include <stdio.h>
#include <stdbool.h>

#define table_size 100

unsigned int change (int num){
    return num % table_size;
}

int check (const int* nums, int size){
    
    int total = 0;
    
    bool falsearr[table_size] = {false};
    
    for(size_t i = 0; i < size; ++i){
        
        unsigned int hash = change(nums[i]);
        
        if (falsearr[hash]){
            
            total++;
            continue;
        } else {
            falsearr[hash] = true;
        }
    };
    
    
    
    return total;
}
int main(){
    
    int nums[] = {1, 1, 2, 3, 5, 8, 2};
    
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = check(nums, size);
    
    printf("%d", result); //2
    
    return 0;
}
