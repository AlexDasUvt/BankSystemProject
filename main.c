#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/Operations.h"

int main(int argc, char *argv[])
{
    char accountName[20]; // fullname of the account used. Used as argument in functions to find account .csv.
    char *name;
    char *surname;
    char fullname[100];
    int menuAction;
    if (argc != 3) // If amount of arguments are not 3 (main.exe + Name + Surname), give an error. 
    {
        printf("You need to give two arguments!(Name surname)\n");
        printf("Exiting...");
        return 1;
    }
    name = argv[1];
    surname = argv[2];
    strcpy(fullname, name);
    strcpy(accountName, name);
    strcat(fullname, surname);
    strcat(accountName, surname);
    strcat(fullname, ".csv");

    FILE *csv_file = fopen(fullname, "r"); // First trying to read exiting file, and if not, create.
    if (csv_file == NULL)
    {
        FILE *csv_file = fopen(fullname, "w");
        if (csv_file == NULL)
        {
            printf("Error opening file.\n");
            return 1;
        }
        printf("Creating account... \n");
        fprintf(csv_file, "%s,%s,", name, surname);
        printf("Write your IBan, currency and amount in specific format! (XXXXXXXX12345678910111213141516171,RON,12345)\n");
        char details[100];
        fgets(details, sizeof(details), stdin);
        fprintf(csv_file, "%s", details);
        fclose(csv_file);
    }
    else{
        fclose(csv_file);
    }
    printf("Successful login.\n");

    printf("Welcome to TEST bank interface.\n"); // Work on bank name
    while (accountName != NULL)
    {
        /*
        Almost infinite loop used as a menu which can be re-used after different commands.
        Has 5 options including Exit and default options which repeats loop with error message.
        */
        printf("\nWhich action do you want to do? (Enter the number o operation)\n 1. Perform transactions\n 2. Edit account\n 3. View account info\n 4. Delete account\n 5. Logout and Exit\n");
        scanf("%d", &menuAction);
        switch (menuAction)
        {
        case 1:
            printf("You selected Perform transaction.\n\n");
            // PerfTransaction(); // Transaction function. TODO
            break;
        case 2:
            printf("You selected Edit account.\n\n");
            EditInfo(accountName);
            break;
        case 3:
            printf("You selected View account info.\n\n");
            ViewInfo(accountName);
            break;
        case 4:
            printf("You selected Delete account.\n\n");
            printf("WARNING!\nThis is irreversible action!\nAfter deleting your account, you will be logged out.\nDo you wish to continue?(1 = Yes/2 = No) ");
            int deleteConf;
            scanf("%d", &deleteConf);
            switch (deleteConf)
            {
                case 1:
                DeleteAccount(accountName);
                printf("Exiting...");
                return 0;
                break;
                case 2:
                printf("Account deletion canceled\n");
                default:
                printf("Unknown command! Deletion canceled\n");
                break;
            }      
        case 5:
            printf("You selected Logout and Exit.\n\n");
            printf("Logout?(1 = Yes/2 = No) ");
            int exitConf;
            scanf("%d", &exitConf);
            switch (exitConf)
            {
                case 1:
                printf("Logging out...\n");
                printf("Exiting...");
                return 0;
                break;
                case 2:
                printf("Logging out canceled\n");
                default:
                printf("Unknown command! Logging out canceled\n");
                break;
            }          
        default:
            printf("Unknown command! Please try again!\n\n");
            break;
        }
    }
}