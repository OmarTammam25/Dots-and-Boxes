#include <stdio.h>
#include <Windows.h>
#include "header files\colors.h"
#include "header files\player_info.h"
#define MAX_NAME 10

int main(){
// initializing the game
    system("cls");
    printf("\t\t\t\twlecome to dots and boxes game :)\n");
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
        /* printf("Please enter your player 1 name: ");
        scanf("") */ // TODO GET PLAYER NAME
        printf("Please enter player 1 prefered color:\n");
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

        /* setColor(player1.colorB);
        printf("     \n     ");
        setColorDefault(); */

        //main game loop:



    return 0;
}
