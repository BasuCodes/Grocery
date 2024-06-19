#include "GroceryHeader.h"

void userRegister()
{
    printf("Enter Name\n");
    scanf("%s",users[numberofUsers].userName);
    printf("Enter Phone Number\n");
    scanf("%ld",&users[numberofUsers].phoneNumber);
    printf("Enter Address\n");
    scanf("%s",users[numberofUsers].Address);
    printf("Enter Gmail ID\n");
    scanf("%s",users[numberofUsers].gmail);
    if(numberofUsers>0)
    {
        for(int userIndex=0;userIndex<numberofUsers;userIndex++)
        {
            if(strcmp(users[numberofUsers].gmail,users[userIndex].gmail)==0)
            {
                printf("This user Email Already Register\n");
                return;
            }
            else{
                printf("Enter Password\n");
                scanf("%s",users[numberofUsers].password);
                numberofUsers++;
                fileWrite();
                return;
            }
        }
    }
    else{
        printf("Enter Password\n");
        scanf("%s",users[numberofUsers].password);
        numberofUsers++;
        return;
    }
}

void userLogin()
{
    char gmail[20],password[10];
    if(numberofUsers>0)
    {
        printf("Enter Email ID\n");
        scanf("%s",gmail);
        for(int userIndex=0;userIndex<numberofUsers;userIndex++)
        {
            if(strcmp(gmail,users[userIndex].gmail)==0)
            {
                printf("Enter Password\n");
                scanf("%s",password);
                if(strcmp(password,users[userIndex].password)==0)
                {
                    printf("Login Successfully\n");
                    return;
                }
                else{
                    printf("Password Incorrect\n");
                    return;
                }
            }
        }
        printf("The Email Id not Register please Register\n");
        userRegister();
        printf("Login Successfully\n");
    }
    else{
        printf("No Record Found\n");
    }
}
void fileWrite()
{
    gFile=fopen("GroceryRegister.txt","w");
    if(gFile == NULL)
    {
        printf("Error In File Opening\n");
    }
    else{
        printf("Register Successfully\n");
    }
    for(int userIndex=0;userIndex<numberofUsers;userIndex++)
    {
        fprintf(gFile,"%s\t%ld\t%s\t%s\t%s\n",users[userIndex].userName,
                users[userIndex].phoneNumber,users[userIndex].Address,
                users[userIndex].gmail,users[userIndex].password);
    }
    fclose(gFile);
}

void fileRead()
{
    gFile=fopen("GroceryRegister.txt","a+");
    if(gFile == NULL)
    {
        printf("Error In File Opening\n");
    }
    else{
        printf("File Open Successfully\n");
    }
    if(users==NULL)
    {
        users=(struct User*)malloc(sizeof(struct User));

    }
    while(fscanf(gFile,"%s %ld %s %s %s",users[numberofUsers].userName,
                  &users[numberofUsers].phoneNumber,users[numberofUsers].Address,
                  users[numberofUsers].gmail,users[numberofUsers].password)!=EOF)
    {
        numberofUsers++;
        users=(struct User*)realloc(users,(numberofUsers+1)*(sizeof(struct User)));
    }
    fclose(gFile);
}
