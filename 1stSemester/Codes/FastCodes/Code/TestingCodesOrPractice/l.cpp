#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
	bool guessFlag = false; 
	char secret[6]="apple";
	char guess[6][6];
	int guesscount=0;
	char guessWord[6];
	//	
	//  apple
	//  arrow
	int eff = 0;
	while ((guessFlag == false) && (guesscount < 6))  {
		
	
	printf("\nGuess the five-letter word: ");
	scanf(" %s", &guessWord);
	eff = 0;
	for (int i = 0; i < 5; i++) {
		if (guessWord[i] == secret[i]) {
			guess[guesscount][i]='#';
			
			eff += 1;
			
		} else if(strchr(secret, guessWord[i]) != NULL) {
			guess[guesscount][i]='+';
		}
		else
		guess[guesscount][i]='-';	
	}
	
	for (int i=0; i <= guesscount; i++)
	{
		for (int j=0; j<5; j++)
		{
			printf("%c  ", guess[i][j]);
		}
		printf("\n");
	}
	if (eff == 5) {
				printf("\nYou guessed the word!\n");
				guessFlag = true;
				break;
			}
	
	
	
	guesscount += 1;	
	}
return 0;
}