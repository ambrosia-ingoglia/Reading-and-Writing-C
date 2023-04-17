# Reading-and-Writing-C
C code for a program to read a file and write to a file

Concurrent reading and writing
    Modifys the writer program so it will:
        create a file called 'concurentoutput.txt'
        repeats until the user enters '-x' do the following:
            Asks the user to write input some text
            appends the 'concurrentoutput.txt' file with the line the user entered.
    The 'reader.c' program reads the 'concurrentoutput.txt'

Random I/O
    randomio.c creates a file called 'randomambrosiaingoglia.txt'. 
        The file contents are set 256 '-' characters.
        Sets the offset to 4 and writes my name to the file.

Asynchronous I/O
    Wrote a routine which prints each character of my name to 'stdout' over and over again until it has completed writing/creating a file called 'asynchronous_output.txt'.

Wrote three programs (10 pts each) to read a large file (15 MB), one uses read(), the second uses readv() and the third uses fread().  Compared their speeds in reading LoremIpsum.txt
