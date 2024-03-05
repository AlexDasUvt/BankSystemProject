#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account
{
    char iBan[34]; // IBan number consist of 34 alphanumeric characters.
    char owner[20];
    char currency[4];
    double amount;
};

void EditInfo() // How to pass struct pointer and edit values inside in methods?
{
}

void ViewInfo(struct Account Acc) // Change to pass pointer to struct
{
    printf("Your account information:\n");
    printf("Your IBan: %s\n", Acc.iBan);
    printf("This account is registered on: %s\n", Acc.owner);
    printf("This account currently has: %.2f %s\n", Acc.amount, Acc.currency);
}

int main()
{
    char editCommand[8];
    struct Account adminAcc;
    strcpy(adminAcc.iBan, "AAAADDDD11111111111111111111111111");
    strcpy(adminAcc.owner, "Alex Dascalu");
    strcpy(adminAcc.currency, "RON");
    adminAcc.amount = 12345.67;

    int IsLogged = 15;
    int loginID = 0; // ID assighned to every account. 0 is False
    int menuAction;
    printf("Welcome to TEST bank interface.\n"); // Work on bank name
    while (IsLogged == 0)
    {
        printf("Please login into your account.\n");
       // IsLogged = Login(); // Login function. Depending on success of login, returns 0 or 1 TODO
    }
    while (IsLogged != 0)
    {
        printf("Which action do you want to do (Enter the number o operation)?\n 1. Perform transactions\n 2. Edit account\n 3. View account info\n 4. Delete account\n 5. Logout and Exit\n");
        scanf("%d", &menuAction);
        switch (menuAction)
        {
        case 1:
            printf("You selected Perform transaction.\n");
            //PerfTransaction(); // Transaction function. TODO
            break;
        case 2:
            printf("You selected Edit account.\n");
            //EditInfo(); // Edit account function. TODO
            break;
        case 3:
            printf("You selected View account info.\n2");
            // ViewInfo(); // View Info function. Make it pass loginID and use it.
            break;
        case 4:
            printf("You selected Delete account.\n");
            printf("WARNING!\n This is irreversible action!\n Do you wish to contionue(1 = Yes/2 = No)? \n");
            int deleteConf = 2;
            scanf("%d", &deleteConf);
            if (deleteConf == 1)
            {
                //DeleteAccount(); // Delete account function. TODO
            }
            break;
        case 5:
            printf("You selected Logout and Exit.\n");
            printf("Logout(1 = Yes/2 = No)? ");
            int exitConf = 2;
            scanf("%d", &exitConf);
            if (exitConf == 1){
                printf("Logging out...\n");
                printf("Exiting...");
                return 0;
            }
            break;
        default:
            printf("Unknown command! Please try again!\n");
            break;
        }
    }
}