#include <stdio.h>
#include <stdlib.h>
int main()
{
	int** matrix = (int **)calloc(3, sizeof(int*));
	if (matrix == NULL)
	{
		printf("\nmatrix Initialization Failed.\n");
		return 1;
	}
	for (int i = 0; i < 3; ++i)
	{
		matrix[i] = (int *)calloc(3, sizeof(int));
		if (matrix[i]==NULL)
		{
			printf("\nMatrix elemt Initialization Failed.\n");
			return 1;
		}
	}
	printf("\nEnter numbers:\n");
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			scanf("%d",&matrix[i][j]);
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%d  ", matrix[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 3; ++i)
	{
		free(matrix[i]);
	}
	free(matrix);
return 0;
}