#include <stdio.h>
#include "stdlib.h"
#include "string.h"




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
    sscanf(input, "%s %s", newUser->name, &newUser->code);
    printf("Added:%s Code:%s\n\n",newUser->name, &newUser->code);
    newUser->next = NULL;
    if(previous != NULL) {
        previous->next = newUser;
    }
    return newUser;
}

void userCreate();

void readAccess();

int main() {


    //readAccess("access.txt");




    int chosenAction;
    int menuFlag = 1;



//    do {
//        printf("Select Action:\n");
//
//        scanf("%d", &chosenAction);
//
//        switch (chosenAction) {
//
//            case 1:
//                printf("Adding a new user: \n");
//                userCreate();
//                break;
//            case 2:
//                printf("case 2 \n");
//                break;
//            case 3:
//                printf("case 3 \n");
//                break;
//            case 4:
//                printf("case 4 \n");
//                break;
//            case 5:
//                printf("case 5 \n");
//                break;
//            case 6:
//                printf("case 6 \n");
////            printf("Search:");
////            char strUser[];
////            scanf("%s", &strUser)
////            search_user(strUser);
//                break;
//            case 7:
//                printf("Thank you and goodbye");
//                menuFlag = 0;
//                break;
//            default:
//                printf("Action Not Valid! \n");
//                break;
//        }
//    } while(menuFlag!=0);


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

    //CleanUp(start);

    return 0;

}

//void userCreate(){
//
//
//    printf("Enter user information:\n");
//
//    printf("Enter  name (20 Characters): ");
//    scanf("%s", user.name);
//
//    printf("Enter access code (8 digits): ");
//    scanf("%s", user.code);
//
//    printf("Enter permission status: ");
//    scanf("%d", &user.permissionStatus);
//
//
//    printf("Displaying Information:\n");
//
//    printf("Name:%s\n",user.name);
//
//
//    printf("access code: %s\n",user.code);
//
//    printf("permission status: %d\n", user.permissionStatus);
//
//
//
//    FILE * fp;
//    /* open the file for writing*/
//    fp = fopen ("test.txt","w");
//
//    fprintf (fp, "%-20s %-8s %-1d\n", user.name, user.code, user.permissionStatus);
//
//
//
//
//
//
////    /* write 10 lines of text into the file stream*/
////    for(i = 0; i < 10;i++){
////        fprintf (fp, " is line %d\n",i + 1);
////    }
//
//    /* close the file*/
//    fclose (fp);
//
//}

