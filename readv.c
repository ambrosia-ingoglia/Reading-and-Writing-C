/*
 * This programs opens a file and reads a block to it every time.
 * It serves as the reader in the example of demonstrating  sharing a file
 * between multiple concurrent processes.
 * From the textbook: "System Programming" by jin-Jwei Chen
 */
//0.000015 seconds for the runtime
//No major challenges came up (code used from class)
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>  /* memset()  */
#include <sys/uio.h>
#include <time.h>

#define BUFSZ1 256
#define BUFSZ2 512
#define BUFSZ3 576

int main(int argc, char *argv[])
{
	clock_t t;
	t = clock();  
	char *fname;
	int fd;
	ssize_t bytes;
	struct iovec iov[3];
	char buf1[BUFSZ1+1], buf2[BUFSZ2+1], buf3[BUFSZ3+1];

	/* Expect to get the file form user */
	if (argc > 1)
	{
		fname = argv[1];
	}
	else
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0] );
		return -1;
	}
	/* open the input file for read only */
	fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "open() failed, errno=%d\n", errno);
		return -2;
	}
	/* empty the buffers */
	memset(buf1, 0, BUFSZ1);
	memset(buf2, 0, BUFSZ2);
	memset(buf3, 0, BUFSZ3);
	/* set up I/O vectors */
	iov[0].iov_base = buf1;
	iov[0].iov_len = BUFSZ1;
	iov[1].iov_base = buf2;
	iov[1].iov_len = BUFSZ2;
	iov[2].iov_base = buf3;
	iov[2].iov_len = BUFSZ3;
	/* perform vectored I/O */
	//uses readv() to read the txt file
	bytes = readv(fd, iov, 3);
	if(bytes == -1)
	{
		fprintf(stderr, "readv() failed, errno=%d\n", errno);
		close(fd);
		return (-3);
	}
	//fprintf(stdout, "%ld bytes were read\n", bytes);
	/* Null terminate the buffers so that we can print the strings */
	buf1[BUFSZ1] = '\0';
	buf2[BUFSZ2] = '\0';
	buf3[BUFSZ3] = '\0';
	/* print the data read on screen */
	//fprintf(stdout, "buf1:%s\n", buf1);
	//fprintf(stdout, "buf2:%s\n", buf2);
	//fprintf(stdout, "buf3:%s\n", buf3);
	/* close file */
	close(fd);
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f seconds\n", time_taken);
	return(0);
}
