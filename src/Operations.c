#include <stdio.h>
#include <string.h>
#include "Operations.h"

void PerfTransaction();
void EditInfo();
void ViewInfo(char const *accountName)
{
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
    fclose(csv_file);
}
void DeleteAccount();