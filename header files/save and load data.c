#include <stdio.h>

void saveData(int num_row, int num_col, /* int gridarray[][2 * num_col -1] */ int turn, int rowGridArray, int colGridArray)
{ // struct player *player1, struct player *player2){
    FILE *fptr = NULL;

    fptr = fopen("saveData.bin", "wb");

    if(fptr == NULL){
        printf("error!!");
        return 1;
    }
    fwrite(&num_row, sizeof(int), 1, fptr);
    fwrite(&num_col, sizeof(int), 1, fptr);
    //fwrite(&gridarray, sizeof(int), sizeof(gridarray), fptr);
    fwrite(&turn, sizeof(int), 1, fptr);
    fwrite(&rowGridArray, sizeof(int), 1, fptr);
    fwrite(&colGridArray, sizeof(int), 1, fptr);
    fwrite(&player1, sizeof(struct player), 1, fptr);
    fwrite(&player2, sizeof(struct player), 1, fptr);
    fclose(fptr);
}
 
void loadData(int *num_row, int *num_col, /* int *gridarray[][2 * num_col -1],  */int *turn, int *rowGridArray, int *colGridArray) //struct player *player1, struct player *player2)
{
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
 
int main(){
    int num_row = 3;
    int num_col = 4;
    int gridArray[5][5] = {
        {3,1,2,0,2},
        {3,2,1,2,0},
        {4,0,2,0,2},
        {0,2,0,2,0},
        {2,0,2,0,2}
    };
    int turn = -3;
    int rowGridArray = 6;
    int colGridArray = 6;
    typedef struct{
        int score;
        char name[10];
    }player;
    player player1;
    player player2;
    player1.score = 1;
    player2.score = 1;
  /*   player1.name = "omar";
    player2.name = "omar"; */

    //saveData(num_row, num_col, turn, rowGridArray, colGridArray);
    loadData(&num_row, &num_col,&turn, &rowGridArray, &colGridArray);
    printf("%d", num_row);
    return 0;
}