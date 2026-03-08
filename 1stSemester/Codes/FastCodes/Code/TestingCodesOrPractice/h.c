#include <stdio.h>
#include <string.h>



int main(){
	
	char hangWord[] = "out of the town";
	int length = strlen(hangWord);
	char ourword[] = {"### ## ### ####"};
	
	char letter;
	int i = 0, tries = 8;
	int flag;
	
	while (i < tries) {
		
		do {
			printf("\nEnter a character: ");
			scanf(" %c", &letter);
			if (letter<'a' || letter > 'z')
				printf("\nInavlid number, enter again.");
		} while (letter<'a' || letter > 'z');
		
		
		for (int j = 0; j < length; j++) {
			
			if (letter == hangWord[j]) {
				ourword[j] = letter;
				
			} else if (letter != hangWord[j] && j == length-1){
				i++;
		 }
		}
		if (strchr(ourword, '#') == NULL) {
			printf("\nYou win");
			printf("%s", ourword);
			break;
			
		}
	
	
	
	
	
	
	
	
	
	
	
	
	}
	
return 0;
}