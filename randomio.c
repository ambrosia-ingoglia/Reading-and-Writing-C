#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
//Biggest challenge was overriding the '-' characters with my name
int main() {
    FILE * fp;
    char str[] = "-";
    //creates a file called 'randomambrosia.txt'.  
    fp = fopen("randomambrosia.txt", "w"); 
    //file contents are initially set to 256 '-' characters
    for (int i = 0; i<257; i++) {
        fputc(str[0], fp);
    }
    fclose(fp);
    int fl = open("randomambrosia.txt", O_RDWR); 
    char buf;
    read(fl,&buf, sizeof(buf));
    if (buf == '-'){
    char copy[] = "ambrosia";
    //sets the offset to 4 and writes my name to the file
    lseek(fl,4,SEEK_SET); 
    write(fl,&copy,8);
    }
    close(fl);    
    return 0;
}