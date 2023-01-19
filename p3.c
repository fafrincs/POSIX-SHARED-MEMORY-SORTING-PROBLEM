#include "pos.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int p3() {

  int fd = shm_open(NAME, O_RDWR , 0666);

  if (fd < 0) {
    perror("shm_open()");
    return EXIT_FAILURE;
  }

  int *a =
      (int *) mmap(0, SIZE, PROT_READ| PROT_WRITE , MAP_SHARED, fd, 0);

    int i,j,temp;
    int n = 10;
 
    printf("\nRandom numbers from shared memory:\n");
    for( i = 0 ; i < n ; i++ )
     {
      printf("%d\t", a[i]);
     }

    for (i = 0; i < (n - 1); ++i)
    {
        for (j = 0; j < n - 1 - i; ++j )
        {
            if (a[j] < a[j+1])
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j]=temp;
            }
        }

    }

printf("\nSorted numbers in descending order:\n ");

        for (i = 0; i < n; i++)
         {
            printf( "%d\t",a[i]);
          }
printf("\n");

  munmap(a, SIZE);

  close(fd);

  shm_unlink(NAME);
  printf("\nSuccessfully Removed the Shared Memory!!\n");
  return EXIT_SUCCESS;
}
