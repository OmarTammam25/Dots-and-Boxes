#include <stdio.h>
#define ROWS 5
#define COLS 5


// loop lineArray, check number of Xs in array until you get
// x number n(which is lineNum)
// put 1 in [i][j+1]
// but first check if j+1 == num of colms
// if true put 1 in [i+1][0]
void addLineToArray(int rows, int cols, int lineArray[][COLS], int lineNum){
    int count =0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if(lineArray[i][j] == 2){
                count++;
                if(count == lineNum && j+1 < COLS){
                    lineArray[i][j+1] = 1;
                    return;
                }else if(count == lineNum){
                    lineArray[i+1][0] = 1;
                    return;
                }
            }
        }
        
    }
}
//TODO make it a header file and put it in main :)

// this main is just to test the code.

/*
int main(){

    // store which line has been drawn till now. for 2*2 board
    int lineArray[ROWS][COLS] = {
        {2,0,2,0,2},
        {0,2,0,2,0},
        {2,0,2,0,2},
        {0,2,0,2,0},
        {2,0,2,0,2}
    }; // the 2 represents the Xs. TODO make size variable depending on the size of the board
    int lineNum;
    printf("Please enter the line you want to select: ");
    scanf("%d", &lineNum);
    addLineToArray(ROWS,COLS,lineArray,lineNum);
    return 0;
}
*/