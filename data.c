#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main (int argc, char **argv) {


    usleep(1000000);

    fclose(fopen(argv[1], "w"));
    FILE* exit = fopen(argv[1], "a");

   int i, n;
   time_t t;
   
   n = 5;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));
   int size = rand() % 10000;
   fprintf(exit, "%d ", size);
   fprintf(exit, "%d ", rand() % 10000);
   fprintf(exit, "%d\n", rand() % 10000);

   /* Print 5 random numbers from 0 to 50 */
   for( i = 0 ; i <  size; i++ ) {
    fprintf(exit, "%d %d", rand() % 10000, rand() % 10000);
    if (i != (size-1)) {
        fprintf(exit, "\n");
    }
   }
   fclose(exit);
   return(0);
}