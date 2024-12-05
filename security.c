#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void clear(){
    int c;
    while(((c = getchar()) != '\n') && c != EOF);
}

int main() {
    int size;
    char buffer[100];

    char input[10];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        char *end;
        long temp = strtol(input, &end, 10);
        if (*end != '\n' && *end != '\0' || temp <= 0 || temp > 1024 * 1024 * 10 / sizeof(int)) {
            snprintf(buffer, sizeof(buffer), "wrong size\n");
            fprintf(stderr, "%s", buffer);
            return 1;
        }
        size = (int) temp;
    } else {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        snprintf(buffer, sizeof(buffer), "Memory allocation error\n");
        fprintf(stderr, "%s", buffer);
        return 1;
    }

    for (size_t i = 0; i < size; i++) {
        if (scanf("%d", &(arr[i])) != 1) {
            snprintf(buffer, sizeof(buffer), "Invalid input\n");
            fprintf(stderr, "%s", buffer);
            clear();
            free(arr);
            return 1;
        }
    }
    //code here
    bool none = true;
    for(size_t i = 0; i < size; i++){
        if((arr[i] % 2 == 0) && (i % 2 == 0)){
            fprintf(stdout, "%d ", arr[i]);
            none = false;
        }
    }
    
    if(none != false){
        snprintf(buffer, sizeof(buffer), "NONE\n");
        fprintf(stdout, "%s", buffer);
    }
    
    memset(arr, 0, size * sizeof(int));
    free(arr);
    arr = NULL;

    return 0;
}