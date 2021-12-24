//#include <stdio.h>

int line_check(int i){
    /*
    to check if the line is vertical or horizontal
    
    parameters:
    i -> the row index of the move 
    */
   if(i%2==0) return 0; //hor=0
   else return 1; //ver =1
}

int check_squares(int i , int j , int n , int m , int data[n][m], int turn){
    /*
    to check if there is the 3 lines of the square that the new line of the user complete it 
    if yes return the number of squares that this line is used to complete them
    if there is no colpleted squares yet return 0 
    
    parametars:
    i -> the index of the row of the choosen line by the user 
    j -> the index of the colomn of the choosen line by the user 
    n -> the number of rows of data structure array
    m -> the number of colomns of data structure array
    data -> the data structure array
    */

   /*
    data structure array explanation:
    0 means space
    -1 means player 1 line
    +1 means player 2 line
    2 means dot or not a square
    -3 means player 1 square
    +3 means player 2 square
   */

    int line = line_check(i);
    int score=0;
    if(line == 0){

        //check the above 3 elements
        int sum = abs(data[i-1][j-1])+abs(data[i-1][j+1])+abs(data[i-2][j]);
        if(sum == 3&&i!=0){
            score++;
            data[i-1][j] = 3*turn;
            sum = 0;
        }
        else sum = 0;

        //check the below 3 elements
        sum = abs(data[i+1][j-1])+abs(data[i+1][j+1])+abs(data[i+2][j]);
        if(sum == 3&&i!=n-1){
            score++;
            data[i+1][j] =3*turn;
            sum = 0;
        }
        sum = 0;
    }
    else if (line == 1){

        //check the left 3 elements
        int sum = abs(data[i-1][j-1])+abs(data[i+1][j-1])+abs(data[i][j-2]);
        if(sum == 3&&j!=0){
            score++;
            data[i][j-1] = 3*turn;
            sum = 0;
        }
        else sum = 0;
        //check the right 3 elements
        sum = abs(data[i-1][j+1])+abs(data[i+1][j+1])+abs(data[i][j+2]);
        if(sum == 3&&j!=m-1){
            score++;
            data[i][j+1] = 3*turn;
            sum = 0;
        }else{
            sum = 0;
        }
    }
    return score ;
}
/*
int main(){
    int data[5][5] = {
        {2,1,2,1,2},
        {1,2,1,2,1},
        {2,0,2,1,2},
        {1,2,1,2,0},
        {2,1,2,0,2}
    };

    //printf("%c\n",line_check(2));
    printf("%d",check_squares(2 ,1,5,5,data));
}
*/