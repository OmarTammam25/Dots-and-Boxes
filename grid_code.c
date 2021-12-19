#include <stdio.h>

#define dot 254
#define ver 124
#define hor 196

void change_grid(int n,int m ,char data[]){
    /* fuction to apply the move of the user 
        and display the new grid 
    */
    int c=0; // counter for the data structure
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",dot);
            if(j!=m-1) printf("%c%c",data[c++],data[c]); //print horizontal line if exist in the data structure
        }
        printf("\n");
        if(i!=n-1){ // for not printing vertical lines after the last row of dots
            for(int j=0;j<m;j++){
                printf("%c",data[c++]); // printing vertical line if exist in the data structure
                if(j!=m-1) printf("  ");
            }
        }
        printf("\n");
    }
}


int main(){
// the data must be in one dimension form of size (2*m*n - m - n)
//and having one value of the 3 (' ' , hor , ver)

//example:

    char data[49]={' ',hor,hor,hor,hor,ver,ver,ver,ver,ver,ver,
                   hor,hor,hor,hor,hor,ver,' ',ver,ver,ver,ver,
                   hor,hor,hor,hor,hor,ver,ver,ver,ver,ver,ver,
                   hor,' ',hor,hor,hor,' ',ver,ver,ver,ver,ver,
                   hor,hor,hor,hor,hor};

    change_grid(5,6,data);
    
}
