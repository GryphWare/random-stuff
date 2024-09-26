#include <stdio.h>

char *reverse(const char* user, int size){
    
    char* results[size];
    
    int index = 0;
    
    for (int i = size - 1; i >= 0; --i){
        results[index] = user[i];
        index++;
    }
    return results;
}
int main(){

   int size;
   
   scanf("%d", &size);
   
   char user[size];
   
   fgets(user, size, stdin);
   
   char *result[] = reverse(user, size); 
   return 0; 
}
