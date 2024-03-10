#include "Login.h"
#include <stdio.h>

#define CSV_FILE "accounts.csv"
#define MAX_LENGTH 100

int Login(const char *name, const char *surname){
    FILE *file = fopen(CSV_FILE, "r");
    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token;
        char *delimiter = ",";
        char *temp;
        char *copy = strdup(line);

        token = strtok(copy, delimiter);
        if (token != NULL && strcmp(token, name) == 0) {
            token = strtok(NULL, delimiter);
            if (token != NULL && strcmp(token, surname) == 0) {
                free(copy);
                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);
    return 0;
}