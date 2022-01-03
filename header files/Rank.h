void Rank(char usernames[][20], int scores[]){  
    FILE *nameptr = NULL;
    FILE *scoreptr = NULL;
    nameptr = fopen("usernames.bin", "rb");
    scoreptr = fopen("scores.bin", "rb");
    if(nameptr == NULL){
        printf("ERROR!");
        return;
    }
    if(scoreptr == NULL){
        printf("ERROR!");
        return;
    }
    int i = 0;
    while(!feof(nameptr)){
        fgets(usernames[i], 20, nameptr);
        fread(&scores[i++], sizeof(int), 1, scoreptr);
    }


}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swapString(char *x, char *y){
    char temp[20];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}

int numOfElements(int scores[]){
    int i = 0;
    while (scores[i]!= 0)
    {
        i++;
    }
    return i;
}


void topTen(char usernames[][20], int scores[]){
    // sorts the 2 arrays using bubble sort :)
    int n = numOfElements(scores);
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(scores[j] < scores[j+1]){
                swap(&scores[j], &scores[j+1]);
                swapString(usernames[j], usernames[j+1]);
            }
        }
        
    }
    // prints leaderboard
    for (int i = 0; i < n; i++)
    {
        if(i == 10) break;
        printf("\n%d- %s Score: %d\n",(i+1), usernames[i], scores[i]);
    }
    

}

void capitalize(char string[]){
    int i = 0;
    while(string[i] != '\0'){
        string[i] = toupper(string[i]);
        i++;
    }
}
