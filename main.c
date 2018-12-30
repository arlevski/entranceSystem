#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Source.c"


typedef struct S_User
{
    char name[20]; // user name
    char code[8];    // user code
    int permissionStatus;   //user status
    struct S_User *next;

    //start time

    //end time

    //pulse
} User;

void PrintList(User *start) {
    User *currentUser = start;
    int count = 0;

    while(currentUser != NULL) {
        count++;
        printf("user:%d Name:%s Code:%s\n",count,
               currentUser->name,
               currentUser->code);
        currentUser = currentUser->next;
    }
    printf("Total Users:%d\n",count);
}

User *AddUser(User *previous) {

    printf("Enter Name And Code: ");
    char input[16];
    fgets( input, 15, stdin);

    User *newUser = malloc(sizeof(User));
    sscanf(input, "%s %s", newUser->name, newUser->code);
    printf("Added:%s Code:%s\n\n",newUser->name, newUser->code);
    newUser->next = NULL;
    if(previous != NULL) {
        previous->next = newUser;
    }

    return newUser;
}

void userCreate();

void readAccess();







int main(int argc, char *argv[]) {

    int day, month, year, hours, mins;

    if (argc != 2)
    {
        printf("Valid Arguments\n");
        printf("---------------\n");
        printf("To enter new submits into the Access System: program.exe requests.txt\n");
        //return;
    }

    readAccess(ACCESS_PATH);

    getDateTime(&day,&month,&year,&hours,&mins);
    printf("Current computer time: %02d/%02d/%d, %02d:%02d\n",day,month,year,hours,mins);

    char command[16];
    char input[16];

    User *start = NULL;
    User *newest = NULL;


    printf("Please type 'add', 'print' or 'quit'\n");
    while( fgets( input, 15, stdin) ) {

        sscanf(input,"%s",command);

        if ( strncmp(command, "quit", 4) == 0) {
            printf("\n\nBreaking...\n");
            break;
        } else if ( strncmp(command, "print", 5) == 0) {
            PrintList(start);
        } else if ( strncmp(command, "add", 3) == 0) {
            if(start == NULL) {
                start = AddUser(NULL);
                newest = start;
            } else {
                newest = AddUser(newest);
            }
        }
    }

    //return 0;

}



