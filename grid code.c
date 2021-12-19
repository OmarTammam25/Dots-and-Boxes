#include <stdio.h>

void printGrid(){
    int conter =1;
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(".    ");
        }
        printf("\n");
    }
}