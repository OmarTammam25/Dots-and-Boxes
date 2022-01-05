//#include <stdio.h>
//#include <math.h>
//#include "../header files/check_function.h"

// store moves
// undo moves 
// delet the old moves after some undo and play a move
// redo moves 
// note dont forget to handel the turn 

int store(int size ,int storage[],int n_row,int n_col,int turn){
    /*
    to store the moves into a 1d array
    parameters:
    size -> the old size of the storage array
    storage -> where the moves are stored
    n -> the new move in the flatten array intex of the flatten

    it return the new size of the storage array
    */
   storage[size++]=(encode(n_row,n_col))*turn;
   return size;
}

void undo(int *g_size,int g_storage[],int *r_size,int r_storage[],int n,int m,int grid_array[n][m],int *turn,int *score1,int *score2){
    /*
    n,m size of grid array
    */
    if(*g_size>0){
        r_storage[*r_size]=g_storage[*g_size-1];
        *r_size+=1;
        decode(&n_col,&n_row,g_storage[*g_size-1]);
        /*
        int n_col=abs(g_storage[*g_size-1]%10);
        //g_storage[*g_size-1]/=10;
        int n_row=abs(g_storage[*g_size-1]/10);
        */
        if (grid_array[n_row][n_col]==1) {
            *turn = 1;
        }
        else if (grid_array[n_row][n_col]==-1) {
            *turn = -1;
        }

        if(n_row%2==0){
            if(n_row !=0){
                if(grid_array[n_row-1][n_col]==3){
                    grid_array[n_row-1][n_col]=2;
                    *score2-=1;
                }
                else if(grid_array[n_row-1][n_col]==-3){
                    grid_array[n_row-1][n_col]=2;
                    *score1-=1;
                }
            }
            if(n_row !=n-1){
                if(grid_array[n_row+1][n_col]==3){
                    grid_array[n_row+1][n_col]=2;
                    *score2-=1;
                }
                else if(grid_array[n_row+1][n_col]==-3){
                    grid_array[n_row+1][n_col]=2;
                    *score1-=1;
                }
            }
        }

        if(n_row%2==1){
            if(n_col !=0){
                if(grid_array[n_row][n_col-1]==3){
                    grid_array[n_row][n_col-1]=2;
                    *score2-=1;
                }
                else if(grid_array[n_row][n_col-1]==-3){
                    grid_array[n_row][n_col-1]=2;
                    *score1-=1;
                }
            }
            if(n_row !=n-1){
                if(grid_array[n_row][n_col+1]==3){
                    grid_array[n_row][n_col+1]=2;
                    *score2-=1;
                }
                else if(grid_array[n_row][n_col+1]==-3){
                    grid_array[n_row][n_col+1]=2;
                    *score1-=1;
                }
            }
        }
        
        grid_array[n_row][n_col]=0;
        *g_size-=1;
    }
}

int check(int i , int j , int n , int m , int data[n][m],int turn){
    int line = i%2;
    int score=0;
    if(line == 0){

        //check the above 3 elements
        int sum = abs(data[i-1][j-1])+abs(data[i-1][j+1])+abs(data[i-2][j]);
        if(sum == 3&&i!=0){
            score++;
            data[i-1][j] = 3*(turn);
            sum = 0;
            //*turn *= -1;
        }
        else sum = 0;

        //check the below 3 elements
        sum = abs(data[i+1][j-1])+abs(data[i+1][j+1])+abs(data[i+2][j]);
        if(sum == 3&&i!=n-1){
            score++;
            //if(data[i-1][j] == 3 || data[i-1][j] == -3) *turn *= -1;
            data[i+1][j] =3*(turn);
            sum = 0;
            //*turn *= -1;
        }
        sum = 0;
    }
    else if (line == 1){

        //check the left 3 elements
        int sum = abs(data[i-1][j-1])+abs(data[i+1][j-1])+abs(data[i][j-2]);
        if(sum == 3&&j!=0){
            score++;
            data[i][j-1] = 3*(turn);
            sum = 0;
            //*turn *= -1;
        }
        else sum = 0;
        //check the right 3 elements
        sum = abs(data[i-1][j+1])+abs(data[i+1][j+1])+abs(data[i][j+2]);
        if(sum == 3&&j!=m-1){
            score++;
            //if(data[i][j-1] == 3 ||data[i][j-1] == -3 ) *turn *= -1;
            data[i][j+1] = 3* (turn);
            sum = 0;
            //*turn *= -1;
        }else{
            sum = 0;
        }
    }
    return score ;
}

void redo(int *g_size,int g_storage[],int *r_size,int r_storage[],int n,int m,int grid_array[n][m],int *turn,int *score1,int *score2){
    if(*r_size>0){
        int value;
        g_storage[*g_size]=r_storage[*r_size-1];
        *g_size+=1;
        decode(&n_col,&n_row,r_storage[*r_size-1]);
        /*
        int n_col=abs(r_storage[*r_size-1]%10);
        //r_storage[*r_size-1]/=10;
        int n_row=abs(r_storage[*r_size-1]/10);
        */
        value=r_storage[*r_size-1]/abs(r_storage[*r_size-1]);

        if(*r_size>1){
            *turn=r_storage[*r_size-2]/abs(r_storage[*r_size-2]);
        }
        else if(*r_size=1){
            int coord=g_storage[*g_size-1];
            decode(&ng_row,&ng_col,coord);
            /*
            int ng_col=abs(coord%10);
            coord/=10;
            int ng_row=abs(coord);*/
            
            if(check(ng_row,ng_col,n, m, grid_array,*turn))
                *turn =g_storage[*g_size-1]/abs(g_storage[*g_size-1]);
            else {
                *turn =(g_storage[*g_size-1]/abs(g_storage[*g_size-1]))*-1;
            }
        }

        if(*turn==-1){
            *score1 +=check(n_row,n_col,n, m, grid_array,*turn);  
        }
        else if(*turn==1){
            *score2 +=check(n_row,n_col,n, m, grid_array,*turn); 

        }
        

        grid_array[n_row][n_col]=value;
        *r_size-=1;

    }
}
/*
int main(){

    int data[9][9]={{2,-1,2,1,2,-1,2,1,2},
                    {-1,3,1,3,-1,3,1,3,-1},
                    {2,1,2,1,2,1,2,1,2},
                    {1,2,-1,2,0,2,1,2,1},
                    {2,0,2,0,2,0,2,0,2},
                    {0,2,0,2,0,2,0,2,0},
                    {2,0,2,0,2,0,2,0,2},
                    {0,2,0,2,0,2,0,2,0},
                    {2,0,2,0,2,0,2,0,2}};
    
    int s[17] = {-1,3,-5,7,-10,12,-14,16,-18,21,23,25,27,30,-32,36,38};
    int r[100]={};
    int g_size= 17;
    int r_size=0;
    int t=-1 ;
    int score1=0;
    int score2=4;

    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
    undo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2);
//s[2] ={-1,3}
//r[15]={38,36,-32,30,27,25,23,21,-18,16,-14,12,-10,7,-5}
        
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t 1
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t -1
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t 1
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t -1
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t 1
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t -1
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t 1
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t 1 
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t 1 
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t 1
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t 1
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t -1
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t 1
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t 1 ++
    redo(&g_size,s,&r_size,r,9,9,data,&t,&score1,&score2); //t -1 


    return 0;
}*/