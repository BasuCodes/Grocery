#ifndef GROCERYHEADER_H
#define GROCERYHEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void userRegister();
void userLogin();

void fileWrite();
void fileRead();

struct User{
    char userName[50],
        gmail[20],password[10],Address[100];
    long int phoneNumber;
};
struct User *users = NULL;
int numberofUsers=0;
FILE *gFile = NULL;

#endif // GROCERYHEADER_H
