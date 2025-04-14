// Same prime-detection strategy, but without any structured
// looping constructs.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Report a list of prime values.
 */
int main( void )
{
  // Get the range of values we're supposed to test.
  unsigned int low, high;
  if ( scanf( "%d%d", &low, &high ) != 2 ) {
    printf( "Invalid input\n" );
    exit( EXIT_FAILURE );
  }
  
  // Write your own, ugly solution, using goto instead of structured looping.
  unsigned int current = low;
  unsigned int factor = 2;
  topOfCurrentLoop:
  if(current > high){
    goto endAll;
  }
  factor = 2;

  topOfPrimeLoop:

  if(factor * factor > current){
    goto endOfPrime;
  }

  if(current % factor == 0){
    current++;
    goto topOfCurrentLoop;
  }

  factor++;
  goto topOfPrimeLoop;


  endOfPrime:
  printf("%u\n", current);
  current++;
  goto topOfCurrentLoop;
  
  endAll:
  return EXIT_SUCCESS;
}
