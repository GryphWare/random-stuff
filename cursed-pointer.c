#include <stdio.h>

int main(){   
    int a = 5;
    
    int *p = &a;    
    int **pp = &p;
    int ***ppp = &pp;
    int ****pppp = &ppp;
    int *****ppppp = &pppp;
    int ******pppppp = &ppppp;
    int *******ppppppp = &pppppp;
    
    p = NULL; // i dont need it btw
    
    printf("%p", ppppppp);
    
    return 0;
    }