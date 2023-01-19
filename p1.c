#include "pos.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main() {

  int fd = shm_open(NAME, O_CREAT | O_RDWR, 0600);
  int i;
  if (fd < 0) {
    perror("shm_open()");
    return EXIT_FAILURE; }

  ftruncate(fd, SIZE);

  int *data =
  (int *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  
   printf("sender mapped address: %p\n", data);
   time_t t;

   srand((unsigned) time(&t));

    for( i = 0 ; i < 10 ; i++ )
     {
      data[i] = rand () % 10;
     }
   p2();
   p3();
  
  munmap(data, SIZE);

  close(fd);

  return EXIT_SUCCESS;
}
