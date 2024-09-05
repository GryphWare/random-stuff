#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//ham cap phat them bo nho if ko du
void appendTo(char** str, size_t* index, const char* str1){
    size_t size = strlen(str1); //so luong byte char trong mang
    
    //nhan so luong bo nho
    if (*index < (strlen(*str) + size + 2)){
        *index = (strlen(*str) + size + 2) * 2;
        *str= (char*)realloc(*str, *index);
    }
    
    strcat(*str, str1); //them str1 vao arr str
    strcat(*str, ","); //them wtf?
    
}

char* summary(const int* nums, int size){
    
    size_t index = 1000; //du kien so size ban dau
    char* str = (char*) malloc(index * sizeof(char)); //tao mang dong
    
    int start = 0; //bat dau
        str[0] = '\0'; 
    
    for (size_t i = 1; i <= size; i++){
        if(i - 1 == start || (nums[i] != nums[i - 1] +1)){
            char temp[50];
            if(i - 1 == start){
                sprintf(temp, "%d", nums[start]); //so trung nhau hoac ko phai so ke tiep
            } else {
                sprintf(temp, "%d -> %d", nums[start], nums[i - 1]); //so ke tiep
            }
            appendTo(&str, &index, temp); //ham de them
            start = i; //thay doi theo i
        }
    }
    return str; //tra ve
}

int main() {
    
    int nums[] = {1, 2, 3, 6, 7}; //ran
    
    int size = sizeof(nums) /sizeof(nums[0]); //tinh size
    
    char *results = summary(nums, size);//ham return str
    
    printf("%s\n", results);
    
    return 0;
}