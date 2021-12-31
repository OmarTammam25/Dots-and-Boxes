#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include <math.h>
#include "header files/colors.h"
#include "header files/lines array.h"
#include "header files/grid_code.h"
#include "header files/check_function.h"
#include "redo/redo.c"

#define MAX_NAME 20

int main(){
// initializing the game
    system("cls");
    printf("\t\t\t\tWelcome to dots and boxes game :)\n");
    Sleep(500);
    system("cls");

    int num_row = 0; //number of dots in each colomn
    int num_col = 0; //number of dots in each row
    int plyers_num=0;


    char main_menu [4][40]= {"1- Start a new game","2- Load a game","3- Top ten players","4- Exit"};
    //char conf_menu[3][40] = {"size of grid","one or two players","players configuration"};
    char grid_size[6][40] = {"1- 2*2","2- 3*3","3- 4*4","4- 5*5","5- custom size","6- Back"};
    char one_two[3][40]   = {"1- one player","2- two players","3- back"};

    int choice=0;
    main_page:
        //printing the main menu elements

        for (int i=0;i<4;i++){
            printf("%s\n",main_menu[i]);
        }

        //user choice
        printf("\n\nchoose the number : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                system("cls");
                printf("\t\t\t\tStart a new game");
                goto game_conf; // take him to game configration page
                choice=0;
                break;
            case 2:
                system("cls");
                printf("\t\t\t\tLoad a game"); // take him to load game page
                choice=0;
                break;
            case 3:
                system("cls");
                printf("\t\t\t\tTop ten players"); // take hime to top ten players
                choice=0;
                break;
            case 4:
                return 0;// Exit the game
                break;
            default :
                printf("\t\t\t\tplease enter a valid number between 1-4");
                choice=0;
                Sleep(1000);
                goto main_page;
        }
    game_conf:
        system("cls");
        printf("\t\t\t\tgame configuration\n");
        //game setup (size of gride , 2 players or one , choosing colors)
        choice=0;
        printf("\t\t\t\tthe size of the grid\n"); //size of grid menu

        for(int j=0;j<6;j++){
            printf("%s\n",grid_size[j]);
        }
        //user choice
        printf("\n\nchoose the number : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                num_row = 3;
                num_col = 3;
                choice=0;
                break;
            case 2:
                num_row = 4;
                num_col = 4;
                choice=0;
                break;
            case 3:
                num_row = 5;
                num_col = 5;
                choice=0;
                break;
            case 4:
                num_row = 6;
                num_col = 6;
                choice=0;
                break;
             case 5:
                //custom input
                printf("\nEnter number of rows and columns: ");
                scanf("%d %d", &num_row, &num_col);
                choice =0;
                break;

            case 6:
                //go to the main page
                system("cls");
                goto main_page;
            default:
                printf("\t\t\t\tplease enter a valid number between 1-6");
                choice=0;
                Sleep(1000);
                goto game_conf;
        }

    players_number:
        system("cls");
        printf("\t\t\t\tgame configuration\n");
        choice=0;
        printf("\t\t\t\tnumber of players\n"); //one or two players

        for(int j=0;j<3;j++){
            printf("%s\n",one_two[j]);
        }
        //user choice
        printf("\n\nchoose the number : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                plyers_num = 1;
                choice=0;
                break;
            case 2:
                plyers_num = 2;
                choice=0;
                break;
            case 3:
                choice=0;
                goto game_conf;
            default:
                printf("\t\t\t\tplease enter a valid number between 1-3");
                choice=0;
                Sleep(1000);
                goto players_number;

        }
    /*
    block of code to ask for user name and user color
    if one user or two users
    add user name to user file and wait for his score if it is his first time with the game
    update the score of the user if it is higher than his last high score
    */

    typedef struct{
        int score;
        WORD colorF;
        WORD colorB;
        char name[MAX_NAME+1];
    }player;
    player player1;
    player player2;
    choice = 0;

    system("cls");
    printf("\t\t\t\tPlayers information\n");
    fflush(stdin); // to make fgets work
    // if number of players is 1:
    if(plyers_num == 1){
        printf("Please enter your name (max 20 characters): \n");
        fgets(player1.name, MAX_NAME+1, stdin);
        fflush(stdin);
        printf("Please enter your prefered color:\n");
        printf("1.Red\n");
        printf("2.Blue\n");

        color_choice:
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    player1.colorF = FOREGROUND_RED;
                    player1.colorB = BACKGROUND_RED;
                    player2.colorF = FOREGROUND_BLUE;
                    player2.colorB = BACKGROUND_BLUE;
                    break;
                case 2:
                    player1.colorF = FOREGROUND_BLUE;
                    player1.colorB = BACKGROUND_BLUE;
                    player2.colorF = FOREGROUND_RED;
                    player2.colorB = BACKGROUND_RED;
                    break;
                default:
                    printf("please enter num 1 or 2: ");
                    goto color_choice;
            }
    } else
    { // number of players are 2:
        printf("Please enter player 1 name (max 20 characters): \n");
        fgets(player1.name, MAX_NAME+1, stdin);
        fflush(stdin);
        printf("Please enter player 2 name (max 20 characters): \n");
        fgets(player2.name, MAX_NAME + 1, stdin);
        fflush(stdin);

        printf("Please enter player 1 prefered color:\n");
        printf("1.Red\n");
        printf("2.Blue\n");
        color_choice_2:
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    player1.colorF = FOREGROUND_RED;
                    player1.colorB = BACKGROUND_RED;
                    player2.colorF = FOREGROUND_BLUE;
                    player2.colorB = BACKGROUND_BLUE;
                    break;
                case 2:
                    player1.colorF = FOREGROUND_BLUE;
                    player1.colorB = BACKGROUND_BLUE;
                    player2.colorF = FOREGROUND_RED;
                    player2.colorB = BACKGROUND_RED;
                    break;
                default:
                    printf("please enter num 1 or 2: ");
                    goto color_choice_2;
            }
    }




    /* example of setting color of the user
    setColor(player1.colorB);
    printf("     \n     ");
    setColorDefault(); */

    //main game loop:

    int turn = 1;
    int numOfMove = 0;
    int totalNumberOfLines= 0;
    int rowGridArray = num_row + num_row -1;
    int colGridArray = num_col + num_col -1;
    int gridArray[rowGridArray][colGridArray];
    int flatArray[2* num_row*num_col - num_row - num_col + (num_row-1)*(num_col -1)];
    int row1,row2,col1,col2;
    player1.score =0;
    player2.score = 0;

    int g_size=0;
    int r_size=0;
    int g_storage[100];
    int r_storage[100];
    int i,j; // coord of new line in gridArray
    /*
        1/ print grid
        2/ ask user for where to place the line TODO CHECK IF USER ENTERS WRONG COORDINATES
        3/ check if its a square
        4/ print new grid
        5/ update variables(score, time, players turn, number of moves for each player, number of remaining line)
        6/ player 2 turn loop again untill no more zeroes in gridArray
    */

    // print grid
    generateGridArray(num_row,num_col,gridArray);
    flatten(rowGridArray,colGridArray,gridArray,flatArray);
    system("cls");
    change_grid(num_row,num_col, flatArray, player1.colorF, player2.colorF, player1.colorB, player2.colorB);
    int play=0;//indicate the game is still working
    int called =0;
    while(!play)
    {
        play=1;
        if(!called){
        turn *= -1; // player 1 negative 1   
        }
        called=0;
        // ask user where to place the line
        printf("\n\n");
        if(turn == -1) printf("\nplayer 1 turn\n");
        if(turn == 1) printf("\nplayer 2 turn\n");

        printf("\nPlease enter coordinates of point 1: ");
        scanf("%d", &row1);
        
        // undo
        if(row1==22){
            undo(&g_size,g_storage,&r_size,r_storage,2*num_row-1,2*num_col-1,gridArray,&turn,&player1.score,&player2.score);
            called =1;
            goto print_grid;
        }
        else if(row1==33){
            redo(&g_size,g_storage,&r_size,r_storage,2*num_row-1,2*num_col-1,gridArray,&turn,&player1.score,&player2.score);
            called =1;
            goto print_grid;
        }
        scanf("%d", &col1);
        printf("Please enter coordinates of point 2: ");
        scanf("%d %d", &row2, &col2);
        // adds the line into the array gridArray
        i = addLineToArray(num_row, num_col, gridArray, row1, row2, col1, col2, turn);
        j = i%10; // col
        i /= 10; // row
        //test store
        g_size=store(g_size,g_storage,i,j,turn);
        r_size=0;
        // checks if a square is made and returns the score thus far
        switch(turn)
        {
            case -1: player1.score +=check_squares(i,j,rowGridArray, colGridArray, gridArray, &turn); break;
            case 1: player2.score +=check_squares(i,j,rowGridArray, colGridArray, gridArray, &turn); break;
        }
        print_grid:
        flatten(rowGridArray,colGridArray,gridArray,flatArray);
        system("cls");
        change_grid(num_row,num_col, flatArray, player1.colorF, player2.colorF,player1.colorB, player2.colorB); // updates the grid

        printf("player 1 score is: %d ", player1.score);
        printf("player 2 score is: %d", player2.score);
        // game over
        for (int h=0; h<2*num_row-1;h++){
            for (int g=0;g<2*num_col-1;g++){
                if(gridArray[h][g]==0) play=0;
            }
        }
        //sytem("pause");
    }

    //system("pause");
    system("cls");
    printf("game over");
    return 0;
    
}
