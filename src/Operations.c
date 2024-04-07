#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Operations.h"

#define MAX_LINE_CHARACHTERS 200

void PerfTransaction(char const *accountName, char const *accountName2)
{
    /*
        This function takes owner accountName and recipient accoutName. It reads details lines from both files and stores amount
        they have and IBan. After that it prompts user to choose amount to transfer, checking if it won't get owner into negative.
        Then using original details lines, prints it into re-written files, skipping changed values like amount and inserting new amount.
    */
    char fileName[20];
    strcpy(fileName, accountName);
    strcat(fileName, ".csv");
    char fileName2[20];
    strcpy(fileName2, accountName2);
    char lineOriginal1[200];
    char lineOriginal2[200];
    char line1[200];
    char line2[200];
    char *token;
    char IBanSender[40];
    char IBanRecipient[40];
    unsigned int senderAmount;
    unsigned int recipientAmount;

    FILE *csv_sender = fopen(fileName, "r");
    FILE *csv_recipient = fopen(fileName2, "r");
    fgets(lineOriginal1, MAX_LINE_CHARACHTERS, csv_sender);
    fgets(lineOriginal2, MAX_LINE_CHARACHTERS, csv_recipient);
    printf("DEBUG %s\n", lineOriginal1);
    printf("DEBUG %s\n", lineOriginal2);
    strcpy(line1, lineOriginal1);
    strcpy(line2, lineOriginal2);
    token = strtok(line1, ",");
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");
    strcpy(IBanSender, token);
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");
    senderAmount = atoi(token);
    token = strtok(line2, ",");
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");
    strcpy(IBanRecipient, token);
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");
    recipientAmount = atoi(token);
    fclose(csv_sender);
    fclose(csv_recipient);

    if (strcmp(IBanSender, IBanRecipient) == 0) // If Ibans are identical
    {
        printf("Identical IBAN!\nCanceling transfer...\n\n");
        return;
    }

    unsigned int transferAmount;
    printf("What amount do you want to transfer?\n");
    while (1)
    {
        scanf("%d", &transferAmount);
        if (senderAmount > transferAmount)
        {
            break;
        }
        printf("ERROR\nYou do not have enough funds to transfer!\nChange amount to transfer:");
    }
    char senderAm[10];
    char recipientAm[10];
    sprintf(senderAm, "%d", senderAmount -= transferAmount);
    sprintf(recipientAm, "%d", recipientAmount += transferAmount);

    csv_sender = fopen(fileName, "w");
    csv_recipient = fopen(fileName2, "w");
    strcpy(line1, lineOriginal1);
    strcpy(line2, lineOriginal2);
    token = strtok(line1, ",");
    for (int i = 0; i < 4; i++)
    {
        char temp[50];
        strcpy(temp, token);
        fprintf(csv_sender, "%s,", temp);
        token = strtok(NULL, ",");
    }
    token = strtok(NULL, ",");
    fprintf(csv_sender, "%s,", senderAm);
    token = strtok(line2, ",");
    for (int i = 0; i < 4; i++)
    {
        char temp[50];
        strcpy(temp, token);
        fprintf(csv_recipient, "%s,", temp);
        token = strtok(NULL, ",");
    }
    token = strtok(NULL, ",");
    fprintf(csv_recipient, "%s,", recipientAm);

    fclose(csv_sender);
    fclose(csv_recipient);
    printf("Transfer successful!\n\n");
}
void EditInfo(const char *accountName)
{
    /*
        This function is taking accountName as a parameter. It prompts user to select which value to edit, and saves it in "value".
        After that it takes whole details line from .csv with account and tokenizes it. It re-writes the file printing each value from "token"
        until value to be changed is next to be printed. It ends the loop, skips that token and prints instead value from "value".
        Prints the remaining tokens and closes file.
    */
    char fileName[20];
    char line[200];
    char *token;
    int tokenColumn = 0;
    int selector;
    char value[40];

    strcpy(fileName, accountName);
    strcat(fileName, ".csv");
    FILE *csv_file = fopen(fileName, "r");
    fgets(line, MAX_LINE_CHARACHTERS, csv_file);
    token = strtok(line, ",");
    fclose(csv_file);

    printf("Which value do you want to update? (IBAN = 1, Currency = 2, Balance = 3)\n");
    scanf("%d", &selector);

    switch (selector)
    {
    case 1:
        tokenColumn = 2;
        printf("Please enter your new IBAN: ");
        while (1)
        {
            scanf("%s", value);
            if (strlen(value) >= 15 && strlen(value) <= 34)
            {
                break;
            }
            printf("Invalid IBAN lenght! (15-34 characters)\n");
        }
        break;
    case 2:
        tokenColumn = 3;
        printf("Please enter your new Currency: ");
        while (1)
        {
            scanf("%s", value);
            for (int i = 0; value[i] != '\0'; i++)
            {
                value[i] = toupper(value[i]);
            }
            if (strcmp(value, "RON") == 0 || strcmp(value, "USD") == 0 || strcmp(value, "EUR") == 0)
            {
                break;
            }
            printf("Unsupported currency! (RON, USD, EUR)\n");
        }
        break;
    case 3:
        tokenColumn = 4;
        printf("Please enter your new Balance: ");
        scanf("%s", value);
        break;
    }
    FILE *csv_file2 = fopen(fileName, "w");
    for (int i = 0; i < tokenColumn; i++)
    {
        char temp[50];
        strcpy(temp, token);
        token = strtok(NULL, ",");
        fprintf(csv_file2, "%s,", temp);
    }
    token = strtok(NULL, ",");
    fprintf(csv_file2, "%s,", value);
    while (token != NULL)
    {
        char temp[50];
        strcpy(temp, token);
        token = strtok(NULL, ",");
        fprintf(csv_file2, "%s,", temp);
    }
    fclose(csv_file);
    free(token);
    free(csv_file);
    free(csv_file2);
    printf("Edit successful!\n");
}
void ViewInfo(char const *accountName)
{
    /*
    ViewInfo takes as a parameter accountName and concatenates ".csv" to reach existing file.
    Function uses strtok to save and later iterate over values in .csv.
    */
    char reader[40];
    char line[100];
    char fileName[20];

    strcpy(fileName, accountName);
    strcat(fileName, ".csv");

    FILE *csv_file = fopen(fileName, "r");
    fgets(line, MAX_LINE_CHARACHTERS, csv_file);
    char *token = strtok(line, ",");
    strcpy(reader, token);
    printf("Your name is: %s\n", reader);
    token = strtok(NULL, ",");
    strcpy(reader, token);
    printf("Your surname is: %s\n", reader);
    token = strtok(NULL, ",");
    strcpy(reader, token);
    printf("Your IBan is: %s\n", reader);
    token = strtok(NULL, ",");
    strcpy(reader, token);
    printf("Your currency is: %s\n", reader);
    token = strtok(NULL, ",");
    strcpy(reader, token);
    printf("Your amount is: %s\n", reader);
    fclose(csv_file);
    free(token);
    free(csv_file);
}
void DeleteAccount(char const *accountName)
{
    /*
    DeleteAccount takes accountName as a parameter and concatenates ".csv" to reach existing file.
    It simply looks for the file and using remove(), deletes it.
    */
    char fileName[20];
    strcpy(fileName, accountName);
    strcat(fileName, ".csv");
    remove(fileName);
    printf("Account deletion is successful.\nLogging out...\n");
}
