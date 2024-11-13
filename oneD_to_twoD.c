#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int oneD[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //3x3
    
    int row = 3, column = 3;
    
    int **twoD = (int**) malloc (column * sizeof(int*)); //lap 2D
    int index_oneD = 0;
    
    for (size_t j = 0; j < column; j++){
        twoD[j] = (int*) malloc (row * sizeof(int));
        for(size_t i = 0; i < row; i++){
            twoD[j][i] = oneD[index_oneD];
            index_oneD++;
        }
    }
    
    for (size_t i = 0; i < row; i++){
        for (size_t j = 0; j < row; j++){
            printf("%d", twoD[i][j]);
         }
        printf("\n");
    }
    
    for (size_t i = 0; i < row; i++){
        free(twoD[i]);
    }
    free(twoD);
    
    return 0;
}