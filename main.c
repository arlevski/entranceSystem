#include <stdio.h>





struct user
{
    char name[20]; // user name
    char code[8];    // user code
    int permissionStatus;   //user status



    //start time

    //end time

    //pulse
} user;

void userCreate();

void readAccess();

int main() {


    //readAccess("access.txt");




    int chosenAction;
    int menuFlag = 1;



    do {
        printf("Select Action:\n");

        scanf("%d", &chosenAction);

        switch (chosenAction) {

            case 1:
                printf("Adding a new user: \n");
                userCreate();
                break;
            case 2:
                printf("case 2 \n");
                break;
            case 3:
                printf("case 3 \n");
                break;
            case 4:
                printf("case 4 \n");
                break;
            case 5:
                printf("case 5 \n");
                break;
            case 6:
                printf("case 6 \n");
//            printf("Search:");
//            char strUser[];
//            scanf("%s", &strUser)
//            search_user(strUser);
                break;
            case 7:
                printf("Thank you and goodbye");
                menuFlag = 0;
                break;
            default:
                printf("Action Not Valid! \n");
                break;
        }
    } while(menuFlag!=0);

    return 0;
}

void userCreate(){
    char name[20], code[8];
    int permissionStatus;

    printf("Enter user information:\n");

    printf("Enter  name (20 Characters): ");
    scanf("%s", user.name);

    printf("Enter access code (8 digits): ");
    scanf("%s", user.code);

    printf("Enter permission status: ");
    scanf("%d", &user.permissionStatus);


    printf("Displaying Information:\n");

    printf("Name:%s\n",user.name);


    printf("access code: %s\n",user.code);

    printf("permission status: %d\n", user.permissionStatus);



    FILE * fp;
    /* open the file for writing*/
    fp = fopen ("test.txt","w+");

    fprintf (fp, "%-20s %-8s %-1d\n", user.name, user.code, user.permissionStatus);


    while (fscanf(fp, "%20s %8s %1d\n", name, code, permissionStatus) != EOF)
    {
        printf("%-20s %-8s %-1d\n", name, 21, code, 9, permissionStatus);

    }
//    /* write 10 lines of text into the file stream*/
//    for(i = 0; i < 10;i++){
//        fprintf (fp, " is line %d\n",i + 1);
//    }

    /* close the file*/
    fclose (fp);

}

