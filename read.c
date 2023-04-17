#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
//0.000028 seconds for the runtime
//No major challenges came up when coding this
int main()
{
    FILE* read;
    char c;
    clock_t t;
    t = clock();  
    //uses read() to read the txt file
    read = fopen("LoremIpsum.txt", "r");
    fclose(read);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f seconds\n", time_taken);    
    return 0;
}