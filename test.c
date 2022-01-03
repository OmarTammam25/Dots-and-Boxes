#include <stdio.h>

int main(){

    FILE *Iptr = NULL;
    Iptr = fopen("ASCII ART!.txt", "r");
    if (Iptr == NULL) printf("error printing file");

    char readImage[128];
    while(fgets(readImage, sizeof(readImage), Iptr) != NULL){
        printf("%s", readImage);
    }
    return 0;

}