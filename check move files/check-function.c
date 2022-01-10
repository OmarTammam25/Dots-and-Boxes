//  NOT WORKING NOW , THE WORKING FILE IN HEADERS FOLDER
#include <stdio.h>

int line_check(int i){
    /*
    to check if the line is vertical or horizontal
    
    parameters:
    n -> the row index of the move 
    */
   if(i%2==0) return 0; //hor=0
   else return 1; //ver =1
}

int check_squares(int i , int j , int n , int m , int data[n][m]){
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

    int line = line_check(i);
    int score=0;
    if(line == 0){

        //check the above 3 elements
        int sum = data[i-1][j-1]+data[i-1][j+1]+data[i-2][j];
        if(sum == 3&&i!=0){
            score++;
            sum = 0;
        }
        else sum = 0;

        //check the below 3 elements
        sum = data[i+1][j-1]+data[i+1][j+1]+data[i+2][j];
        if(sum == 3&&i!=n-1){
            score++;
            sum = 0;
        }
        sum = 0;
    }
    else if (line == 1){

        //check the left 3 elements
        int sum = data[i-1][j-1]+data[i+1][j-1]+data[i][j-2];
        if(sum == 3&&j!=0){
            score++;
            sum = 0;
        }
        else sum = 0;
        //check the right 3 elements
        sum = data[i-1][j+1]+data[i+1][j+1]+data[i][j+2];
        if(sum == 3&&j!=m-1){
            score++;
            sum = 0;
        }
        sum = 0;
    }
    return score ;
}
/*
int main(){
    //example:
    int data[5][5] = {
        {2,1,2,1,2},
        {1,2,1,2,1},
        {2,0,2,1,2},
        {1,2,1,2,0},
        {2,1,2,0,2}
    };

    //printf("%c\n",line_check(2));
    printf("%d",check_squares(2 ,1,5,5,data));
}*/
