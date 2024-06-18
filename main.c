#include "GroceryHeader.h"
#include "GroceryFun.cpp"

int main(){
    fileRead();
    int choice=0;
    printf("WelCome To Grocery Store\n");    
    while(choice!=3)
    {
        printf("Enter Your choice\n1.Register\n2.Login\n3.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            userRegister();
            fileWrite();
            break;
        case 2:
            userLogin();
            break;
        case 3:
            printf("Logout\n");
            free(users);
            break;
        default:
            printf("Enter Valid Choice\n");
            break;
        }
    }
    return 0;
}
