#include <stdio.h>
int main()
{
	int array[3][3], array2[3][3], array3[3][3]={0};
	int sum=0, large, small, largestsum=0, smallestsum=0, rowl, rows;
	for(int i=0;i<3;i++)
	{
		for(int j=0; j<3;j++)
		{
			printf("Enter the value for %d row %d column for 1st matrix\n", i+1, j+1);
			scanf("%d", &array[i][j]);
			/*sum+=array[i][j];
			if(i==0 && j==0)
			{
			large=array[i][j];
			small=array[i][j];
			}
			else if (array[i][j]>large)
			large=array[i][j];
			else if (array[i][j]<small)
			{
			small=array[i][j];
			}
			*/
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0; j<3;j++)
		{
			printf("Enter the value for %d row %d column for 2nd matrix\n", i+1, j+1);
			scanf("%d", &array2[i][j]);
			/*sum+=array[i][j];
			if(i==0 && j==0)
			{
			large=array[i][j];
			small=array[i][j];
			}
			else if (array[i][j]>large)
			large=array[i][j];
			else if (array[i][j]<small)
			{
			small=array[i][j];
			}
			*/
		}
	}

	printf("\n");
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			array3[i][j]=array[i][j]+array2[i][j];
			printf("%d\t", array3[i][j]);
		}
		printf("\n\n");
	}
	//printf("The final sum of all elements are: %d\n", sum);
	//printf("The largest number is %d\n", large);
	//printf("The smallest number is %d\n", small);
return 0;
}
