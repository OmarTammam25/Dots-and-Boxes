//#include <stdio.h>
//#include <Windows.h>
//#include "colors.h"

#define dot 254
#define ver 124
#define hor 196


void flatten(int n ,int m,int arr[n][m],int flat_data[]){
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
    // note the size of the flaten array can be obtained from (2*m*n-m-n)
    int counter=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0) flat_data[counter++]=' ';//check if the element is zero turn it to space

            // check if the element is 1 and the row number is even turn it to horizontal line
            else if(arr[i][j]==1&&i%2==0) flat_data[counter++] =  hor ;
            else if(arr[i][j]==-1&&i%2==0) flat_data[counter++]= -hor ;   
            // check if the element is 1 and the row number is odd turn it to vertical line
            else if(arr[i][j]==1&&i%2==1) flat_data[counter++] =  ver ;
            else if(arr[i][j]==-1&&i%2==1) flat_data[counter++]= -ver ;
        }
    }
}



void change_grid(int n,int m ,int data[],WORD cr1,WORD cr2){
    /* fuction to apply the move of the user 
        and display the new grid 
    */
    int c=0; // counter for the data structure
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",dot);
            if(j!=m-1){
                if(data[c]<0){
                    setColor(cr1);
                    printf("%c%c",data[c++]*-1,data[c]*-1); //print horizontal line if exist in the data structure with color -1
                    setColorDefault();
                }
                else{ 
                    setColor(cr2);
                    printf("%c%c",data[c++],data[c]); //print horizontal line if exist in the data structure with color 1
                    setColorDefault();
                }
            }
        }
        printf("\n");
        if(i!=n-1){ // for not printing vertical lines after the last row of dots
            for(int j=0;j<m;j++){
                if(data[c]<0){
                    setColor(cr1);
                    printf("%c",data[c++]*-1); // printing vertical line if exist in the data structure with color -1
                    setColorDefault();
                }
                else {
                    setColor(cr2);
                    printf("%c",data[c++]*1); // printing vertical line if exist in the data structure with color 1
                    setColorDefault();
                }

                if(j!=m-1) printf("  ");
            }
        }
        printf("\n");
    }
}


/*
int main(){
// the data must be in one dimension form of size (2*m*n - m - n)
//and having one value of the 3 (' ' , hor , ver)

//example:

    
int data[9][9]={{2,-1,2,0,2,-1,2,-1,2},
                {1,2,1,2,1,2,1,2,1},
                {2,1,2,1,2,1,2,1,2},
                {1,2,0,2,0,2,1,2,1},
                {2,1,2,-1,2,-1,2,1,2},
                {-1,2,0,2,1,2,1,2,1},
                {2,1,2,-1,2,1,2,1,2},
                {1,2,-1,2,1,2,1,2,1},
                {2,1,2,-1,2,1,2,1,2}};
    int flat_data[40];//number of lines
    flatten(9,9,data,flat_data); //size of data structure
    for (int i = 0; i < 40 ; i++)
    {
        printf("%c,",flat_data[i]);
    }

    printf("\n");
    
    //int data[49]={' ',hor,hor,hor,hor,ver,ver,ver,ver,ver,ver,
    //               hor,-hor,hor,hor,hor,-ver,' ',ver,-ver,ver,ver,
    //               hor,hor,hor,hor,hor,ver,ver,ver,-ver,ver,ver,
    //               hor,' ',hor,hor,-hor,' ',ver,ver,ver,ver,ver,
    //               hor,hor,hor,hor,hor};
                   
    change_grid(5,5,flat_data,FOREGROUND_RED,FOREGROUND_BLUE);//number of dots
    system("pause");
    return 0;
    
}*/