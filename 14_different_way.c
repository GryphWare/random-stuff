#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* prefix(const char **user, int size){
    
    bool tempSize[256] = {false};
    bool charSize[256] = {false};
    
    for (const char *c = user[0]; *c; c++){
        tempSize[(unsigned char)*c] = true;
    }
    
    for(size_t i = 1; i < size; i++){
        
        memset(charSize, 0, sizeof(charSize));
        
        for (const char *c = user[i]; *c; c++){
            if(tempSize[(unsigned char)*c]){
                charSize[(unsigned char)*c] = true;
            }
        }
        memcpy(tempSize, charSize, sizeof(tempSize));
    }
    
    static char result[256];
    int index = 0;
    for(size_t i = 0; i < 256; i++){
        if(tempSize[i]){
            result[index++] = (char)i;
        }
    }
    
    result[index++] = '\0';
    
    return result;
}


int main() {
    
    char *user[] = {"flower", "flow", "fly"};
    int size = sizeof(user) / sizeof(user[0]);
    
    printf("%s", prefix(user, size));
    
    return 0;
}