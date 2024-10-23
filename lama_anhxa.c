#include <stdio.h>
#include <string.h>

int converted (const char *user){
    
    int roman_value[200] = {0};
    
    roman_value['I'] = 1;
    roman_value['V'] = 5;
    roman_value['X'] = 10;
    roman_value['L'] = 50;
    roman_value['C'] = 100;
    roman_value['D'] = 500;
    roman_value['M'] = 1000;
    
    int total = 0;
    int size = strlen(user);
    
    for (size_t i = 0; i < size; i++){
        if(i + 1 < size && roman_value[user[i]] < roman_value[user[i+1]]){
            total -= roman_value[user[i]];
        } else {
            total += roman_value[user[i]];
        }
    }
    return total;
}
int main() {
    
    char user[1000];
    //user nhap o day
    scanf("%s", user);
    
    //in
    printf("%s la %d\n", user, converted(user));
    return 0;
}