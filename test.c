#include <stdio.h>

int main(){
    goto load;
    int num_row = 0;
    int num_col = 0;
    int turn = 0;
    int rowGridArray = 0;
    int colGridArray = 0;
  /*   player1.name = "omar";
    player2.name = "omar"; */



    FILE *fptr;
    fptr = fopen("saveData.bin", "rb");

    if(fptr == NULL){
        printf("error!!");
        return 1;
    }
    fread(&num_row, sizeof(int), 1, fptr);
    fread(&num_col, sizeof(int), 1, fptr);
    // fread(&gridarray, sizeof(int), sizeof(gridarray), fptr);
    fread(&turn, sizeof(int), 1, fptr);
    fread(&rowGridArray, sizeof(int), 1, fptr);
    fread(&colGridArray, sizeof(int), 1, fptr);
/*     fread(&player1, sizeof(struct player), 1, fptr);
    fread(&player2, sizeof(struct player), 1, fptr); */
    fclose(fptr);    
    printf("%d", num_row);
}