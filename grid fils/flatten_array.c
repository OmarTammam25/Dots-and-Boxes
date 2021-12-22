#include <stdio.h>

// defining the asci code
#define dot 254
#define ver 124
#define hor 196


void flatten(int n ,int m,int arr[n][m],char flat_data[]){
    /*
    function to get the data structure as 2d array of intergers and
    turn it to 1d array of the characters (| , __ ,' ')
    each caracter mathced with the grid to display
    
    the parameters:
        n-> the number of rows of the data structure array
        m -> the number of colomns of the data structure array
        arr -> the data structure array
        flat_data -> the new formed flat data array
    */
    // note the size of the flaten array can be obtained from (2*m*n-m-n)*2
    int counter=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0) {
                flat_data[counter]=' ';//check if the element is zero turn it to space
                counter+=2;
            }
            // check if the element is 1 and the row number is even turn it to horizontal line
            else if(arr[i][j]==1&&i%2==0) {
                flat_data[counter]= hor ;
                counter+=2;
            }    
            // check if the element is 1 and the row number is odd turn it to vertical line
            else if(arr[i][j]==1&&i%2==1) {
                flat_data[counter]= ver ;
                counter+=2;
            }
        }
    }
}
/*
int main(){ 
    // example:

    int data[5][5]={{2,1,2,1,2},
                    {1,2,1,2,1},
                    {2,1,2,1,2},
                    {1,2,1,2,1},
                    {2,1,2,1,2}};
    char flat_data[24];
    flatten(5,5,data,flat_data);
    for (int i = 0; i < 24 ; i++)
    {
        printf("%c,",flat_data[i]);
    }
    //system("pause");
    return 0;
}*/