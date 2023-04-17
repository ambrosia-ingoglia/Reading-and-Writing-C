#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Biggest challenge was making sure no seg fault errors occured
int main() {
        FILE * fp;
        char choice[30] = " ";
		//creates a file called 'concurentoutput.txt'
		fp = fopen("concurentoutput.txt", "w"); 
		//repeats until the user enters '-x'
		while(strcmp(choice, "-x") != 0)
		{
			//asks the user to write some text
			printf("Enter some text. Type -x to exit\n");
			fscanf(stdin, "%s", choice);
			if (strcmp(choice, "-x") == 0)
			{
				exit(1);
			}
			//appends txt file with the line the user entered
			for (int i = 0; i<strlen(choice); i++) {
            fputc(choice[i], fp);
        }
		fputc('\n', fp);
		}
        fclose(fp);
        return 0;
    }