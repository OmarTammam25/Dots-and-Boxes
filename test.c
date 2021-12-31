#include <stdio.h>

int main(){
    char userNames[100][20] = {};
    int scoresHistory[100] = {0};
    int numUsers = 2;
    FILE *username = NULL;
    FILE *scores = NULL;
    username = fopen("usernames.bin","rb");
    scores = fopen("scores.bin", "rb");
    int i = 0;
    while(numUsers--){
        char string[20];
        fgets(userNames[i++], 20, username);
        //userNames[i++] = string;
    }
  /*   char string[20];
    char string2[20];
    fgets(string, 100, username);
    fgets(string2, 20, username);
    userNames[0] = string;
    userNames[1]= string2; */
/*     FILE *usernames = NULL;
    usernames = fopen("usernames.bin","ab");
    char name[20] = "Joseph";
    fwrite(name, sizeof(char), 20, usernames); */
    return 0;

}