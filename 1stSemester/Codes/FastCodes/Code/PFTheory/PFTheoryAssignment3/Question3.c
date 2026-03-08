#include <stdio.h>
#include <string.h>
//The structure needed
struct employeeData
{
	int id;
	char name[50];
	char designation[50];
	int salary;
};
//function declarations
void displayEmployees(struct employeeData employees[], int n);
int findHighestSalary(struct employeeData employees[], int n);
void searchEmployee(struct employeeData employees[], int n, int searchid, char searchname[50], int mode);

int main()
{
	int n, choice;
	printf("Enter the number of employees to add: ");
	scanf("%d", &n);
	struct employeeData employees[n];
	//Taking input of all employees below.
	for (int i = 0; i < n; ++i)
	{
		printf("\nEnter Employee#%d ID: ", i+1);
		scanf("%d", &employees[i].id);
		printf("\nEnter Employee#%d Name: ",i+1);
		getchar();
		fgets(employees[i].name, sizeof(employees[i].name), stdin);
		employees[i].name[strcspn(employees[i].name, "\n")]='\0';
		printf("\nEnter Employee#%d Designation: ",i+1);
		fgets(employees[i].designation, sizeof(employees[i].designation), stdin);
		employees[i].designation[strcspn(employees[i].designation, "\n")]='\0';
		printf("\nEnter Employee#%d salary: ",i+1);
		scanf("%d", &employees[i].salary);
		getchar();
	}
	do
	{
		//This is the start of the menu driven program.
		printf("\n\n1. Display all employees.\n2. Find highest salary.\n3. Search employee by ID or Name.\n4. Exit program.\nEnter your choice: ");
		scanf("%d", &choice);
		printf("\n");
		switch (choice)
		{

		case 1:
			{
				printf("Employee#\tEmployee ID\tName\t\tDesignation\t\tSalary");
				displayEmployees(employees, n);
				break;
			}

		case 2:
			{
				int sal = findHighestSalary(employees, n);
				printf("\nThe Employee with Highest salary is:");
				printf("\nEmployee#%d ID:\t\t%d", sal+1, employees[sal].id);
				printf("\nEnter Employee#%d Name:\t\t%s",sal+1, employees[sal].name);
				printf("\nEnter Employee#%d Designation:\t\t%s", sal+1, employees[sal].designation);
				printf("\nEnter Employee#%d salary:\t\t%d", sal+1, employees[sal].salary);
				break;
			}

		case 3:
			{
				int choice2;
				do
				{//Here we are searching by either ID or Name, and we need to use a single function.
					//so, we will use a mode system to decide if we are searching by ID or Name.
					int mode, searchid=0;
					char searchname[50]={0};
					printf("\n1. Search by ID.\n2. Search by Name\n3. Return to main menu.\nEnter your choice: ");
					scanf("%d", &choice2);
					if (choice2==1)
					{
						printf("\nEnter exact Employee ID: ");
						scanf("%d", &searchid);
						mode=1;//here mode 1 = searching by ID. Name is also passed along as a dummy value, so we can use the same function.
						searchEmployee(employees, n, searchid, searchname, mode);
					}
					else if (choice2==2)
					{
						printf("\nEnter exact Employee Name: ");
						getchar();
						fgets(searchname, sizeof(searchname), stdin);
						searchname[strcspn(searchname, "\n")]='\0';
						mode=2;//here mode 2 = searching by Name. ID is also passed along as a dummy value, so we can use the same function.
						searchEmployee(employees, n, searchid, searchname, mode);
					}
					else if (choice!=3)
					{
						printf("\nInvalid choice.\n");
					}
				} while(choice2!=3);
				break;
			}
		case 4:
			break;
		default:
			{
				printf("\nInvalid Input.\n");
				break;
			}
		}

	} while (choice!=4);

	printf("\n");
	return 0;
}

//This function is used to display all employees, for Case 1.
//It could be done by using Loops but i used recursion for extra practice.
void displayEmployees(struct employeeData employees[], int n)
{
	if (n==0)
		return;
	displayEmployees(employees, n-1);
	printf("\n%d\t\t%d\t\t%s\t\t%s\t\t\t%d",n,employees[n-1].id,employees[n-1].name,employees[n-1].designation,employees[n-1].salary);
}
//This funciton is used to find the highest salary among the employees(index of that employee), for Case 2.
//Again, this could be done by loops but i used recursion.
int findHighestSalary(struct employeeData employees[], int n)
{
	if (n==1)//Base case
	{
		return 0;
	}
	int highestindex = findHighestSalary(employees, n-1);//stores the highest index found
	if (employees[n-1].salary>employees[highestindex].salary)//If the stored highest index is less than the current index.
		//we are using n-1 instead of n because n is the count/number of employees, but we are dealing with indexes which start from 0, so n-1 = index.
		//if new index is higher than old highest, return the new highest.
	{
		return n-1;
	}
	else //if previous index is higher, return it.
	{
		return highestindex;
	}
}//This function is used for searching employee by ID or name, for Case 3.
void searchEmployee(struct employeeData employees[], int n, int searchid, char searchname[50], int mode)
{
	if (mode==1) //Mode 1 = seraching by ID.
	{
		for (int i = 0; i < n; ++i)
		{
			if (employees[i].id==searchid)
			{
				printf("\nEmployee#%d ID:\t\t%d", i+1, employees[i].id);
				printf("\nEnter Employee#%d Name:\t\t%s",i+1, employees[i].name);
				printf("\nEnter Employee#%d Designation:\t\t%s", i+1, employees[i].designation);
				printf("\nEnter Employee#%d salary:\t\t%d", i+1, employees[i].salary);
				return;
			}
		}
	}
	else
	{
		for (int i = 0; i < n; ++i) //If not Mode 1(searching by ID), then it must be mode 2 (searching by name).
		{
			if (strcmp(employees[i].name, searchname)==0)
			{
				printf("\nEmployee#%d ID:\t\t%d", i, employees[i].id);
				printf("\nEnter Employee#%d Name:\t\t%s",i, employees[i].name);
				printf("\nEnter Employee#%d Designation:\t\t%s", i, employees[i].designation);
				printf("\nEnter Employee#%d salary:\t\t%d", i, employees[i].salary);
				return;
			}
		}
	}
}
/*
If the company later wants to give a 10% salary bonus to employees whose salary is below a certain
threshold (say, 50,000), Explain how you could modify your existing program using a function with
structure arrays passed by reference to update salaries directly.

To do this, I would create a new function for this, void updateSalary(struct employeeData employees[], int n).
use a if condition inside a loop to go through each employee whose salary is lower than, say 50000.
then if a employee's salary is lower than 50000, i will use employee[i].salary += (employee[i].salary)*0.10
Here we are not using pointers because, the array by default returns a address and works like a pointer, unlike a normal variable.

This will update the salaries directly without having to return anything.
 */