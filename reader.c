#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//Biggest challenge was having reader.c and writer.c execute at the same time
int main()
{
    FILE* read;
    char c;
 
    read = fopen("concurentoutput.txt", "r");
    
    if (NULL == read) {
        printf("file can't be opened \n");
    }
    //reads the 'concurrentoutput.txt'
    do {
        c = fgetc(read);
        printf("%c", c);
    } while (c != EOF);
 
    fclose(read);
    return 0;
}