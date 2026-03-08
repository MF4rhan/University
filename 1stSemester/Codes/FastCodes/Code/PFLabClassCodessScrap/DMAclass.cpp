#include <stdio.h>
#include <stdlib.h>
/*
malloc and calloc have 3 main issues/things to note:
1. you need to add a NULL check immediately after its initialization.
2. It will initialize all members as garbage values be default. (malloc only)
3. After completing its use, you need to use the free() adn then free the pointer.
	free(ptr);
	ptr = NULL;
	Use these two together, otherwise you may run into issues.
*/
int main()
{
	int *ptr = (int*)malloc(3*sizeof(int));
	ptr[0]=11;
	ptr[1]=22;
	ptr[2]=33;
	printf("Original 3 values: %d %d %d\n", ptr[0], ptr[1], ptr[2]);
	
	int *temp = (int*)realloc(ptr, 10* sizeof(int));
	if (temp == NULL)
	{
		printf("Cannot grow, keeping old array.\n");
	}
	else
	{
		ptr = temp;
		printf("Succsesfully grown to 10!\n");
	}
	for(int i=3; i<10; i++)
	ptr[i]=99;
	
	for(int j=0; j<10; j++)
	printf("%d ", ptr[j]);
	
return 0;
}
