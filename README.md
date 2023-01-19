
**************** POSIX SHARED MEMORY-SORTING PROBLEM*********************
                                 === Authors ===

                                  Fahmida Afrin

                               === Introduction ===

This folder contains the following files:
1. p1.c : irst process will create a shared memory ofsize 2048. It will generate 10 random numbers ranging from 1-1000 
and write those numbers to the shared memory.
2. p2.c : Second process will read numbers from the shared memory sort them in an ascending order and print them.
3. p3.c : Third process will read numbers from the shared memory sort them in a descending order, print them and remove the shared memory.
4. Makefile: This is a makefile to compile the three programs.
5. all : This is a program which is a output of Makefile. 

                            === How to run the program?===

There are two way:
1. Run the Makefile using the following command:	
$ make all
$ ./all

or,

2. Run the following command in command prompt:

$ gcc -o all p1.c p2.c p3.c -lrt

