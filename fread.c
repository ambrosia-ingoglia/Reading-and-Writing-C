#include <stdio.h>
#include <time.h>
//0.000180 seconds for the runtime
//No major challenges came up
int main () 
{
    clock_t t;
	t = clock();  
    int buffer;
    FILE * stream;
    stream = fopen("LoremIpsum.txt", "r");    
    //uses fread() to read the txt file
    fread(&buffer, sizeof(int), 1, stream);
    fclose(stream);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f seconds\n", time_taken);
    return 0;
}