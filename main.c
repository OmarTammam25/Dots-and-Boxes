#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "header files/colors.h"
#include "header files/lines array.h"
#include "header files/grid_code.h"
#include "header files/check_function.h"
#include "redo/redo.c"
#include "ai_bot/ai.c"
#include "header files/Rank.h"
#include "header files/user input errors.h"

#define MAX_NAME 20
#define MAX_USERS 100

int main(){
// initializing the game
    system("cls");


    // Initialize variables
    typedef struct{
        int score;
        WORD colorF;
        WORD colorB;
        char name[MAX_NAME+1];
        int numOfMove;
        double timeSpent;
    }player;
    player player1;
    player player2;

    int num_row = 0; //number of dots in each colomn
    int num_col = 0; //number of dots in each row
    int plyers_num=0;
    int turn = 1;
    int totalNumberOfLines= 0;
    int rowGridArray;
    int colGridArray;
    int row1,row2,col1,col2;
    player1.score =0;
    player2.score = 0;
    int i,j; // coord of new line in gridArray
    int save = 1;
    FILE *ptr = NULL;
    int numOfGames = 0; // number of games played.
    char userNames[MAX_USERS][MAX_NAME];
    int scoresHistory[MAX_USERS] = {0};
    int loadChoice;
    int fileSave;
    player1.numOfMove = 0;
    player2.numOfMove = 0;
    int g_size=0;
    int r_size=0;
    int g_storage[100];
    int r_storage[100];
    int remain_lines =0;
    clock_t begin1 = 0;
    clock_t begin2 = 0;
    clock_t end1 = 0;
    clock_t end2 = 0;
    FILE *Iptr = NULL;
    char readImage[128];

    char main_menu [4][40]= {"1- Start a new game","2- Load a game","3- Top ten players","4- Exit"};
    //char conf_menu[3][40] = {"size of grid","one or two players","players configuration"};
    char grid_size[6][40] = {"1- 2*2","2- 3*3","3- 4*4","4- 5*5","5- custom size","6- Back"};
    char one_two[3][40]   = {"1- one player","2- two players","3- back"};

    int choice=0;
    main_page:


        Iptr = fopen("ASCII ART/ASCII ART!.txt", "r");
        if (Iptr == NULL){
            printf("\t\t\t\tWelcome to dots and boxes game :)\n");
            system("pause");
            system("cls");
        }else{
            setColorL(2);
            while(fgets(readImage, sizeof(readImage), Iptr) != NULL){
                printf("\t\t\t%s", readImage);
            }
        }
        fclose(Iptr);
        setColorDefault();

        //printing the main menu elements
        printf("\n\n\n");
        for (int i=0;i<4;i++){
            setColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            printf("%s\n",main_menu[i]);
        }

        //user choice
        printf("\n\nchoose the number : ");

        scanf("%d",&choice);
        int load = 0;
        switch(choice){
            case 1:
                system("cls");
                printf("\t\t\t\tStart a new game");
                goto game_conf; // take him to game configration page
                choice=0;
                break;
            case 2:
                system("cls");
                printf("\t\t\t\tLoad a game\n"); // take him to load game page
                load = 1;
                choice=0;
                goto load_game;
                break;
            case 3:
                system("cls");
                printf("\t\t\t\t\t\tTop ten players\n\n"); // take hime to top ten players
                // handling Rank of players :)
                Rank(userNames, scoresHistory);
                topTen(userNames, scoresHistory);
                system("pause");
                choice=0;
                break;
            case 4:
                return 0;// Exit the game
                break;
            default :
                printf("\t\t\t\tplease enter a valid number between 1-4\n");
                fflush(stdin);
                choice=0;
                system("pause");
                goto main_page;
        }
    game_conf:
        system("cls");

        Iptr = fopen("ASCII ART/Game Config.txt", "r");
        if (Iptr == NULL){
            printf("\t\t\t\tgame configuration\n");
        }else{
            setColorL(3);
            while(fgets(readImage, sizeof(readImage), Iptr) != NULL){
                printf("\t\t\t%s", readImage);
            }
        }
        fclose(Iptr);
        setColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);




        
        //game setup (size of gride , 2 players or one , choosing colors)
        choice=0;
        printf("\nthe size of the grid\n\n"); //size of grid menu

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
                if(num_row > 15 || num_col >15){
                    printf("\nThe grid you've chosen is too large, Please select a smaller grid\n");
                    fflush(stdin);
                    system("pause");
                    goto game_conf;
                }else if(num_row < 3 || num_col <3){
                    printf("\nThe grid you've chosen is too small, Please select a bigger grid\n");
                    fflush(stdin);
                    system("pause");
                    goto game_conf;                   
                }
                choice =0;
                break;

            case 6:
                //go to the main page
                system("cls");
                goto main_page;
            default:
                printf("\t\t\t\tplease enter a valid number between 1-6\n");
                fflush(stdin);
                choice=0;
                system("pause");
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
                printf("\t\t\t\tplease enter a valid number between 1-3\n");
                fflush(stdin);
                choice=0;
                system("pause");
                goto players_number;

        }
    /*
    block of code to ask for user name and user color
    if one user or two users
    add user name to user file and wait for his score if it is his first time with the game
    update the score of the user if it is higher than his last high score
    */

    choice = 0;
    system("cls");
    printf("\t\t\t\tPlayers information\n");
    fflush(stdin); // to make fgets work
    // if number of players is 1:
    if(plyers_num == 1){
        printf("Please enter your name (max 20 characters): \n");
        fgets(player1.name, MAX_NAME+1, stdin);
        fflush(stdin);
        capitalize(player1.name);
        printf("\nPlease enter your prefered color:\n");
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
                    fflush(stdin);
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
        capitalize(player1.name);
        capitalize(player2.name);

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
                    fflush(stdin);
                    goto color_choice_2;
            }
    }
    



    /* example of setting color of the user
    setColor(player1.colorB);
    printf("     \n     ");
    setColorDefault(); */

    //main game loop:
 
    load_game: 

    /*
        1/ print grid
        2/ ask user for where to place the line TODO CHECK IF USER ENTERS WRONG COORDINATES
        3/ check if its a square
        4/ print new grid
        5/ update variables(score, time, players turn, number of moves for each player, number of remaining line)
        6/ player 2 turn loop again untill no more zeroes in gridArray
    */

   if( load == 1){
       system("cls");
       printf("\n\t\t\t\tenter a number between 1-3 to select saved data: ");
       scanf("%d", &loadChoice);
       switch (loadChoice)
       {
       case 1:
           ptr = fopen("saveData1.bin", "rb");
           break;
        case 2:
            ptr = fopen("saveData2.bin", "rb"); 
            break;
        case 3:
            ptr = fopen("saveData3.bin", "rb");
            break;
       default:
            printf("\n Please  select a number from 1-3: \n");
            fflush(stdin);
            system("pause");
            goto load_game;
            break;
       }
       if(ptr == NULL){
           printf("error, no file found!\n");
           system("pause");
           load = 0;
           goto main_page;
       }
        fread(&num_row, sizeof(int), 1, ptr);
        fread(&num_col, sizeof(int), 1, ptr);
        fread(&turn, sizeof(int), 1, ptr);
        fread(&rowGridArray, sizeof(int), 1, ptr);
        fread(&colGridArray, sizeof(int), 1, ptr);
        fread(&player1, sizeof(player), 1, ptr);
        fread(&player2, sizeof(player), 1, ptr);
        fread(&plyers_num, sizeof(int), 1, ptr);
        fread(&g_size, sizeof(int), 1, ptr);
        fread(&remain_lines, sizeof(int), 1, ptr);  
        fread(&g_storage, sizeof(int), sizeof(g_storage), ptr);
        turn *= -1;
   }else{
        rowGridArray = num_row + num_row -1;
        colGridArray = num_col + num_col -1;
   }
    int gridArray[rowGridArray][colGridArray];
    int flatArray[2* num_row*num_col - num_row - num_col + (num_row-1)*(num_col -1)];
    if(load == 1){

        fread(&gridArray, sizeof(int), sizeof(gridArray) / sizeof(gridArray[0][0]), ptr); // every line 4 values,  row*col
        fclose(ptr);
        load = 1;
    }
    // print grid
    setColorDefault();
    if(!load) generateGridArray(num_row,num_col, gridArray);
    flatten(rowGridArray,colGridArray,gridArray, flatArray);
    system("cls");
    change_grid(num_row,num_col, flatArray, player1.colorF, player2.colorF, player1.colorB, player2.colorB);
    int play = 0;
    int called =0;
    int coor;
    int total_lines=2* num_row*num_col - num_row - num_col;
    

    while(!play)
    {
        play = 1;
        if(!called){
            turn *= -1; // player 1 negative 1   
        }
        called=0;
        // ask user where to place the line
        printf("\n\n");
        if(plyers_num==1&&turn==1){
            coor=playf(2*num_row-1,2*num_col-1,gridArray);
        }
        else{
            take_input:
            
            if(turn == -1){
                setColor(player1.colorF);
                printf("\nplayer 1 turn\n");
            } 
            
            if(turn == 1){
                setColor(player2.colorF);
                printf("\nplayer 2 turn\n");
            } 
            
            fflush(stdin);
            setColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            printf("\nwrite 55 to save the game");
            printf("\t\t\twrite 22 to undo");
            printf("\t\t\twrite 33 to redo\n");

            setColor(player1.colorF);
            printf("\nplayer 1 score is: %d ", player1.score);
            setColor(player2.colorF);
            printf("\t\t\t\t\t\t\tplayer 2 score is: %d", player2.score);
            setColor(player1.colorF);
            printf("\nplayer 1 total moves: %d ", player1.numOfMove);
            setColor(player2.colorF);
            printf("\t\t\t\t\t\tplayer 2 total moves: %d", player2.numOfMove);
            setColorDefault();
            // printing time

            if(plyers_num == 1){
                setColor(player1.colorF);
                printf("\nTime passed for player1: %d:%d", (int)player1.timeSpent/60, (int)player1.timeSpent%60);
                setColorDefault();
            }else if(plyers_num == 2){
                setColor(player1.colorF);
                printf("\nTime passed for player1: %d:%d", (int)player1.timeSpent/60, (int)player1.timeSpent%60);
                setColor(player2.colorF);
                printf("\t\t\t\t\tTime passed for player2: %d:%d", (int)player2.timeSpent/60, (int)player2.timeSpent%60);
                setColorDefault();
            }
            
            setColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            printf("\n\n\t\t\t\t\tnumber of remaining lines: %d",remain_lines);
            setColorDefault();
            if(turn == -1){
                setColor(player1.colorF);
            }else if(turn == 1 && plyers_num == 2){
                setColor(player2.colorF);
            }
            printf("\n\nPlease enter coordinates of point 1: ");
            
            if(turn == -1) begin1 = clock();
            if(turn == 1) begin2 = clock();
            scanf("%d", &row1);
            setColorDefault();
            save_file:
                if(row1 == 55){
                    FILE *fptr = NULL;
                    setColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    printf("\nenter a number between  1-3 to save the game\n");
                    scanf("%d", &fileSave);
                    switch (fileSave)
                    {
                    case 1:
                        fptr = fopen("saveData1.bin", "wb");                    
                        break;
                    case 2:
                        fptr = fopen("saveData2.bin", "wb");
                        break;
                    case 3:
                        fptr = fopen("saveData3.bin", "wb");
                        break;
                    default:
                        printf("\nEnter a number between 1-3\n");
                        fflush(stdin);
                        goto save_file;
                        break;
                    }
                    if(fptr == NULL){
                        printf("error!!");
                        return 1;
                    }else{
                        fwrite(&num_row, sizeof(int), 1, fptr);
                        fwrite(&num_col, sizeof(int), 1, fptr);
                        fwrite(&turn, sizeof(int), 1, fptr);
                        fwrite(&rowGridArray, sizeof(int), 1, fptr);
                        fwrite(&colGridArray, sizeof(int), 1, fptr);
                        fwrite(&player1, sizeof(player), 1, fptr);
                        fwrite(&player2, sizeof(player), 1, fptr);
                        fwrite(&plyers_num, sizeof(int), 1, fptr);
                        fwrite(&g_size, sizeof(int), 1, fptr);  
                        fwrite(&remain_lines, sizeof(int), 1, fptr);  
                        fwrite(&g_storage, sizeof(int), sizeof(g_storage), fptr);
                        fwrite(&gridArray, sizeof(int), sizeof(gridArray), fptr);
                        fclose(fptr);
                        printf("\n Game Saved!\n");
                        system("pause");
                        system("cls");
                        setColorDefault();
                        change_grid(num_row,num_col, flatArray, player1.colorF, player2.colorF,player1.colorB, player2.colorB); // updates the grid
                        turn *= -1;
                        play = 0;
                        row1 = -1;
                        continue;
                    }
                }

            // undo
            else if(row1==22){
                if(plyers_num==1){
                    //int flag=0;
                    //if(g_storage[g_size-1]<0){
                        undo(&g_size,g_storage,&r_size,r_storage,2*num_row-1,2*num_col-1,gridArray,&turn,&player1.score,&player2.score);
                    //}
                    /*
                    else {
                        undo(&g_size,g_storage,&r_size,r_storage,2*num_row-1,2*num_col-1,gridArray,&turn,&player1.score,&player2.score);
                        flag=1;
                    }*/
                    while(g_storage[g_size-1]>0&&g_size!=0){
                        undo(&g_size,g_storage,&r_size,r_storage,2*num_row-1,2*num_col-1,gridArray,&turn,&player1.score,&player2.score);
                        //flag = 1;
                    }
                   // if(flag){
                        undo(&g_size,g_storage,&r_size,r_storage,2*num_row-1,2*num_col-1,gridArray,&turn,&player1.score,&player2.score);
                        //flag=0;
                    //}
                    called =1;
                    row1 = -1;
                    fflush(stdin);
                    goto print_grid;
                }
                else{
                    undo(&g_size,g_storage,&r_size,r_storage,2*num_row-1,2*num_col-1,gridArray,&turn,&player1.score,&player2.score);
                    called =1;
                    row1 = -1;
                    fflush(stdin);
                    goto print_grid;
                }
            }

            // redo
            else if(row1==33){
                if(plyers_num==1){
                    int flag=0;
                    redo(&g_size,g_storage,&r_size,r_storage,2*num_row-1,2*num_col-1,gridArray,&turn,&player1.score,&player2.score);
                    while(r_storage[r_size-1]>0&&r_size!=0){
                        flag=1;
                        redo(&g_size,g_storage,&r_size,r_storage,2*num_row-1,2*num_col-1,gridArray,&turn,&player1.score,&player2.score);
                    }                
                    called =1;
                    row1 = -1;
                    fflush(stdin);
                    goto print_grid;
                }
                else{
                    redo(&g_size,g_storage,&r_size,r_storage,2*num_row-1,2*num_col-1,gridArray,&turn,&player1.score,&player2.score);
                    called =1;
                    row1 = -1;
                    fflush(stdin); 
                    goto print_grid;
                }
            }
            if(turn == -1){
                setColor(player1.colorF);
            }else if(turn == 1 && plyers_num == 2){
                setColor(player2.colorF);
            }
            scanf("%d", &col1);
            fflush(stdin);
            printf("Please enter coordinates of point 2: ");
            scanf("%d %d", &row2, &col2);
            setColorDefault();
            
            if(turn == -1){
                end1 = clock();
                player1.timeSpent += (double)(end1 - begin1) / CLOCKS_PER_SEC;
            } 
            if(turn == 1){
                end2 = clock();
                player2.timeSpent += (double)(end2 - begin2) / CLOCKS_PER_SEC;
            } 
        }
         // checks input
        if( !checkInput(row1, col1, row2, col2, num_row, num_col)){
            flatten(rowGridArray,colGridArray,gridArray,flatArray);
            system("cls");
            change_grid(num_row,num_col, flatArray, player1.colorF, player2.colorF,player1.colorB, player2.colorB); // updates the grid
            fflush(stdin);
            goto take_input;
        }

        // adds the line into the array gridArray
        if(plyers_num==1&&turn==1){
            i = coor;
            j = i%10; // col
            i /= 10; // row
            gridArray[i][j]=1;
        }
        else{
            i = addLineToArray(num_row, num_col, gridArray, row1, row2, col1, col2, turn);
            //checks if line has already been played
            if(i == -1){
                flatten(rowGridArray,colGridArray,gridArray,flatArray);
                system("cls");
                change_grid(num_row,num_col, flatArray, player1.colorF, player2.colorF,player1.colorB, player2.colorB); // updates the grid
                fflush(stdin);
                goto take_input;
            } 
            j = i%10; // col
            i /= 10; // row
        }
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
            player1.numOfMove=0;
            player2.numOfMove=0;
            remain_lines=0;
            for(int i_row=0;i_row<rowGridArray;i_row++){
                for (int j_col = 0; j_col <colGridArray ; j_col++)
                {
                    if(gridArray[i_row][j_col]==-1)player1.numOfMove++;
                    else if(gridArray[i_row][j_col]==1)player2.numOfMove++;        
                }
                remain_lines=total_lines-player1.numOfMove-player2.numOfMove;
                
            }


        // check game end
        for (int h=0; h<2*num_row-1;h++){
            for (int g=0;g<2*num_col-1;g++){
                if(gridArray[h][g] ==0){
                    play =0;
                    break;
                }
            }
        }
        if(play == 1){
            if(player1.score > player2.score){
                setColor(player1.colorF);
                printf("\nPlayer 1 won!\n", player1.name);
                printf("Congratulations %s \n", player1.name);
                printf("\nScore: %d\n", player1.score);
                system("pause");
                setColorDefault();

                FILE *usernames = NULL;
                FILE *scores = NULL;
                usernames = fopen("usernames.bin","ab");
                scores = fopen("scores.bin", "ab");
                fclose(usernames);
                fclose(scores);
                int foundName=0;
                // search for name and update score
                    FILE *nptr = NULL;
                    nptr = fopen("usernames.bin", "rb+");
                    FILE *sptr =NULL;
                    sptr = fopen("scores.bin", "rb+");
                    if(nptr != NULL && sptr !=NULL){
                        char temp[20];
                        int index_num = 0;
                        int tempValue = 0;
                        while(fgets(temp, 20, nptr) != NULL)
                        {
                            if(strcmp(temp, player1.name) == 0) // that means we found the string
                            { 
                                if( fseek(sptr, index_num * sizeof(int), SEEK_SET) == 0 ) // seeks to wanted value in file
                                { 
                                    foundName = 1;  
                                    fread(&tempValue, sizeof(int), 1, sptr); // reads the value
                                    if(player1.score > tempValue) // compares it
                                    { 
                                        fseek(sptr, index_num * sizeof(int), SEEK_SET);
                                        fwrite(&player1.score, sizeof(int), 1, sptr);
                                    }
                                }  

                            }
                            index_num++;
                        } 
                        fclose(sptr);
                        fclose(nptr);

                    }
                if(!foundName){
                    usernames = fopen("usernames.bin","ab");
                    scores = fopen("scores.bin", "ab");
                    fwrite(&player1.name, sizeof(char), strlen(player1.name), usernames);
                    fwrite(&player1.score, sizeof(int), 1, scores);
                    fclose(usernames);
                    fclose(scores);
                }

            }else if(player1.score < player2.score){
                if(plyers_num == 2){
                    setColor(player2.colorF);
                    printf("\nPlayer 2 won!\n");
                    printf("Congratulations %s \n", player2.name);
                    printf("\nScore: %d\n", player2.score);
                    system("pause");
                    setColorDefault();
                    FILE *usernames = NULL;
                    FILE *scores = NULL;
                    usernames = fopen("usernames.bin","ab");
                    scores = fopen("scores.bin", "ab");
                    fclose(usernames);
                    fclose(scores);
                    int foundName=0;
                    // search for name and update score
                        FILE *nptr = NULL;
                        nptr = fopen("usernames.bin", "rb+");
                        FILE *sptr =NULL;
                        sptr = fopen("scores.bin", "rb+");
                        if(nptr != NULL && sptr !=NULL){
                            char temp[20];
                            int index_num = 0;
                            int tempValue = 0;
                            while(fgets(temp, 20, nptr) != NULL)
                            {
                                if(strcmp(temp, player2.name) == 0) // that means we found the string
                                { 
                                    if( fseek(sptr, index_num * sizeof(int), SEEK_SET) == 0 ) // seeks to wanted value in file
                                    { 
                                        foundName = 1;  
                                        fread(&tempValue, sizeof(int), 1, sptr); // reads the value
                                        if(player2.score > tempValue) // compares it
                                        { 
                                            fseek(sptr, index_num * sizeof(int), SEEK_SET);
                                            fwrite(&player2.score, sizeof(int), 1, sptr);
                                        }
                                    }  

                                }
                                index_num++;
                            } 
                            fclose(sptr);
                            fclose(nptr);

                        }
                    if(!foundName){
                        usernames = fopen("usernames.bin","ab");
                        scores = fopen("scores.bin", "ab");
                        fwrite(&player2.name, sizeof(char), strlen(player2.name), usernames);
                        fwrite(&player2.score, sizeof(int), 1, scores);
                        fclose(usernames);
                        fclose(scores);
                    }
                }else{
                    setColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    printf("YOU LOST!\n");
                    system("pause");
                    setColorDefault();
                }
            }else{
                setColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                printf("Draw!\n");
                setColorDefault();
                system("pause");

            }

            // print leaderboard.
                setColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                printf("\t\t\t\t\t\tTop ten players\n\n");
                Rank(userNames, scoresHistory);
                printf("\n");
                topTen(userNames, scoresHistory);
                printf("\n\n type 0 to exit the game, or type 1 to return to main menu\n");
                int endGameChoice = 0;
                final:
                scanf("%d", &endGameChoice);
                switch (endGameChoice)
                {
                case 1:
                    system("cls");
                    goto main_page;
                    break;
                case 0:
                    return 0;
                
                default:
                    printf("\nplease enter 0 or 1\n");
                    fflush(stdin);
                    goto final;
                    break;
                }
        }
    }
    return 0;
}
