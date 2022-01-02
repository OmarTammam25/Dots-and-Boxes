int checkInput(int row1, int col1, int row2, int col2, int num_row, int num_col){
    //correct input
    if((row1 == row2 || abs(row1 - row2) == 1) && (col1 == col2 || abs(col1 - col2) == 1 ) && (row1 <= num_row) && (row2 <= num_row) && (col1 <= num_col) && (col2 <= num_col)){
        return 1;

    }else{
        printf("\n\n\t\t\t\tWrong input,  please enter correct coordinates of points you want to choose\n");
        system("pause");
        return 0;
    } 
}
