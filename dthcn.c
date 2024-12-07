#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define buffer 50
#define limit_size (1024 * 1024 * 10) / sizeof(int);
#define input_size 20

void clear() {
    int c;
    while((c = getchar() != '\n') && (c != EOF));
}
int main(){
    
    long long int height, weight; //truyen tham so neu char sang int
    char num_height[input_size], num_weight[input_size]; //buoc dau bao mat
    char printf_buffer[buffer]; //buffer de in
    
    //input
    fgets(num_height, sizeof(num_height), stdin);
    fgets(num_weight, sizeof(num_weight), stdin);
    
    //neu user co nhap \n
    if((num_height[0] == '\n') || (num_weight[0] == '\n')){
        snprintf(printf_buffer, sizeof(printf_buffer), "User pressed Enter, that not allowed!\n");
        fprintf(stderr, "%s", printf_buffer);
        clear(); //xoa bo dem
        return 1;
    }
    
    //xoa bot ky tu \n neu co
    num_height[strcspn(num_height, "\n")] = '\0';
    num_weight[strcspn(num_weight, "\n")] = '\0';
    
    //ham de chuyen char sang int
    char *end;
    
    height = strtol(num_height, &end, 10);
    if(*end != '\n' && *end != '\0'){
        snprintf(printf_buffer, sizeof(printf_buffer), "Height cant converte char to int!\n");
        fprintf(stderr, "%s", printf_buffer);
        clear();
        return 1;
    }
    
    *end = '\0'; //lam rong
    
    weight= strtol(num_weight, &end, 10);
    if((*end != '\n' && *end != '\0')){
        snprintf(printf_buffer, sizeof(printf_buffer), "weight cant converte char to int!\n");
        fprintf(stderr, "%s", printf_buffer);
        clear();
        return 1;
    }
    
    snprintf(printf_buffer, sizeof(printf_buffer), "%lld", (height + weight) * 2);
    fprintf(stdout, "chu vi hcn: %s\n", printf_buffer);
    
    snprintf(printf_buffer, sizeof(printf_buffer), "%lld", (height * weight));
    fprintf(stdout, "dien tich hcn: %s\n", printf_buffer);
    
    return 0;
}