int checkInput(int row1, int col1, int row2, int col2, int num_row, int num_col){
    //correct input
    if((row1 == row2 || abs(row1 - row2) == 1) && (col1 == col2 || abs(col1 - col2) == 1 ) && (row1 <= num_row) && (row2 <= num_row) && (col1 <= num_col) && (col2 <= num_col) && !(row1 == row2 && col1 == col2) && !(row1 == col1 && row2 == col2)  ){
        return 1;

    }else{
        printf("\n\n\t\t\t\tWrong input,  please enter correct coordinates of points you want to choose\n");
        system("pause");
        return 0;
    } 
}

int encode (int i,int j){
    return i*100000+j;
}

void decode(int *i,int *j,int coor ){
    coor=abs(coor);
    *j=coor%10;
    coor/=10;
    if(coor%10!=0){
        *j+=(coor%10)*10;
        coor/=10000;
    }
    else coor/=10000;
    *i=coor%10;
    coor/=10;
    if(coor%10!=0){
        *i+=(coor%10)*10;

    }
}

/* example for encoding and decoding 
int main(){
    int x,y,coor;
    for (int i = 0; i < 10; i++)
    {for (int j = 0; j < 10; j++)
    {
        coor=encode(i,j);
        //printf("%d\n",);
        decode(&x,&y,coor);
        //if(i!=x||j!=y)
        printf("%d %d\t%d\t%d %d\n",i,j,coor,x,y);

    }
    
    }
    
    int i=9;
    int j=11;
    
system("pause");
}*/