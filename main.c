#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account{
    char iBan[34]; // IBan number consist of 34 alphanumeric characters.
    char owner[20];
    char currency[4];
    double amount;
};

void EditInfo(struct Account Acc){              // How to edit values inside structs in methods?
    Acc.amount = 100;
}

void ViewInfo(struct Account Acc){              // DONE
    printf("Your account information:\n");
    printf("Your IBan: %s\n", Acc.iBan);
    printf("This account is registered on: %s\n", Acc.owner);
    printf("This account currently has: %.2f %s\n", Acc.amount, Acc.currency);
}

int main(){
    char editCommand[8];
    struct Account adminAcc;
    strcpy(adminAcc.iBan, "AAAADDDD11111111111111111111111111");
    strcpy(adminAcc.owner, "Alex Dascalu");
    strcpy(adminAcc.currency, "RON");
    adminAcc.amount = 12345.67;
    // ViewInfo(adminAcc);
    printf("What do you want to edit?\n");
    scanf("%s", editCommand);
    printf("%.2f\n", adminAcc.amount);
    EditInfo(adminAcc);
    printf("%.2f", adminAcc.amount);
}