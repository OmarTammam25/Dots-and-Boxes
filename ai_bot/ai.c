#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int arr0[100];
int size0;
int arr1[100];
int size1;
int arr2[100];
int size2;
int arr3[100];
int size3;
int marr[100];
int sizem;

int in (int number,int array[],int size){
    
    for(int i=0;i<size;i++){
        if(array[i]==number) return 1;
    }
    return 0;
}

void switchf(int sum,int i,int j,int*score ){
    int num =i*10+j;
    if(sum==2){
        arr2[size2]=num; 
        size2+=1;
    }
    else if(sum==3&&!in(num,arr2,size2)){
        arr3[size3]=num; 
        size3+=1;
        *score+=1;
    }
    else if(sum==1&&!in(num,arr2,size2)){
        arr1[size1]=num; 
        size1+=1;
    }
    else if(sum==0 && !in(num,arr2,size2)){
        arr0[size0]=num; 
        size0+=1;
    }
}

void check (int i , int j , int n , int m , int data[n][m]){
    //,int arr0[],int size0,int arr1[],int size1,int arr2[],int size2,int arr3[],int size3,int marr[],int sizem
    int line = i%2;
    int score=0;
    int number_lines=0;
    if(line == 0){//hor
        if(i!=0){
            //check the above 3 elements
            int sum = abs(data[i-1][j-1])+abs(data[i-1][j+1])+abs(data[i-2][j]);
            switchf(sum,i,j,&score);
        }

        if(i!=n){
            //check the below 3 elements
            int sum = abs(data[i+1][j-1])+abs(data[i+1][j+1])+abs(data[i+2][j]);
            switchf(sum,i,j,&score);
        }
    }

    else if (line == 1){//ver
        if(j!=0){
            //check the left 3 elements
            int sum = abs(data[i-1][j-1])+abs(data[i+1][j-1])+abs(data[i][j-2]);
            switchf(sum,i,j,&score);
        }
        
        if(j!=m){
            //check the right 3 elements
            int sum = abs(data[i-1][j+1])+abs(data[i+1][j+1])+abs(data[i][j+2]);
            switchf(sum,i,j,&score);
        }
    }

    if(score==2){
        marr[sizem]=i*10+j;
        sizem+=1;
        score=0;
    }
}

void fill(int n , int m , int data[n][m]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(data[i][j]==0){
                check(i,j,n,m,data);
            }
        }  
    }   
}

int play(int n,int m,int data[n][m]){
    fill(n,m,data);
    if (sizem>0) {
        if(sizem==1) return marr[0];
        else {
            srand(time(NULL));
            int num = (rand() % (sizem-1));
            return marr[num];
        }
    }
    else if(size3>0){
        if(size3==1) return arr3[0];
        else {
            srand(time(NULL));
            int num = (rand() % (size3-1));
            return arr3[num];
        }
    }
    else if(size1>0){
        if(size1==1) return arr1[0];
        else {
            srand(time(NULL));
            int num = (rand() % (size1-1));
            return arr1[num];
        }
    }
    else if(size0>0){
        if(size0==1) return arr0[0];
        else {
            srand(time(NULL));
            int num = (rand() % (size0-1));
            return arr0[num];
        }
    }
    else if(size2>0){
        if(size2==1) return arr2[0];
        else {
            srand(time(NULL));
            int num = (rand() % (size2-1));
            return arr2[num];
        }
    }
} 

int main(){
    int data[5][5] ={{2,1,2,0,2},
                     {1,2,0,2,0},
                     {2,0,2,0,2},
                     {0,2,0,2,0},
                     {2,0,2,0,2}};

    int move = play(5,5,data);
    printf("%d",move);
    return 0;
}