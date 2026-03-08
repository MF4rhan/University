#include <stdio.h>
int main()
{
	//int rows, columns, num=1, odd=0,even=0;
	//printf("How many rows do you want?.\n");
	//scanf("%d", &rows);
	/*	printf("How many columns do you want?.\n");
	scanf("%d", &columns);
	*/
for(int i=1; i<=5; i++)	//This controls Rows
	{
		for(int j=1; j<=5; j++)	//This controls Columns
		{
			if (j>=5-i)
			printf(" *");
			else
			printf(" ");
		}
		printf("\n");
	}
	//printf("\nThe number of even and odd numbers are %d and %d", odd, even);
return 0;
}
