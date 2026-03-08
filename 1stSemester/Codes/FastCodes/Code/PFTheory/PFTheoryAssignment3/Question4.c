#include <stdio.h>
#include <string.h>
struct bookdata
{
	int id;
	int popularity;
	int lastAccess;
};
void operations(struct bookdata books[], int capacity, int lines, int *currentaccess);
int main()
{
	int capacity, lines, currentaccess=0;
	printf("Enter the capacity of the shelf and number of input commands (separated by a space):\n");
	scanf("%d %d", &capacity, &lines);
	struct bookdata books[capacity];
	printf("\n\n\n");
	operations(books, capacity, lines, &currentaccess);
	printf("\n");
	return 0;
}

void operations(struct bookdata books[], int capacity, int lines, int *currentaccess)
{
	char command[10];
	int tempid, temppop, currentcap=0;
	printf("\nInput\t\tOutput\n");
	for (int i=0; i<lines; ++i)
	{
		//printf("\nEnter Command (ADD ID POPULARITY)(ACCESS ID):\n");
		scanf("%s",command);
		if (strcmp(command, "ADD")==0) //This block of code will run if the input command is "ADD"
		{
			int found=0;
			scanf("%d %d", &tempid, &temppop); //inputting ID and Popularity
			for (int j=0; j<currentcap; ++j)
			{
				if (tempid==books[j].id) //In this block, if the blood alreaday exists in the database, it will update it's score.
				{
					//printf("\nThis book alreadye exists in the database, Updated popularity score.\n");
					books[j].popularity=temppop;
					(*currentaccess)++;//updating the current access and the book's last accessed time.
					books[j].lastAccess = (*currentaccess);
					found=1;
					break;
				}	
			}
			if (currentcap == capacity && found==0) //In this block, if the shelf capacity is full, the least accessed book will be replaced.
				{
					int smallest, smallestindex;
					//printf("\nShelf capacity is full, the least accessed book has been replaced.\n");
					(*currentaccess)++; //updating current access
					for (int k=0; k<currentcap; k++) //here we are finding the least accessed book.
					{
						if (k==0) //This is used for the very first iteration, just to fill up the smallest and smallestindex variables with something.
						{
						smallest = books[k].lastAccess;
						smallestindex = k;
						}
						else if (books[k].lastAccess<smallest) //This is the comparision, if the book's last access count is lower, it will run.
						{
						smallest = books[k].lastAccess;
						smallestindex = k;
						} //by the end of this loop, we will have the least accessed book out of them all.
					}
					books[smallestindex].lastAccess = (*currentaccess); //updating the book's last access.
					books[smallestindex].id = tempid; //replacing the least accessed book's id and popularity with new book
					books[smallestindex].popularity = temppop;
					found=1;
				}
			else if (found==0) //In this block, if the book is not in the database and shelf is not full, it is simply added into the shelf.
			{
				(*currentaccess)++; //increasing current access count
				books[currentcap].id = tempid; //adding the new book's ID, popularity and starting its access count.
				books[currentcap].popularity = temppop;
				books[currentcap].lastAccess = (*currentaccess);
				currentcap++;
				//printf("\nBook successfully added to the shelf.\n");
			}
		}
		else if (strcmp(command, "ACCESS")==0) //This block of code will run if the input command is ACCESS
		{
			int found=0;
			scanf("%d", &tempid); //taking the book ID to find
			for (int i=0; i<currentcap; ++i)
			{
				if (books[i].id == tempid) //if matched, print out its popularity and update its last access
				{
					printf("\t\t%d\n", books[i].popularity);
					(*currentaccess)++; //increasing current access count
					books[i].lastAccess = (*currentaccess);
					found =1;
					break;
				}
			}
			if(found==0)
			{
				printf("\t\t-1\n"); //if not found, printing -1.
			}
		}
	}
}