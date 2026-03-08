#include <stdio.h>
#include <stdlib.h>
int main()
{
    int code,d4,d5,d6,accesspart,enviropart;
    printf("Enter your 6 digit pin code.\n");
    scanf(" %d", &code);

    d4=(code/100)%10;
    d5=(code/10)%10;
    d6=code%10;

    accesspart=code/1000;
    enviropart=code%1000;

    if (accesspart==8)
    {
        printf("Access Denied.\n");
        exit(0);
    }
    else if (accesspart==84)
    {
        printf("Read Only Access given.\n");
    }
    else if (accesspart==255)
    {
        printf("Read and Write Access Given.\n");
    }
    else if (accesspart==385)
    {
        printf("Full Administrator Access Given.\n");
    }
    else
    {
        printf("Invalid Code.\n");
        exit(0);
    }
    d5%2==1?d5%7==0?printf("Access to System resources granted.\n")
        :printf("User access Granted.\n")
        :(printf("access Denied.\n"), exit(0));

    d6==1?printf("Hardware failure detected, Access Denied.\n")
        :printf("Welcome.\n");

    d4%2==0?printf("access restricted to normal working hours (9-5).\n")
        :printf("No restriction on Access time.\n");

return 0;
}