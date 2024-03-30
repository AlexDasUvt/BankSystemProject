#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/Operations.h"

int main(int argc, char *argv[])
{
    char accountName[20]; // fullname of the account used.
    char *name;
    char *surname;
    char fullname[100];
    int menuAction;
    if (argc != 3)
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

    FILE *csv_file = fopen(fullname, "r");
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
        scanf("%s", details);
        fprintf(csv_file, "%s", details);
    }
    printf("Successful login.\n");
    fclose(csv_file);

    printf("Welcome to TEST bank interface.\n"); // Work on bank name
    // struct Account ActiveAcc;

    while (accountName != NULL)
    {
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
            // EditInfo(); // Edit account function. TODO
            break;
        case 3:
            printf("You selected View account info.\n\n");
            ViewInfo(accountName);
            break;
        case 4:
            printf("You selected Delete account.\n\n");
            printf("WARNING!\n This is irreversible action!\n Do you wish to contionue?(1 = Yes/2 = No) ");
            int deleteConf = 2;
            scanf("%d", &deleteConf);
            if (deleteConf == 1)
            {
                // DeleteAccount(); // Delete account function. TODO
            }
            break;
        case 5:
            printf("You selected Logout and Exit.\n\n");
            printf("Logout?(1 = Yes/2 = No) ");
            int exitConf = 2;
            scanf("%d", &exitConf);
            switch (exitConf)
            {
                case 1:
                printf("Logging out...\n");
                printf("Exiting...");
                return 0;
                break;
                case 2:
                printf("Logging canceled\n");
                default:
                printf("Unknown command! Logging canceled\n");
            }
            break;
        default:
            printf("Unknown command! Please try again!\n\n");
            break;
        }
    }
}