#include <stdio.h>

int main(){
    int selection;

    printf("______       _   _   _        _____  __   _____ _                       _       \n");
    printf("| ___ \\     | | | | | |      |  _  |/ _| |  _  | |                     (_)      \n");
    printf("| |_/ / __ _| |_| |_| | ___  | | | | |_  | | | | |_   _ _ __ ___  _ __  _  __ _ \n");
    printf("| ___ \\/ _` | __| __| |/ _ \\ | | | |  _| | | | | | | | | '_ ` _ \\| '_ \\| |/ _` |\n");
    printf("| |_/ | (_| | |_| |_| |  __/ \\ \\_/ | |   \\ \\_/ | | |_| | | | | | | |_) | | (_| |\n");
    printf("\\____/ \\__,_|\\__|\\__|_|\\___|  \\___/|_|    \\___/|_|\\__, |_| |_| |_| .__/|_|\\__,_|\n");
    printf("                                                   __/ |         | |            \n");
    printf("                                                  |___/          |_|            \n");
    printf("Welcome to Battle of Olympia\n");
    printf("Select menu\n");
    printf("1. New Game\n");

    // TODO : Insert Load Game
    
    printf("> ");

    scanf("%d", &selection);
    if(selection == 1){
        NewGame();
    }
}