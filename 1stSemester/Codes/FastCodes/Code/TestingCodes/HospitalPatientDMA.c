#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct patient
{
	int id;
	char name[30];
	char disease[30];
	int age;
	int status;
};

void addPatient(struct patient*** array, int beds, int *wards);

int main()
{
	int wards, beds;
	printf("\nEnter number of initial wards: ");
	scanf("%d", &wards); // example: 2

	struct patient** arr = (struct patient**)malloc(sizeof(struct patient*)*wards);
	if (arr == NULL)
	{
		printf("\nMalloc failed.\n");
		exit(1);
	}
	printf("\nEnter number of beds per ward: ");
	scanf("\n%d", &beds);

	for (int i = 0; i < wards; ++i)
	{
		arr[i] = (struct patient*)malloc(sizeof(struct patient)*beds);
		if (arr[i]==NULL)
		{
			printf("\nMalloc Failed.\n");
			exit(1);
		}
		for (int j = 0; j < beds; ++j)
		{
			arr[i][j].status=0;
		}
	}

	while(1)
	{
		int choice;
		printf("\n1.Add patient.\n2. Dispatch Patient.\n3. Show all Patients.\n4. Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{

			case 1:
			{
				addPatient(&arr, beds, &wards);
				break;
			}

			case 2:
			{

				break;
			}

			case 3:
			{
				
				break;
			}

			case 4:
			{
				exit(1);
			}

		default:
			{
				printf("\nInvalid Choice.\n");
				break;
			}
		}
}	



return 0;
}


void addPatient(struct patient*** array, int beds, int *wards)
{
	struct patient** temp= NULL;

	for (int i = 0; i < (*wards); ++i)
	{
		for (int j = 0; j < beds; ++j)
		{
			if ((*array)[i][j].status==0)
			{
				printf("\nEnter Patient ID: ");
				scanf("%d", &(*array)[i][j].id);
				printf("\nEnter Patient Name: ");
				scanf("%s", (*array)[i][j].name);
				printf("\nEnter Patient Disease Name: ");
				scanf("%s", (*array)[i][j].disease);
				printf("\nEnter Patient Age: ");
				scanf("%d", &(*array)[i][j].age);
				(*array)[i][j].status = 1;
				return;
			}
		}
		if (i==(*wards)-1)
		{
			temp = (struct patient**)realloc((*array), sizeof(struct patient*)*((*wards)+1));
			if (temp == NULL)
			{
				printf("\nRealloc Failed.\n");
				exit(1);
			}
			(*array) = temp;
			temp=NULL;
			(*array)[(*wards)] = (struct patient*)malloc(sizeof(struct patient)*beds);
			if ((*array)[(*wards)]==NULL)
			{
				printf("\nMalloc Failed.\n");
				exit(1);
			}
			for (int k = 0; k < beds; ++k)
			{
				(*array)[(*wards)][k].status=0;
			}
			++(*wards);
			printf("\nNew Ward created.\n");
		}
	}
}