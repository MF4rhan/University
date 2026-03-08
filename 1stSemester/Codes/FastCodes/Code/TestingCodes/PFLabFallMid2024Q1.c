#include <stdio.h>
int main() {
    float employeesalary, contripercent, employermatchpercent, employeecontr=0, employercontr=0, totalcontr=0;
    printf("enter your salary.\n");
    scanf(" %f", &employeesalary);
    printf("enter your contribution percentage.\n");
    scanf(" %f", &contripercent);
    printf("enter your employer matching percentage.\n");
    scanf(" %f", &employermatchpercent);
    employeecontr=employeesalary*(contripercent/100);
    employercontr=employeecontr*(employermatchpercent/100);
    totalcontr=employeecontr+employercontr;
    if (totalcontr>0.15)
    {
        totalcontr=(employeesalary*0.15);
    }
    printf("Total %.2f (k) Contribution.", totalcontr);
return 0;
}