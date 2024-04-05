#include <stdio.h>
#include <string.h>
#include "Operations.h"

void PerfTransaction();
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
    fgets(line, sizeof(line), csv_file);
    token = strtok(line, ",");
    fclose(csv_file);

    printf("Which value do you want to update? (IBan = 1, Currency = 2, Amount = 3)\n");
    scanf("%d", &selector);

    switch (selector)
    {
    case 1:
        tokenColumn = 2;
        printf("Please enter your new IBan: ");
        scanf("%s", value);
        break;
    case 2:
        tokenColumn = 3;
        printf("Please enter your new Currency: ");
        scanf("%s", value);
        break;
    case 3:
        tokenColumn = 4;
        printf("Please enter your new Amount: ");
        scanf("%s", value);
        break;
    }
    FILE *csv_file2 = fopen(fileName, "w");
    for(int i = 0; i < tokenColumn; i++){
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
    fgets(line, sizeof(line), csv_file);
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
    free(token);
    fclose(csv_file);
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
