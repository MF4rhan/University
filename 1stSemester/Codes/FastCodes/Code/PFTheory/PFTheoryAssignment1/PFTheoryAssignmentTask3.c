#include <stdio.h>
int main()
{
    int Age;
    char Eyesight, WrittenTest, DrivingTest, MedicalFitnessCertificate;
    printf("Enter your Age.\n");
    scanf("%d", &Age);
   if (Age>=18)
   {
    printf("Enter your Eyesight Test Results, P for Pass, F for Fail.\n");
    scanf(" %c", &Eyesight);
    if (Eyesight == 'P')
    {
       printf("Enter your Written Test Results, P for Pass, F for Fail.\n");
       scanf(" %c", &WrittenTest);
       if (WrittenTest == 'P')
       {
        printf("Enter your Driving Test Results, P for Pass, F for Fail.\n");
       scanf(" %c", &DrivingTest);
       if (DrivingTest == 'P')
       {
        if (Age>60)
        {
            printf("Enter your Medical Fitness Certificate, Y for Yes, N for No.\n");
            scanf(" %c", &MedicalFitnessCertificate);
            if (MedicalFitnessCertificate == 'Y')
            {
                printf("You are eligible for a Driver's License.");
            }
            else
            {
                printf("You are ineligible for a Driver's License.");
            }
            
        }
        else
        {
            printf("You are eligible for a Driver's License.");
        }
        
       }
       else
       {
        printf("You are ineligible for a Driver's License.");
       }
       
       }
       else
       {
        printf("You are ineligible for a Driver's License.");
       }
       
    }
    else
    {
       printf("You are ineligible for a Driver's License.");
    }
    
   }
   else
   {
    printf("You are ineligible for a Driver's License.");
   }
   
return 0;
}