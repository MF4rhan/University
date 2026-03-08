#include <stdio.h>
#include <string.h>
int main()
{
   char words[3][10];
    for (int i = 0; i < 3; i++)
    fgets(words[i], sizeof(words), stdin);
    printf("\n\n");
    for (int i = 0; i < 3; i++)  
        fputs(words[i], stdout);
return 0;
}   