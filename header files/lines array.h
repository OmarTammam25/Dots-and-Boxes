//#include <stdio.h>

// generate array which will hold the lines. dynamic array ;)
void generateGridArray(int n, int m, int gridArray[n+n-1][m+m-1]){
    
    for (int i = 0; i < n+n-1; i++)
    {
        for (int j = 0; j < m+m-1; j++)
        {
            // generating the rows which begin with a dot
            if(i%2==0){
                if(j%2 == 0) gridArray[i][j] = 2;
                if(j%2 == 1) gridArray[i][j] = 0;
            }

            // generating the rows which begin witha vert line
            if(i%2 == 1){
                if(j%2 == 0) gridArray[i][j] = 0;
                if(j%2 == 1) gridArray[i][j] = 2;
            }
        }
        
    }

}

// enter row1 as first row is 1
// enter col1 as first col is 1
int addLineToArray(int n, int m, int gridArray[n+n-1][m+m-1],int row1, int row2, int col1, int col2,int turn)
{
    int sum =0;
    if(row1 == row2){ // hor line
        int col3;
        if(col1>col2){ col3 = col1;}
        else if(col1 < col2) {col3 = col2;}
        if(gridArray[row1 + row2 -2][2*col3 - 3] == 1){
            printf("ERROR");
        }else{
            gridArray[row1 + row2 -2][2*col3 - 3] = 1*turn;
            sum = (row1+row2-2) *10;
            sum+= 2*col3-3;  // GET COORD OF LINES AS 2 DIGITS , MOST SIG NUM IS ROW
            return sum;
        }
    }
    if(col1 == col2){ // vertical line
        int row3;
        if(row1 > row2) {row3 = row1;}
        else if(row1<row2) {row3 = row2;}
        if(gridArray[2*row3 - 3][col1 + col2 - 2] == 1){
            printf("ERROR");   // TODO CHECK IN MAIN GAME LOOP 
        }else{
            gridArray[2*row3 - 3][col1 + col2 - 2] = 1*turn;    
            sum = (2*row3-3)*10;
            sum += col1+col2-2;
            return sum;
        }
    }
}

// this main is just to test the code.

/*
 int main(){
    
    int lineArray[ROWS][COLS] = {
        {2,0,2,0,2},
        {0,2,0,2,0},
        {2,0,2,0,2},
        {0,2,0,2,0},
        {2,0,2,0,2}
    }; // the 2 represents the Xs.

    printf("enter grid size nxm");
    int n,m;
    scanf("%d %d",&n, &m);

    int gridArray[n+n-1][m+m-1];
    generateGridArray(n,m,gridArray);
    
    int row1,row2,col1,col2;
    scanf("%d %d %d %d",&row1,&col1,&row2,&col2);


    addLineToArray(n,m,gridArray,row1,row2,col1,col2);
    return 0;
}*/
