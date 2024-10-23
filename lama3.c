#include <stdio.h>
#include <string.h>

int getRomanValue (char c){
    switch (c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
}

int roman_converted(const char *user){
    
    int total = 0;
    int size = strlen(user);
    int current, next;
    
    for (size_t i = 0; i < size; i++){
        current = getRomanValue(user[i]);
        next = getRomanValue(user[i+1]);
        
        if (current < next){
            total -= current;
        } else {
            total += current;
        }
        }
    return total;
    }

int main() {
    
    char user[100];
    scanf("%s", user);
    
    printf("%d", roman_converted(user));
    
    return 0;
}